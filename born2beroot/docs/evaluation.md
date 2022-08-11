# 평가 준비

## Virtual Box란?

즉, 가상 머신이란 물리적 컴퓨터 안에서 실행되는 컴퓨터 파일이다. 컴퓨터 안의 컴퓨터!
가상 머신을 사용하면 위험한 작업을 자유롭게 테스트할 수 있다(샌드박스).
버추얼 박스는 호스트 가상화 방식(호스트 컴퓨터의 OS 위에 통째로 띄우는 방식).

## Debian을 설치한 이유

1. 가상머신 초보라 ㅎㅎ
2. 안정성을 매우 중시하는 리눅스 배포판(아무 패키지나 다루지 않는다)
3. 감동적인 오픈소스 정신
4. CentOS는 주로 기업용 서버로 이용된다고...

## apt vs. aptitude

모두 패키지 관리 도구. 하지만 aptitude가 좀 더 다양한 일들을 한번에 할 수 있다고 한다(GUI도 제공!). 하지만 가상머신에서 그렇게 복잡한 패키기 관리를 할 일이 없을 것 같고, apt 관련 자료가 더 많아서 apt 사용.

### dpkg

apt가 고수준 패키지 관리자라면, dpkg는 저수준 패키지 관리자. 보다 자세하게 패키지를 다루고자 할 때 사용한다고.

## SELinux vs. AppArmor

SELinux는 설정이 복잡하지만, 그만큼 사용자가 보안을 위해 할 수 있는 일들이 많다.
AppArmor는 SELinux보다 직관적.

SELinux와 AppArmor는 모두 MAC 보안을 제공. 즉 보안 정책을 사용하여 프로세스의 행동을 제어한다.
리눅스는 일반적으로 DAC(소유자가 직접 파일에 권한을 부여하는 방식)으로 보안을 한다.

SELinux는 주로 파일 시스템 단위로 보안 모델을 다루고, AppArmor는 주로 응용프로그램 단위로 보안 모델을 다루는 듯하다.

AppArmor는 Debian 10 이후 버전에 자동으로 깔려있음. (`aa-status`, `systemctl status apparmor`로 확인)

## LVM이란?

리눅스 저장 공간을 효율적이고 유연하게 관리하는 커널의 일부.
여러 개의 디스크 공간을 합쳐 하나의 공간(볼륨 그룹)을 사용하는 것처럼 만든다.
물리 디스크를 추가하여 파티션의 크기를 변경하기 위해선 운영체제 재설치 필요.
하지만 LVM을 사용하면 그럴 필요가 없다.

## SUDO를 설치해야 하는 이유

사용자가 root를 사용하는 시간이 짧아져, 실수를 방지할 수 있다.
sudo는 로그를 남겨 사용자의 행동을 추적할 수 있다.
sudoers에 등록된 사용자만 sudo를 사용할 수 있으므로 보안 향상.

### SUDO가 TTY 모드에서 실행되어야 하는 이유는?

SUDO 명령어가 현재의 터미널 바깥에서 사용되는 경우를 방지한다.

### SUDO의 로그 파일의 개수와 journalctl의 로그의 개수가 다르다?

그야 중간에 SUDO 설정을 하였으니까...

## UFW란?

데비안 계열에서 사용하는 방화벽 프로그램. 방화벽은 신뢰할 수 있는 네트워크를 구분하며, 네트워크 트래픽을 모니터링하고 제어할 수 있다. 리눅스는 기본적으로 `iptables`를 방화벽으로 사용하나, UFW를 사용하면 보다 쉽게 방화벽을 제어할 수 있다.

## SSH란?

컴퓨터 간 네트워크의 통신에 보안을 담당하는 프로토콜. 클라이언트와 호스트의 통신이 암호화된다. (키 교환 알고리즘을 사용함.)

## CRON이란?

어떤 작업을 특정 시간에 실행시키기 위한 데몬.

### CRONTAB 형식

```
분(0-59)    시간(0-23)    일(1-31)    월(1-12)    요일(0-7)
```

## 명령어들

### 그래픽 모드 확인

```sh
systemctl get-defaults

# graphical.target이 나오지 않으면 된다.
```

### 파티션 확인

```sh
lsblk
```

### hostname 변경

```sh
hostnamectl set-hostname <machine-name>
```

### 운영체제 확인

```sh
hostnamectl
```

### UFW 활성화 확인

```sh
ufw status
# or
systemctl status ufw
```

### SSH 활성화 확인

```sh
systemctl status ssh
```

### SSH 정보 확인

```sh
vim /etc/ssh/sshd_config
```

### 패스워드 정보 확인

```sh
vim /etc/login.defs
vim /etc/pam.d/common-password
```

### 유저 패스워드 정책 확인

```sh
vim /etc/shadow
```

### 유저 그룹 확인

```sh
groups
# or
id
```

### 유저 생성

```sh
adduser <username>
```

### 유저 확인

```sh
vim /etc/passwd
```

### 그룹 만들기

```sh
addgroup <groupname>

# checking group exists
grep <groupname> /etc/group
```

### 그룹에 유저 추가

```sh
adduser <username> <groupname>

# check user group
id <username>
```

### 유저의 그룹 확인

```sh
groups <username>
```

### SUDO 설치 확인

```sh
dpkg -l | grep sudo
```

### 유저에게 SUDO 권한 부여

```sh
adduser <username> sudo
```

### SUDO 설정

```sh
visudo
```

### SUDO 실행 확인

```sh
cd /var/log/sudo
```

### UFW 작동 확인

```sh
systemctl status ufw
```

### UFW 규칙 확인

```sh
ufw status
```

### UFW 포트 개방 및 닫기

```sh
# allow port
ufw allow <port>

# disable port
ufw status numbered
ufw delete <ruleNum>
```

### SSH 작동 확인

```sh
systemctl status ssh
```

### SSH 설정 확인

```sh
vim /etc/ssh/sshd_config
```

### SSH Keybase 로그인 설정

먼저, 로컬의 `$HOME/.ssh/` 폴더로 들어간다.

이전에 `ssh-keygen`을 한 이력이 남아있다면, 폴더에 `id_rsa.pub` 파일이 생성되어 있을 것이다. 공개키를 서버로 전송하기 위해선...

```sh
ssh-copy-id -p 4242 <username>@localhost
```

SSH 포트포워딩을 한 포트로 연결해서 공개키를 전송하자.
이후 비밀번호 없이 로그인이 진행된다.

- 참고 : [https://velog.io/@lehdqlsl/SSH-공개키-암호와-방식-접속-원리-i7rrv4de](https://velog.io/@lehdqlsl/SSH-%EA%B3%B5%EA%B0%9C%ED%82%A4-%EC%95%94%ED%98%B8%ED%99%94-%EB%B0%A9%EC%8B%9D-%EC%A0%91%EC%86%8D-%EC%9B%90%EB%A6%AC-i7rrv4de)

### CRON이 실행되지 않게 하기

```sh
systemctl disable cron
reboot
```
