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

fdisk /dev/sda

apt install parted

resizepart 2, 5 to 100%

pvresize /dev/mapper/sda5_crypt
lvcreate -n var -L 500M gychoi42-vg
...
lvcreate -n var-log -l +100%FREE gychoi42-vg

mkfs.ext4 /dev/gychoi42-vg/var
...

mount /dev/gychoi42-vg/var /var
...
cd /var
mkdir log
mount /dev/gychoi42-vg/var-log /var/log

(나중에 좀 더 자세히 정리하기)

<img src="../img/partition.png" alt="partition" width="600" />

루트가 머무르는 파티션이라 삭제하고 다시 파티션을 만드는 일은 굉장히 많은 시스템 크래시를 만들었다.

참고:  
[https://happylulurara.tistory.com/137](https://happylulurara.tistory.com/137)  
[https://lifegoesonme.tistory.com/449](https://lifegoesonme.tistory.com/449)  
[https://askubuntu.com/questions/1110790/encrypted-drive-cloning-resizing-partitions-problem](https://askubuntu.com/questions/1110790/encrypted-drive-cloning-resizing-partitions-problem)  
[https://unix.stackexchange.com/questions/637893/how-to-increase-lvm-when-using-luks2-on-debian-buster](https://unix.stackexchange.com/questions/637893/how-to-increase-lvm-when-using-luks2-on-debian-buster)  
[https://itguava.tistory.com/100](https://itguava.tistory.com/100)  
