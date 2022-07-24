# 패스워드 정책

You have to implement a strong password policy. ... To set up a strong password policy, you have to comply with the following requirements:
* Your password has to expire every 30 days.
* The minimum number of days allowed before the modification of a password will be set to 2.
* The user has to receive a warning message 7 days before their password expires.
* Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters.
* The password must not include the name of the user
* The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.
* Of course, your root password has to comply with this policy.

!! After setting up your configuration files, you will have to change all the passwords of the accounts present on the virtual machine, including the root account.

여러분은 강력한 패스워드 정책을 만들어야 한다. ... 강력한 패스워드 정책을 만들기 위해서, 여러분은 다음의 요구 조건들을 준수해야 한다:
* 여러분의 패스워드는 30일마다 만료되어야 한다.
* (패스워드를 설정하고) 최소한 2일이 지나야 패스워드를 변경할 수 있다.
* 유저는 패스워드 만료되는 날의 7일 전에 경고 메세지를 받아야 한다.
* 비밀번호는 최소한 10자리 이상이여야 하며, 영어 대문자와 숫자가 반드시 포함되어야 한다. 그리고 패스워드는 3개 이상의 동일한 문자가 연속되어선 안된다.
* 패스워드가 유저의 이름을 포함해서는 안된다.
* 패스워드는 이전의 패스워드와 최소한 7글자가 달라야 한다(root는 예외로 이 조건을 따르지 않아도 된다).
* 당연히, root 또한 위의 조건들을 모두 따라야 한다.

!! 패스워드 환경 설정 파일을 변경한 후에, 여러분은 root를 포함하여 가상 머신에 있는 모든 계정의 패스워드를 변경해야 합니다.

* * *

패스워드 정책 변경을 하기 위해선, `/etc/login.defs` 파일을 수정해야 한다.

하지만 그 전에 먼저, 패스워드 설정 강화를 위한 pam 모듈인 `libpam-pwquality`를 설치해야 한다.

```sh
apt install -y libpam-pwquality
```

* PAM이란? PAM(Pluggable Authentication Module, 착탈형 인증 모듈)은 사용자를 인증하고, 그 사용자의 서비스에 대한 액세스를 제어하는 모듈화된 방법을 일컫는다. PAM은 관리자가 응용프로그램들의 사용자 인증 방법을 선택할 수 있도록 해준다. PAM은 시스템에 공통 인증체계와 필요한 공유 라이브러리의 묶음을 제공하여, 관리자와 응용프로그램 개발자 모두에게 유연성과 인증 제어 기능을 제공한다. 따라서 응용프로그램 개발자는 본인만의 인증 스키마를 만들지 않고 프로그램을 작성할 수 있게 된다.
	- 참고: [https://5log.tistory.com/183](https://5log.tistory.com/183)

패스워드 만료일과 최소 변경일 그리고 경고 메세지를 설정하기 위해, 160번째 줄로 이동해서, 아래와 같이 변수의 값을 변경한다.

```sh
# /etc/login.defs

PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```

다만 위 정책은 기존에 등록된 유저에게는 적용되지 않는다. 기존 유저에게도 위의 정책을 적용하기 위해선, 아래의 명령어를 입력해야 한다.

```sh
# PASS_MAX_DAYS
chage -M 30 <user>

# PASS_MIN_DAYS
chage -m 2 <uwer>

# PASS_WARN_AGE
chage -W 7 <user>
```

* chage: 사용자의 패스워드 만기 정보를 변경 및 설정하는 명령어([https://aury524.tistory.com/12](https://aury524.tistory.com/12))

`/etc/shadow`에서 패스워드 정책이 적용된 root와 유저를 확인할 수 있다. 

```sh
# /etc/shadow

root:blahblahblah:<패스워드 만료까지 남은 기간>:2:30:7:::
...
gychoi:looooooong:<패스워드 만료까지 남은 기간>:2:30:7:::
# 당연히... blah와 long은 무작위 문자이다...
```

이제 `/etc/pam.d/common-password`로 이동하여, 나머지 패스워드 설정을 마치자. 25번째 줄의 마지막(`retry=3`) 뒤에 다음의 설정들을 추가한다.
- minlen=10 : 패스워드의 최소 길이
- dcredit=-1 : 패스워드에 포함되어야 하는 숫자의 최소 개수. 일반적인 사용과 반대로 음수로 개수가 카운팅이 된다. 양수는 제한 없음을 의미.
- ucredit=-1 : 패스워드에 포함되어야 하는 영어 대문자의 최소 개수. 위와 카운트 방식이 동일하다.
- maxrepeat=3 : 패스워드에서 연속될 수 있는 문자의 최대 개수.
- reject_username : 패스워드에 유저 이름이 들어있는지 확인(거꾸로 들어있는지도 확인한다고...).
- difok=7 : 새로운 패스워드가 이전 패스워드와 달라야 하는 문자의 최소 개수.
- enforce_for_root : root에게도 비밀번호 정책을 동일하게 적용.

```sh
# /etc/pam.d/common-password
# line 25

password    requisite        pam_pwquality.so retry=3 minlen=1 dcredit=-1 ucredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

* 문제 요구 조건에서 root 계정은 새로운 비밀번호 7글자가 이전과 달라야 한다는 조건을 기억한다면... 다행히도 root 계정은 이전의 패스워드를 묻는 일이 없기에, `difok=7` 조건이 실행되지 않는다고 한다. ([https://man.archlinux.org/man/pam_pwquality.8#enforce_for_root](https://man.archlinux.org/man/pam_pwquality.8#enforce_for_root))

이제 마지막으로 root와 유저로 하여금 패스워드 변경을 하도록, `passwd -e <username>`을 실행한다. 해당 명령어는 유저의 <패스워드 만료까지 남은 기간>을 0으로 변경하여, 다음 로그인 시 비밀번호 변경이 요청된다.

```sh
# 재 접속시...
You are required to change your password immediately (administrator enforceed).
...
```

참고:  
[https://www.linuxtechi.com/enforce-password-policies-linux-ubuntu-centos/](https://www.linuxtechi.com/enforce-password-policies-linux-ubuntu-centos/)  
[https://www.cyberciti.biz/faq/linux-set-change-password-how-to/](https://www.cyberciti.biz/faq/linux-set-change-password-how-to/)

# sudo 및 유저 정책

You have to install and configure sudo following strict rules.
In addition to the root user, a user with your login as username has to be present. This user has to belong to the user42 and sudo groups.

i) During the defense, you will have to create a new user and assign it to a group.

...

To set up a strong configuration for your sudo group, you have to comply with the following requirements:
* Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.
* A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
* Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the `/var/log/sudo/` folder.
* The TTY mode has to be enabled for security reasons.
* For security reasons too, the paths that can be used by sudo must be restricted.
	- Example: `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`

여러분은 sudo를 설치하고 강력한 sudo 정책을 만들어야 한다.
root 유저와 더불어 여러분의 login 아이디를 이름으로 삼은 유저가 존재해야 한다. 해당 유저는 user42와 sudo 그룹에 속해야 한다.

i) 디펜스가 진행되는 동안, 여러분은 새로운 유저를 만들어 그룹에 포함시킬 수 있어야 한다.

...

강력한 sudo 그룹 정책을 설정하기 위해, 여러분은 다음의 요구 조건들을 준수해야 한다:
* sudo를 이용한 인증에 있어 비밀번호 오류에 의한 재시도는 3회로 제한된다.
* sudo를 이용함에 있어 비밀번호 오류가 발생하면, 여러분이 선택한 커스텀 메세지가 출력되어야 한다.
* sudo를 이용하는 행동의 입력과 출력은 모두 기록되어야 한다. 로그 파일은 `/var/log/sudo/` 폴더에 저장되어야 한다.
* 보안상의 이유로 TTY 모드를 활성화해야 한다.
* 동일하게 보안상의 이유로, sudo를 사용할 수 있는 경로는 제한되어야 한다.
	- 예시: `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`

* * *

## 그룹에 유저 추가하기

지금까지 root와 gychoi 유저를 만든 상태이다. user42 그룹을 만들고 user42와 sudo 그룹이 잘 만들어져있는지 확인한다.

```sh
# user42 그룹 만들기
addgroup user42

# 그룹 삭제는...
delgroup <group>

# user42 그룹 확인하기
grep 'user42' /etc/group

# output
user42:x:1001:

# sudo 그룹 확인하기
grep 'sudo' /etc/group

# output
sudo:x:27:
```

이제 gychoi 유저를 user42와 sudo 그룹에 추가하자.

```sh
# user42, sudo 그룹을 gychoi의 Secondary group에 이어서 추가한다.
adduser gychoi user42
adduser gychoi sudo

# gychoi가 속한 그룹 체크(gychoi 계정이라면 재로그인이 필요할 수 있다)
id gychoi

#output
id=1000(gychoi) gid=1000(gychoi) groups=1000(gychoi),24(cdrom),25(floppy),27(sudo),29(audio),30(dip),44(video),46(plugdev),108(netdev),1001(user42)

# 반대로 삭제할 떈...
deluser gychoi <group>
```

* Linux의 group 개념은, 어떤 파일이나 시스템 자원을 그룹에 따라 접근할 수 있는 권한을 다르게 하기 위해 주로 사용되는 듯 하다. 모든 파일들은 각각 한 명의 유저와 하나의 그롭에 소속된다. 유저는 반드시 1차 그룹(Primary group)에 속해야 하고, 최대 15개의 2차 그룹(Secondary groups)에 속할 수 있다.
	- 1차 그룹은 유저가 새로운 파일/디렉터리를 만들거나, 파일을 수정하거나, 명령어를 수행하는데 적용된다.
	- 2차 그룹은 유저가 1차 그룹 외에 속한 그룹들을 나열한다. 2차 그룹에 속한 유저들은 2차 그룹에 속한 파일들을 읽고 쓸 수 있다.
	- 참고: [https://askubuntu.com/questions/853399/can-we-have-a-user-without-a-primary-group](https://askubuntu.com/questions/853399/can-we-have-a-user-without-a-primary-group)
* 새로운 유저를 만들기 위해선 `adduser <username>` 명령어를 입력하자. 유저를 삭제할 땐 `deluser -f <username>`을 입력하자.
* 그룹의 리스트를 확인할 땐 `cat /etc/group`, 유저를 확인할 땐 `cat /etc/passwd`를 사용!

참고:  
[https://chanchan-father.tistory.com/206](https://chanchan-father.tistory.com/206)  
[https://kingname.tistory.com/155](https://kingname.tistory.com/155)

## sudo group 정책 변경

일반적으로 유저는 sudo 명령어를 실행할 수 없다. 유저가 sudo 명령어를 실행하기 위해선, 해당 유저를 sudo group에 추가해야 한다. 위에서 gychoi 유저를 user42와 sudo 그룹에 추가하였기 떄문에, 이제 gychoi 유저는 sudo 명령어를 사용할 수 있다.

그렇다면 이제 sudo group의 정책을 강력하게 만들어보자. sudo group의 정책을 변경하기 위해선 `/etc/sudoers` 파일의 내용을 수정해야 한다. 다만, sudoers 파일은 기본적으로 쓰기 명령이 없기 때문에, `visudo`라는 명령어로 파일 수정을 진행해야 한다.
	- 그런데 기본 에디터가 nano로 실행되기에, 조금 익숙하지 않을 수도 있다. `.bashrc`에 `export EDITOR=/usr/bin/vim`을 설정하여 vim 에디터로 실행되도록 하자. (마지막에 `source ~/.bashrc` 잊지 말기!)

sudoers에 설정되어있는 변수들을 살펴보자.
* env_reset : sudo 명령어가 새로운 환경에서 실행될 수 있도록 한다. `HOME, MAIL, SHELL, LOGNAME, USER` 환경 변수는 새로운 환경에 그대로 적용된다.
* mail_badpass : 유저가 틀린 비밀번호를 입력하여 sudo 명령어를 실행하지 못하는 경우, 유저의 `mailto` 경로로 메일을 보낸다.
* secure_path : 유저의 환경 변수 경로 대신, secure_path로 설정된 경로에 한정해서 sudo + 명령어를 실행한다.
	- secure_path에 대한 보다 자세한 이야기: [https://www.tuwlab.com/ece/24044](https://www.tuwlab.com/ece/24044)

우선, sudo 명령어 비밀번호 재입력 횟수는 기본적으로 3회로 제한되어 있다. 비밀번호 인증 횟수를 변경하기 위해선 `passwd_tries` 설정을 사용하면 된다. (기본으로 설정되어 있어서 파일에 따로 적지는 않았다.)

비밀번호 오류가 발생하는 경우, 커스텀 메세지가 출력되도록 하려면 `badpass_message` 설정을 사용하자. 재미있는건, `insults` 설정을 사용해도 커스텀 메세지가 출력된다. (그런데 커스텀 메세지의 상태가...?!)

```sh
Defaults	badpass_message="WRONG PASSWORD, PLEASE TRY AGAIN!"

# 혹은, 누군가 유저를 사랑하지 않는 사람이라면...

Defaults	insults
```

만약, sudo 로그인 실패로 권한을 얻지 못하였을 때에도 메세지를 출력하도록, 아래 설정을 추가로 해야할 것 같다.
```sh
authfail_message="AUTHENTICATION FAILED"
```

sudo 입출력의 로그 파일을 만들기 위해선 다음과 같이 설정한다.

```sh
# 우선, /var/log에 sudo 디렉터리를 생성하자.
mkdir /var/log/sudo

# 그리고 다시 visudo로 돌아와...

# sudo의 입출력이 /var/log/sudo에 적히도록 설정한다.
Defaults	log_input, log_output, iolog_dir="/var/log/sudo/"
Defaults	log_host, logfile="/var/log/sudo/"
```
* `iolog_dir="/var/log/sudo/%{user}"`로 하면 유저의 이름 안에 log 정보가 담기는데, 우선 조금 애매해서 설정은 위처럼 진행했다.

TTY 모드도 활성화하자.

```sh
Defaults	requiretty
```
* TTY(Teletypewriter)는 간단하게 콘솔이나 터미널을 의미한다고 생각하면 된다. 그렇다면 보안을 위해 TTY를 활성화해야 하는 이유는 무엇일까?
	- sudo 명령어가 TTY 상태에서 진행되어야 한다는 의미는, 현재 터미널 바깥에서 sudo 명령어가 사용되는 경우를 방지할 수 있다. 가령, sudo 권한이 없는 유저가 cronjob에 sudo 명령어를 적어놓고 실행하는 경우를 막을 수 있다.
	- 참고: [https://stackoverflow.com/questions/67985925/why-would-i-want-to-require-a-tty-for-sudo-whats-the-security-benefit-of-requi](https://stackoverflow.com/questions/67985925/why-would-i-want-to-require-a-tty-for-sudo-whats-the-security-benefit-of-requi)
	- [콘솔? 터미널? 쉘?](https://hanamon.kr/%ED%84%B0%EB%AF%B8%EB%84%90-%EC%BD%98%EC%86%94-%EC%89%98-%EB%AA%85%EB%A0%B9%EC%A4%84terminal-console-shell-command-line%EC%9D%98-%EC%B0%A8%EC%9D%B4-2/)

마지막으로, `secure_path`를 서브젝트에서 요구하는 대로 수정하자.

```sh
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

완성된 모습은 아래와 같다:

```sh
# visudo 9번째 줄
Defaults	env_reset
Defaults	mail_badpass
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
Defaults	authfail_message="AUTHENTICATION FAILED"
Defaults	log_input, log_output, iolog_dir="/var/log/sudo/"
Defaults	log_host, logfile="var/log/sudo/sudo.log"
Defaults	requiretty
```

참고:  
[https://www.tecmint.com/sudoers-configurations-for-setting-sudo-in-linux/](https://www.tecmint.com/sudoers-configurations-for-setting-sudo-in-linux/)  
[man sudoers](https://www.freebsd.org/cgi/man.cgi?query=sudoers&apropos=0&sektion=0&manpath=FreeBSD+13.0-RELEASE+and+Ports&arch=default&format=html)  

이제, 마지막 맨데토리인 `monitoring.sh`를 작성하러 가보자.
