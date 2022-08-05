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
resizepart 2, 5 to 100%

# 조정이 끝났다면, quit를 입력하고 프로그램을 나온다.

# df -h를 입력해보면, 아직 용량이 늘어나지 않았다고 나올 것이다.
# 먼저, pvs를 입력하여 우리가 늘리고자 하는 물리 디스크(물리 볼륨)의 이름을 확인하고(sda5_crypt),
# 아래의 명령어를 입력하여 리사이징을 진행한다.
pvresize /dev/mapper/sda5_crypt

# 이제 다시 pvs를 입력하면, 반영 여부를 다시 확인할 수 있다.
# root, home과 동일한 볼륨 그룹에 논리적 볼륨을 추가로 생성한다.
# 2GB만 추가해서 대충 4개를 비슷하네 분배했다. 어차피 구조만 비슷하면 될 것 같기에...
lvcreate -n var -L 500M gychoi42-vg
lvcreate -n srv -L 500M gychoi42-vg
lvcreate -n tmp -L 300M gychoi42-vg
lvcreate -n var-log -l +100%FREE gychoi42-vg

# root와 home의 파일 시스템과 동일하게 파티션을 설정해주었다.
mkfs.ext4 /dev/gychoi42-vg/var
...
mkfs.ext4 /dev/gychoi42-vg/var-log /var/log

# 그리고 잠깐! 마운트(mount) 하기 전에, 개인적인 추측으로는
# /var 의 내용을 따로 옮겨놓고, 다시 var에 붙여넣어야 할 것 같다.
# 무턱대고 마운트 했다가 그 안의 파일이 모두 사라지는 참사가 발생했었음...
# https://unix.stackexchange.com/questions/591971/after-partitioning-mounting-and-turning-of-directory-is-missing

# 위 링크를 따라 파일을 옮겨놓았다면, 만들어진 논리적 볼륨에 디렉토리를 마운트하자.
mount /dev/gychoi42-vg/var /var
...
mount /dev/gychoi42-vg/var-log /var/log

# 그리고 마지막으로 /etc/fstab 파일에, 지금까지 만든 논리적 볼륨의 UUID 혹은 논리 볼륨의 디렉토리를 적는다.
# 그래야 부팅 시 자동으로 디스크를 읽을 수 있어, 만든 파티션이 부팅 이후에도 사라지지 않는다.
# /etc/fstab
UUID=xxx	/var		ext4	defaults	0 2
...
UUID=xxx	/var/log	ext4	defaults	0 2
```

<img src="../img/partition.png" alt="partition" width="600" />

참고:  
[https://happylulurara.tistory.com/137](https://happylulurara.tistory.com/137)  
[https://lifegoesonme.tistory.com/449](https://lifegoesonme.tistory.com/449)  
[https://askubuntu.com/questions/1110790/encrypted-drive-cloning-resizing-partitions-problem](https://askubuntu.com/questions/1110790/encrypted-drive-cloning-resizing-partitions-problem)  
[https://unix.stackexchange.com/questions/637893/how-to-increase-lvm-when-using-luks2-on-debian-buster](https://unix.stackexchange.com/questions/637893/how-to-increase-lvm-when-using-luks2-on-debian-buster)  
[https://itguava.tistory.com/100](https://itguava.tistory.com/100)  
[https://starrykss.tistory.com/1760](https://starrykss.tistory.com/1760)

ext4, fstab에 대해 좀 더 자세하게 정리하기.
