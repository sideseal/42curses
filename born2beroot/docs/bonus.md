# Bonus Part

## LVM 파티션 추가하기

(갑작스러울 수 있지만, 물리적 볼륨, 볼륨 그룹, 논리적 볼륨을 한 번에 설명하는 그림)

<img src="../img/volumes.png" alt="volumes" width="600" />
이미지 출처: https://askubuntu.com/questions/417642/logical-volume-physical-volume-and-volume-groups

LVM 파티션을 추가하기 위해, 우선 가상 머신의 하드 디스크 용량을 늘려주기로 하였다. 커맨드 라인으로 입력하는 방법도 있으나... 간단하게 VM 매니저 어플리케이션으로 들어가, `File -> Virtual Media Manager -> Properties` 하단의 용량을 늘려주고(나는 8G에서 10G로 늘렸다), 적용 버튼을 누르면, 가상 머신의 용량이 증가한다.

증가한 가상 머신의 용량을 확인하기 위해 `lsblk`를 입력하고, `sda`를 살펴보면 된다.

- `lsblk` : 리눅스 디바이스 정보를 트리 형식으로 출력하는 명령어.
- `sda` : 리눅스 시스템이 첫 번째로 발견한 하드디스크의 이름. 가상 머신이 SCSI 인터페이스를 사용하여 `/dev/sda`로 불리는 듯하다.
- 참고: [https://m.blog.naver.com/tlsrka649/221797149037](https://m.blog.naver.com/tlsrka649/221797149037)

하드디스크에 (나의 경우에는) 2GB가 추가로 생겼으니, 이를 이용하여 파티션을 생성하자.

서브젝트에는 sda5 파티션의 크기를 늘려, 그 안에 추가로 여러 파티션을 쪼개어 넣었다. 따라서 먼저 sda5 파티션의 크기를 늘려야 한다.

그런데 기존 명령어인 `fdisk`를 사용하는 일은 너무 위험했다. `fdisk`로 크기를 늘리기 위해선 기존 sda5 파티션을 삭제하고 늘어난 전체 용량을 다시 배정하는 방식인데, sda5 파티션이 루트로써 동작하고 있기에, 섣부르게 삭제하다간 시스템이 망가져버린다(가상머신 파일 복사본을 따로 마련해서 다행이지 한 6번은 깨뜨려먹은 것 같다).

따라서 [GNU parted 유틸리티](https://geekpeach.net/ko/linux-parted-%EC%9C%A0%ED%8B%B8%EB%A6%AC%ED%8B%B0-%EC%9D%B4%ED%95%B4)를 사용하여, sda5 파티션의 크기를 늘렸다.

```sh
# parted 설치
apt install parted

# 실행
# (따로 디스크를 추가하지 않고 용량을 늘렸기에 첫 번째 하드디스크를 다룬다)
parted /dev/sda

# 2번 파티션, 5번 파티션을 늘어난 용량만큼 크기 조정.
# 2번 파티션은 논리적 파티션인 5번 파티션을 지시하고 있다.
# 따라서 2번과 5번을 모두 용량을 같게 처리해야 하나... 확신이 들지는 않지만,
# fdisk로 파티션의 끝을 확인해보면 동일하기에, 두 파티션 모두 용량을 최대로 늘리도록 명령어를 사용하였음.
(parted) resizepart 2
# 100% 입력하고 엔터
End?    [8.7GB]? 100%
...
# 파티션 5번에 대해 위와 동일하게 진행한다.
(parted) resizepart 5
End?    [8.7GB]? 100%

# 조정이 끝났다면, quit를 입력하고 프로그램을 나온다.
# 아마 reboot를 한 번 하고, 아래 pvresize를 실행해야 하는 것 같다.

# 먼저, pvs를 입력하여 우리가 늘리고자 하는 물리 디스크(물리 볼륨)의 이름을 확인하고(sda5_crypt),
# 아래의 명령어를 입력하여 할당된 디스크 공간에 맞게 파티션을 리사이징을 진행한다.
pvresize /dev/mapper/sda5_crypt

# 이제 다시 pvs를 입력하면, 반영 여부를 확인할 수 있다.

# root, home과 동일한 볼륨 그룹에 논리적 볼륨을 추가로 생성한다.
# 2GB만 추가해서 대충 4개를 비슷하네 분배했다. 어차피 구조만 비슷하면 될 것 같기에...
# -L은 MB, GB ... 단위로 정하는 명령이고, -l은 4MB 사이즈 기준으로 정하는 옵션이다.
lvcreate -n var -L 500M gychoi42-vg
lvcreate -n srv -L 500M gychoi42-vg
lvcreate -n tmp -L 500M gychoi42-vg
lvcreate -n var-log -l +100%FREE gychoi42-vg

# root와 home의 파일 시스템과 동일하게 파티션을 설정해주었다.
mkfs.ext4 /dev/gychoi42-vg/var
...
mkfs.ext4 /dev/gychoi42-vg/var-log

# 그리고 잠깐! 마운트(mount) 하기 전에, 개인적인 추측으로는
# /var 의 내용을 따로 옮겨놓고, 다시 var에 붙여넣어야 할 것 같다.
# 무턱대고 마운트 했다가 그 안의 파일이 모두 사라지는 참사가 발생했었음...

# 해당 링크를 따라 디렉토리를 마운트했다.
# https://unix.stackexchange.com/questions/131311/moving-var-home-to-separate-partition

# single user mode로 들어가, 디렉토리에 read-write 행동이 발생하지 않도록 한다.
init 1

# mnt 폴더에 임시로 디렉토리름 만들고, 마운트를 한다.
# 그런데 해당 과정이 왜 필요한지는 아직 정확히 모르겠음...
mkdir /mnt/var
mount /dev/gychoi42-vg/var /mnt/var

# 디렉토리로 이동하여 파일에 담긴 모든 정보를 mnt/<dir> 폴더에 복사한다.
cd /var
cp -ax . /mnt/var

# 디렉토리 복사본을 만들고 기존 디렉토리를 지운다.
cd /
mv var var.old

# 디렉토리를 새로 만든다.
mkdir var

# 마운트 해제
umount /dev/gychoi42-vg/var

# 새로 만들어진 디렉토리로 마운트
mount /dev/gychoi42-vg/var /var

# /etc/fstab 파일에 파티션의 정보를 저장해서 reboot 하더라도 지워지지 않게 한다.
# blkid 명령어로 파티션의 UUID를 맨 앞에 입력해도 된다.
/dev/gychoi42-vg/var    /var    ext4    defaults    0 0
# [파일시스템 장치명]   [마운트 포인트] [파일 시스템 종류]  [옵션]  [덤프, 파일체크 옵션]
# https://itdexter.tistory.com/311

# srv, tmp, var/log에 대해서도 위 과정을 동일하게 반복함.

# 모두 마운트가 완료되었다면, RunLevel을 변경하여 CLI 멀티태스킹 모드로 돌아온다.
init 3

# 여담이지만 systemctl get-default가 graphical.target로 나오기에
# systemctl set-default multi-user.target으로 변경하였다.
# https://shuzy65536.tistory.com/20
```

- `ext4` : `ext`는 리눅스용 파일 시스템을 의미한다. `ext4`는 이전의 버전들과 하휘 호환성을 가짐과 동시에 성능이 향상된 버전이라고 한다.
- 파일 시스템 : 운영체제가 파일을 사용자가 쉽게 접근 및 발견할 수 있도록, 시스템의 디스크상에 일정한 규칙을 가지고 보관하는 방식. 운영체제가 파일들을 일정한 규칙을 연속적으로 사용하여 디스크의 파티션 상에 저장하게 되면, 저장장치 내에서 파일을 저장하는데 용이하고, 파일 검색 및 관리를 효율적으로 할 수 있다. (http://www.incodom.kr/Linux/파일시스템)[http://www.incodom.kr/Linux/%ED%8C%8C%EC%9D%BC%EC%8B%9C%EC%8A%A4%ED%85%9C]
- 런 레벨(runlevel) : 시스템 관리의 용이함을 위하여 서비스의 실행을 단계별로 구분하여 적용하는 것. 1은 안전모드, 3은 텍스트 인터페이스 기반 다중 사용자 모드이고, 5는 그래픽 인터페이스 기반 다중 사용자 모드이다.
- fstab : 리눅스 부팅 시 마운트 정보와 파일 시스템 정보를 저장하고 있는 파일. 시스템이 부팅할 때 파일에 구성된 정보들이 자동으로 적용될 수 있도록 한다.

<img src="../img/partition.png" alt="partition" width="600" />

참고:  
[https://happylulurara.tistory.com/137](https://happylulurara.tistory.com/137)  
[https://lifegoesonme.tistory.com/449](https://lifegoesonme.tistory.com/449)  
[https://askubuntu.com/questions/1110790/encrypted-drive-cloning-resizing-partitions-problem](https://askubuntu.com/questions/1110790/encrypted-drive-cloning-resizing-partitions-problem)  
[https://unix.stackexchange.com/questions/637893/how-to-increase-lvm-when-using-luks2-on-debian-buster](https://unix.stackexchange.com/questions/637893/how-to-increase-lvm-when-using-luks2-on-debian-buster)  
[https://itguava.tistory.com/100](https://itguava.tistory.com/100)  
[https://starrykss.tistory.com/1760](https://starrykss.tistory.com/1760)  
[https://unix.stackexchange.com/questions/131311/moving-var-home-to-separate-partition](https://unix.stackexchange.com/questions/131311/moving-var-home-to-separate-partition)

## WordPress 구축

lighttpd, MariaDB, PHP를 이용하여 워드프레스 웹사이트를 구축해야 한다.

- lighttpd : Apache보다 적은 메모리 자원을 사용하면서도 높은 성능을 보이는 오픈소스 웹 서버 어플리케이션.
	- 웹 서버 : 웹 브라우저와 같은 클라이언트로부터 HTTP 요청을 받아들이고, HTML 문서와 같은 웹 페이지를 반환하는 컴퓨터 프로그램.
	- 참고 : [https://ko.wikipedia.org/wiki/웹서버](https://ko.wikipedia.org/wiki/%EC%9B%B9_%EC%84%9C%EB%B2%84), [https://aroundck.tistory.com/1113](https://aroundck.tistory.com/1113)
- MariaDB : MySQL을 유료화한 오라클에 대한 반발로 나온 오픈소스 RDBMS.
	- RDBMS(Relational Database Management System) : 관계형 데이터베이스(RDB, Relational Database)를 생성, 수정 및 관리할 수 있는 소프트웨어.
	- 참고 : [https://jwprogramming.tistory.com/52](https://jwprogramming.tistory.com/52), [https://bio-info.tistory.com/102](https://bio-info.tistory.com/102)
- PHP : 서버 측에서 실행되는 서버 사이드 스크립트 언어. PHP로 작성된 코드를 HTML 코드 안에 추가하면, 웹 서버는 해당 PHP 코드를 해석하여 동적 웹 페이지를 생성한다.
	- 자바스크립트는 클라이언트 측에서 실행되는 스크립트 언어.
	- 참고 : [https://choseongho93.tistory.com/61](https://choseongho93.tistory.com/61)
- 워드프레스 : 세계 최대의 온라인 발행 플랫폼으로, 웹페이지 제작 및 관리를 위한 콘텐치 관리 시스템(CMS, Contents Management System)의 하나.
	- 참고 : [http://b-lot.co.kr/워드프레스란/](http://b-lot.co.kr/%EC%9B%8C%EB%93%9C%ED%94%84%EB%A0%88%EC%8A%A4%EB%9E%80/)

ㅇㅇ

