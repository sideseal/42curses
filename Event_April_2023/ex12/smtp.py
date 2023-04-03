import smtplib
import getpass
from email.mime.text import MIMEText
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders

SENDER_EMAIL = getpass.getpass(prompt="Enter your email(naver.com): ")
SENDER_PASSWORD = getpass.getpass(prompt="Enter your password: ")
RECEIVER_EMAIL_DEFAULT = "gychoi@student.42seoul.kr"
SMTP_SERVER = "smtp.naver.com"
SMTP_PORT = 587

RECEIVER_EMAIL = input("Enter the recipent email: ")
if not RECEIVER_EMAIL.strip():
	RECEIVER_EMAIL = RECEIVER_EMAIL_DEFAULT
	print("Test email will be sent to 'gychoi@student.42seoul.kr'.")
else:
	print("Test email will be sent to '{}'.".format(RECEIVER_EMAIL))
print("Sending...")

msg = MIMEMultipart()
msg['From'] = SENDER_EMAIL
msg['To'] = RECEIVER_EMAIL
msg['Subject'] = "SMTP EMAIL TEST"

body = "TEST MESSAGE"
msg.attach(MIMEText(body, 'plain'))

# attach image in to email.
imagename = "42.jpg"
try:
    attachment = open(imagename, "rb")
    p = MIMEImage(attachment.read())
    p.add_header('Content-ID', '<image1>')
    msg.attach(p)
except Exception as e:
	print(e)
	print("NO IMAGE ATTACHED")

# attach file in to email.
filename = "test.txt"
try:
	attachment = open(filename, "rb")
	p = MIMEBase('application', 'octet-stream')
	p.set_payload((attachment).read())
	encoders.encode_base64(p)
	p.add_header('Content-Disposition', "attachment; filename= %s" % filename)
	msg.attach(p)
except Exception as e:
	print(e)
	print("NO FILE ATTACHED")

server = smtplib.SMTP(SMTP_SERVER, SMTP_PORT)
server.starttls()
server.login(SENDER_EMAIL, SENDER_PASSWORD)

text = msg.as_string()
server.sendmail(SENDER_EMAIL, RECEIVER_EMAIL, text)

server.quit()
print("SEND TEST EMAIL SUCCESS")
