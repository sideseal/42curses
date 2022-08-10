# Born2BeRoot

Virtual Box를 사용하여 가상 머신을 만들고, 가상 머신의 시그니처(`shasum`)가 담긴 `signature.txt` 파일을 제출해야 한다.

[Part 1. Install](./docs/install.md)

[Part 2-1. Setting: SSH, 포트포워딩, 방화벽](./docs/setting1.md)

[Part 2-2. Setting: 패스워드, 유저, sudo](./docs/setting2.md)

[Part 3. Monitoring.sh](./docs/monitoring.md)

[Part 4. Bonus](./docs/bonus.md)

[Part 5. 평가 준비](./docs/evaluation.md)

- 가상 머신을 시작할 때, `Volume group "gychoi42-vg" not found`가 뜨는 이유가 무엇일까?

* 파티션이 암호화(encrypted)되어 있으면 시스템이 `lvmetad` 명령어로 파티션을 읽지 못해서 발생하는 상황이라고 하는데, 따라서 암호화된 파티션을 사용하는 경우 자연스러운 현상이라고 볼 수 있을 것 같다.
* 참고: [https://ubuntu.forumming.com/question/524/volume-group-ldquo-ubuntu-vg-rdquo-not-found-cannot-process-volume-group-ubuntu-vg](https://ubuntu.forumming.com/question/524/volume-group-ldquo-ubuntu-vg-rdquo-not-found-cannot-process-volume-group-ubuntu-vg)
