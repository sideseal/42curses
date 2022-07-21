# SSH 포트 및 권한 변경

A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.

SSH 연결은 4242번 포트에서만 가능해야 하고, 루트 계정으로 연결되어서는 안된다.

## SSH란?

SSH(Secure Shell, Secure Socket Shell)는 네트워크 프로토콜 중 하나로, 컴퓨터 간 인터넷과 같은 공용 네트워크(Public Network)의 통신에 있어 보안을 보장하여, 서로 안전한 통신을 가능하게 한다. 과거에는 텔넷(TELNET)이라는 네트워크 프로토콜을 이용하여 통신을 하였으나, 텔넷의 보안 문제로 사용률이 감소하여 현재는 SSH가 많이 쓰이고 있다고 한다.
	* 프로토콜(Protocol) : 서로 다른 통신 장비 간 주고 받는 데이터의 양식과 규칙. 클라이언트의 브라우저가 웹페이지를 보여주기 위해 서버와 HTTP/HTTPS 프로토콜로 통신을 하는 것처럼, 서로 다른 컴퓨터들이 shell을 통해 통신하기 위해 SSH를 사용한다.

SSH를 이용한 통신에서는 클라이언트(Clinent: Host에 접속하려고 하는 컴퓨터)와 호스트(Host: 접속 대상)의 통신이 암호화되어, 통신으로 전송되는 모든 데이터가 암호화되기에 안전하다. SSH 통신은 기본적으로 TCP 포트 22번을 사용한다. SSH는 키 교환 알고리즘을 사용하여 송/수신자 간 안전한 연결을 구성한다.
	* 포트(port) : 네트워크 서비스나 특정 프로세스를 식별하는 논리적 단위를 의미하며, 클라이언트가 특정 서버의 프로그램을 지정하는 방법으로 사용된다. 하나의 호스트 컴퓨터는 여러 개의 서버를 실행할 수 있기에, 클라이언트가 어느 서버에 접속할 것인지 포트 번호를 사용하여 명시한다.

참고:  
[https://medium.com/@jamessoun93/ssh란-무엇인가요-87b58c521d6f](https://medium.com/@jamessoun93/ssh%EB%9E%80-%EB%AC%B4%EC%97%87%EC%9D%B8%EA%B0%80%EC%9A%94-87b58c521d6f)
[https://whitedelay.github.io/post/what-is-ssh](https://whitedelay.github.io/post/what-is-ssh)
[https://study-recording.tistory.com/13](https://study-recording.tistory.com/13)

* * *

과제 말미에 sudo와 관련된 작업을 해야하기에 sudo를 설치한다. 하지만 설치하기 전에, `apt update`, `apt upgrade`로 운영체제를 최신의 상태로 유지하자.

```sh
# sudo가 시스템에 설치되어 있는지 확인하고 싶다면...
dpkg-query -l | grep sudo

# sudo를 설치한다.
apt install sudo

# pretty한 에디팅을 위해 vim도 설치...
apt install vim
```

## dpkg?

dpkg란 데비안 패키지 관리 시스템의 기초가 되는 소프트웨어이다. 패키지 관리(Package Management)란, 새로운 소프트웨어를 설치, 업데이트, 삭제하는 일을 말한다. 패키지는 저장소(repository)에 저장되어 있으며, HTTP 혹은 FTP 서버를 통해 다운로드 할 수 있다. 리눅스는 배포판에 따라 서로 다른 패키지 형식을 지원하는데, 데비안의 계열의 경우, `.deb` 파일 확장자를 가진다.

패키지를 관리하기 위한 패키지 관리 도구는 저수준 툴(low-level tools)과 고수준 툴(high-level tools)로 나뉜다.
	* 저수준 툴 : 실제 패키지의 설치, 업데이트 삭제 등을 수행. 하지만 자동으로 패키지를 다운로드하거나 패키지 간 의존성을 해결하지 않는다.
	* 고수준 툴 : 패키지 의존성 해결, 패키지 다운로드, 패키지 검색 등의 기능을 제공.
dpkg는 데비안 계열의 리눅스에서 사용되는 저수준 패키지 관리자(low-level package manager)이고, apt는 데비안 계열의 리눅스에서 사용되는 고수준 패키지 관리자(high-level package manager)이다. 소프트웨어를 관리하는데 보통 apt 명령으로 충분하지만, 시스템에 있는 특정 파일과 패키지의 관계를 보는 것처럼, 보다 자세한 일을 수행하기 위해선 dpkg 명령이 필요하다고 한다.

<img src="../img/packageManager.png" alt="package manager" width="600" />

참고: [https://gamsungcoding.tistory.com/entry/Linux-리눅스Linux-패키지-관리하기](https://gamsungcoding.tistory.com/entry/Linux-%EB%A6%AC%EB%88%85%EC%8A%A4Linux-%ED%8C%A8%ED%82%A4%EC%A7%80-%EA%B4%80%EB%A6%AC%ED%95%98%EA%B8%B0)

## sudo를 왜 설치해야 할까?

과제에서 sudo를 다루는 문제가 나오긴 하지만, 우리가 sudo를 사용함으로써 얻을 수 있는 이점은 무엇일까?

sudo를 사용하면 root가 시스템 상에서 작업하는 시간이 짧아진다. root shell로 장시간 작업을 하다가 실수를 하게 될 경우, 결과를 책임질 수 없게 된다. 따라서 root 권한이 필요한 명령어의 경우에만 sudo를 사용한다면, 사용자의 오류를 방지할 수 있게 된다.

또한 sudo를 사용하면 사용자의 특권 행동이 로그(log)로 남게 되기에 추적이 쉬워지고, 이에 따라 사용자의 권한과 책임이 명확해진다. 만약 root 권한을 여러 사람이 공유한다면(su root), 어떤 작업이 누구에 의해 행해졌는지 파악할 수 없게 된다.

마지막으로 sudo는 sudoers라는 파일에 등록된 사용자만 사용할 수 있기에, 침입자는 sudo를 사용할 수 없다. 만약 침입자가 sudo를 사용하기 위해 자신의 존재를 sudoers에 등록한다면, 침입자의 정보가 시스템에 모두 기록되므로 침입자의 정보를 알 수 있게 된다.

따라서 root 권한을 최소화하는 것이 시스템 보안에 중요한 요소라면, sudo의 사용은 보안의 기본이라고 할 수 있을 것이다. 하지만 동시에 sudo 명령어를 남용하는 것을 조심해야 할 것이다. 가령 root가 아닌 유저가 sudo 명령어로 패키지를 설치하게 된다면 시스템 보안의 문제가 발생할 수 있다.

* 참고로 sudo와 su는 조금 다르다! su는 사용자를 전환하는 명령어라면(`su -`는 root 계정으로 전환된다), sudo는 사용자 전환 없이 단일 명령에 대해 root 권한을 부여한다.

참고: [https://deois.tistory.com/entry/sudo사용의-필요성](https://deois.tistory.com/entry/sudo%EC%82%AC%EC%9A%A9%EC%9D%98-%ED%95%84%EC%9A%94%EC%84%B1)

* * *

아래의 과정을 따라 SSH 서버를 설치한다.

```sh
# devian 11에서는 이미 깔려 있었다.
sudo apt install openssh-server

# SSH 서버가 작동하고 있는지 확인. 작동한다면 Active 항목이 active (running)으로 표시된다.
systemctl status ssh
```
* systemctl이란?
	- systemctl은 systemd 및 서비스를 제어하고 관리하는 데 사용되는 Linux 유틸리티이다. systemd(system management daemon)는 시스템의 첫 번째 프로세스(1번 PID)로, 부팅부터 서비스 관리, 로그 관리 등 시스템의 전반적인 기능을 관리하는 데몬(daemon, 백그라운드에서 여러 작업을 하는 프로세스)이다.
	- 참고: [https://junb51.tistory.com/9](https://junb51.tistory.com/9)

SSH는 기본적으로 22번 포트로 연결되어 있기에, sshd_config 파일을 수정하여 포트를 변경하고 루트 계정 접속을 막는다.

```sh
# /etc/ssh/sshd_config

...
# 주석 처리되어 있는 Port를 해제하고, 22를 4242로 변경한다.
Port 4242
...
# 주석 처리되어 있는 PermitRootLogin을 해제하고, no로 변경한다.
PermitRootLogin no
```

변경을 완료하고, SSH 서버를 재시작한다.

```sh
sudo systemctl restart ssh
```

# UFW 방화벽 설정

You have to configure your operating system with the UFW firewall and thus leave only port 4242 open.
