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
리눅스는 일반적으로 DAC(사용자가 직접 권한을 부여하는 방식)으로 보안을 한다.

SELinux는 주로 파일 시스템 단위로 보안 모델을 다루고, AppArmor는 주로 응용프로그램 단위로 보안 모델을 다루는 듯하다.

AppArmor는 Debian 10 이후 버전에 자동으로 깔려있음. (`aa-status`, `systemctl status apparmor`로 확인)

## LVM이란?

내일 정리하기

## 명령어들

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
