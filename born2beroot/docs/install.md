## 가상 머신(Virtual Machine, VM)이란?

가상화란 일반적으로 컴퓨터 리소스를 추상화함을, 즉 컴퓨터 내부의 작동 방식을 다른 시스템, 응용 프로그램, 사용자들로부터 감추는 기술을 의미한다. 그렇다면 가상 머신(가상화된 컴퓨터?!)이란 무엇일까?

가상 머신은 **물리적 컴퓨터와 동일한 기능을 제공하는 소프트웨어 컴퓨터**이다. 가상 머신은 (지금 우리가 다루고 있는) 물리적 컴퓨터와 동일하게 애플리케이션과 운영 체제를 실행하지만, 가상 머신은 물리적 컴퓨터 안에서 실행되고 작동하는 컴퓨터 파일일 뿐이다. 컴퓨터 안의 컴퓨터라니!

가상 머신을 사용하면 위험한 작업을 자유롭게 테스트할 수 있다. 가상 머신은 호스트 컴퓨터로부터 샌드박스화 되므로, 변조된 파일이 호스트 컴퓨터를 위협할 수 없다. 혹은 호스트 컴퓨터의 운영 체제에 제한되지 않고 다양한 운영 체제 환경을 실행할 수 있을 것이다. 하지만 한 대의 컴퓨터에서 또 다른 컴퓨터를 실행하는 일은 아주 무겁기에(하나의 물리적인 자원을 두 대의 컴퓨터가 동시에 사용한다면...), 여러 가상 머신을 실행할 경우, 호스트 컴퓨터의 성능이 불안정해질 수 있다. 또한 가상 머신은 물리적 컴퓨터보다 효율성이 떨어지고 속도도 느린 경향이 있다.

참고: [https://www.vmware.com/kr/topics/glossary/content/virtual-machine.html](https://www.vmware.com/kr/topics/glossary/content/virtual-machine.html)

혹시 게임을 좋아하는 사람이라면 '에뮬레이터'가 떠오르지 않았을까? 그렇다면 에뮬레이터와 가상 머신은 어떤 차이가 있을까?

가상화 방법에는 다음의 3가지가 있다고 한다: 호스트 가상화, 하이퍼바이저 가상화, 컨테이너 가상화

* 호스트 가상화 : 게스트 운영 체제(게스트 OS, 가상의 컴퓨터)를 호스트 운영 체제(호스트 OS, 물리적 컴퓨터)의 소프트웨어로 에뮬레이팅하는 방식으로, 오버헤드가 크지만 범용성은 가장 뛰어나다.
* 하이퍼바이저 가상화 : 물리적 컴퓨터의 하드웨어에 '하이퍼바이저'라는 소프트웨어를 설치하여, 호스트 운영 체제의 개입 없이 게스트 운영 체제와 물리적 하드웨어와의 직접적인 상호작용을 가능하게 하는 방식(bare-metal).
* 컨테이너형 가상화 : 위의 두 방식과는 다르게 운영 체제가 아닌 소프트웨어를 바로 가상화하는 기술. 호스트 운영 체제 위에 컨테이너가 '이미지'라는 (가벼운) 실행 패키지를 빌드, 배포, 작동한다.

정리하면, 호스트 가상화는 실제 물리적 컴퓨터의 리소스를 가상 머신과 공유하고, 하이퍼바이저 가상화는 (호스트 가상화와는 다르게) 게스트 운영 체제가 호스트 운영 체제를 경유하지 않기에 오버헤드가 적어 퍼포먼스가 좋다. 컨테이너형 가상화는 OS 자체를 가상화하지 않기에, 가상화 소프트웨어를 가벼운 리소스와 함꼐 빠르게 사용할 수 있다. 이번에 사용하는 Virtual Box는 호스트 가상화인 듯 하다.

참고: [https://eunjinii.tistory.com/10](https://eunjinii.tistory.com/10)

## CentOS? Debian?

리눅스(linux)는 오픈소스로써 누구나 자유롭게 수정하고 배포할 수 있다. 따라서 수많은 형태의 리눅스들이 나오게 되었는데, 크게 두 가지 계열의 리눅스로 말할 수 있다고 한다. 바로 레드햇 계열과 데비안 계열이다. 이들의 대표적인 버전으로 레드햇은 센토스(CentOS), 데비안은 우분투(UbuntuOS)가 있다. (하지만 과제에서 사용해야 하는 버전은 센토스와 데비안 자체이다!)

참고: [https://jhnyang.tistory.com/135](https://jhnyang.tistory.com/135)

### CentOS

레드햇 엔터프라이즈 리눅스(RHEL)이 유료화됨에 대한 반발로 나온 운영체제. RHEL의 기술을 그대로 사용할 수 있다는 장점이 있지만, 오픈소스로 돌아가기에 사후 기술 지원이 RHEL에 비해 느리다고 한다. `yum`(Yellodog Update Modified)이라는 패키지 설치 관리 도구(패키지 매니저)를 사용한다.

참고: [https://dololak.tistory.com/331](https://dololak.tistory.com/331)

### Devian

데비안은 순수하게 오픈소스 자원자들로부터 구성된 운영체제이다. 데비안은 안정성을 매우 중시하는 리눅스 배포판이여서, 서버 사용에 있어 상당한 인기를 끌고 있다고 한다. `apt`(Advanced Packaging Tool)라는 패키지 매니저를 사용한다(`apt-get`과 큰 차이는 없다) 유명한 오픈소스인 만큼 커뮤니티도 아주 크다.

참고: [https://la-nube.tistory.com/190](https://la-nube.tistory.com/190)

이번 과제에서는 Devian을 사용할 예정이다('`Debian` is highly recommended if you are new to system administration.' ㅎㅎ;;) Devian 11은 여러 하드웨어의 지원과 더불어 Apache, Emacs, LibreOffice, Vim의 최신 버전과(Vim은 최근 9.0이 나왔지만...) 업데이트된 Linux kernal을 사용한다.

[What's New in Devian 11 "Bullseye"?](https://www.linuxjournal.com/content/whats-new-debian-11-bullseye)

## Devian 설치하기

설치 과정은 다음의 블로그를 참고했다: [https://techdebt.tistory.com/18](https://techdebt.tistory.com/18)

먼저, [https://www.debian.org/releases/stable/debian-installer/](https://www.debian.org/releases/stable/debian-installer/)로 이동하여, 'netinst'(전체 운영 체제를 설치할 수 있는 단일 CD)에서 `amd64`의 디스크 이미지를 다운로드한다.
* AMD64 : AMD사가 만든 64bit 프로세서(x86-64). 기존 32bit 아키텍처와 호환되면서도 인텔의 프로세서와 다르게 성능 저하가 없어 64bit 프로세서의 표준으로 자리가 매겨졌다고 한다. (ARM64와 헷갈리지만... ARM은 RISC 명령어 체계를 사용하고, 인텔 계열의 AMD는 CISC 명령어 체계를 사용한다.)
* iso : 국제 표준화 기구(ISO)가 제정한 광학 디스크의 압축 파일 형식. 모든 CD나 DVD를 ISO 형식의 파일로 만들 수 있기에, 물리적인 매체를 이용하지 않아도 인터넷 연결을 통하여 디스크의 파일을 전송할 수 있다. ISO 파일은 일반적인 압축 툴로 읽거나 실행하기 어렵기에 특정한 도구를 사용해야 한다.

이제 Virtual Box를 키고 Linux Devian 가상 머신을 설치하자.

1. Virtual Box 상단의 'new'를 클릭하여 가상 머신 생성 과정으로 들어간다.
2. 가상 머신을 설치할 경로를 선택한다. 8GB의 용량이 필요하기에 goinfre에 저장하고 디스크 이미지(VDI)를 다시 압축해서 클라우드에 올려놓거나, 개인이 소지한 하드디스크에 저장해야 한다.
3. 메모리는 1024MB로 설정.
4. 그리고 '새 가상 하드디스크 만들기', 'VDI', '동적 할당', 8GB를 선택한다.
	- VDI(VirtualBox Disk Image) : Oracle의 Virtual Box에서만 사용 가능한 포맷 방식. Virtual Box에서만 사용할 것이기에 VDI를 선택함.
	- VHD(Virtual Hard Disk) : Virtual Box 외에도 Hyper-V, Xen에서 구동이 가능한 포맷 방식.
	- VMDK(Virtual Machine Disk) : Virtual Box와 VMware Player에서 구동이 가능한 포맷 방식.
	- 동적 할당(dynamically allocation)은 가상 머신이 사용한 만큼만 호스트 컴퓨터의 하드 디스크 용량을 사용한다. 고정 할당(Fixed size)을 사용하면 가상 머신을 좀 더 빠르게 사용할 수 있지만, 호스트 컴퓨터를 보다 쾌적하게 이용하기 위해 동적 할당을 선택하였다.
5. 선택을 모두 완료하고, Virtual Box 창으로 다시 나오게 되면, 상단의 'start'를 누르고 다운로드했던 iso 파일을 마운트한다.
6. 'install' -> 언어 설정 -> 타임존 설 -> 키보드 언어 설정
7. 서브젝트에 나온 대로 hostname은 'intra id'42로 해야 한다(즉, gychoi42).
8. 도메인 이름은 생략.
9. 비밀번호 설정. 비밀번호를 설정하지 않으면 root, 유저 구분 없이 모두 sudo를 사용할 수 있게 되어버린다!
10. root가 아닌 유저 한 명을 추가한다. 유저 이름은 인트라 id 그대로 하였음.
11. 서브젝트의 요구에 따라 LVM을 사용한다. 'use entire disk and set up encrypted LVM' 선택.
12. 서브젝트의 요구에 따라 2개 이상의 LVM을 만들기 위해 /home 파티션을 분리하는 옵션을 선택한다.
13. LVM에도 비밀번호를 설정해주자.
14. 서브젝트에 나온대로 파티셔닝을 하기 위해 최댓값(8.1GB)로 설정한다.
15. extra media installation은 생략.
16. 패키지를 다운로드하는데 사용할 네트워크 서버는 한국 - debian으로 선택(카이스트 미러 서버가 대학에서 운영하다 보니 생각보다 느리다고 해서...).
17. http proxy 설정은 생략.
18. 데스크탑 환경은 사용하지 않을 것이기에 기본 값만 설정한다.
19. GRUB 부트로더를 설치해야 11버전은 클러스터에서 돌아간다고 한다!
20. 그리고 /dev/sda에 부트로더를 설치해야 한다고 한다. 그렇지 않으면 부트로더가 하드 드라이버의 시스템들을 다루지 못하는 듯 하다. 부트로더는 /dev/sda에 있지만, 부트로더의 코드들은 /dev/sda1에 저장되므로, 서브젝트의 디렉토리 구조와 일치하게 된다(꼭 일치해야 하는지는 모르겠지만...)
	- [https://opencomputeproject.github.io/onie/design-spec/x86_boot_loader.html](https://opencomputeproject.github.io/onie/design-spec/x86_boot_loader.html)
21. LVM 비밀번호, root/root 비밀번호 입력 후 들어가면 가상 머신의 세계가 등장한다. `lsblk` 명령어를 입력하여 LVM 파티션이 두 개인지 확인하자.

<img src="../img/lsblk.png" alt="lsblk" width="300" />

LVM, 파티션, http 프록시, grub 설명하기.
