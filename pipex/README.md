# pipex

UNIX의 파이프 기능을 구현하는 과제이다.

## Some Concepts

### IPC

Inter Process Communication의 약자로, 프로세스 간 데이터를 주고 받는 방식을 의미한다. 운영체제에서 제공하는 주요 IPC 방식으로 파일 시스템, 시그널, 소켓, 메세지 큐, 파이프, 공유 메모리 ... 등이 있다.

### 파일(FILE)

파일은 UNIX에서 사용하는 입출력 방식이자 데이터를 저장하는 형식이다. UNIX는 모든 정보와 장치를 파일로 조작하기 때문에, UNIX 시스템 내의 자원도 파일로서 접근할 수 있다.

### 파일 디스크립터(FD, File Descriptor)

UNIX에서 파일 또는 입출력 장치에 접근하는데 사용하는 식별자(identifier). 일반적으로 양의 정수값을 가지며, 0번은 표준 입력, 1번은 표준 출력, 2번은 표준 에러에 할당되어 있다. 

각 프로세스는 파일 디스크립터 테이블을 가지며, 이를 바탕으로 사용중인 파일을 관리한다.

UNIX는 사용자가 파일을 열거나 소켓을 생성하는 경우, 파일 디스크립터 테이블을 탐색하여, 사용하지 않는 FD의 가장 작은 값을 할당한다. 사용자는 해당 FD에 시스템 콜을 사용함으로써 해당 파일에 접근할 수 있다.
- 사용자는 시스템 콜을 사용하지 않고서는 파일에 접근할 수 없다.

### 파일 테이블(File Table)

파일 디스크립터 테이블이 프로세스 내부에서 파일을 관리하는 데 사용된다면, 파일 테이블은 시스템에서 파일을 관리하는데 사용된다. 파일 디스크립터 테이블과 유사하게, 프로세스가 `open()`과 같은 시스템 콜을 사용하여 파일을 열 때마다 항목이 하나씩 할당되고, `close()` 시스템 콜을 사용하면 항목을 해제한다.

### 아이노드(i-node)

UNIX에서 파일 시스템을 관리하기 위해 사용되는 자료구조. 파일의 속성을 가리키며, 모든 파일은 각자 1개의 아이노드를 가지고 있다. 하나의 파일은 데이터 영역과 아이노드 영역으로 구분된다. 프로세스는 파일의 아이노드 정보를 공유한다. 파일의 아이노드를 모아놓은 아이노드 테이블이 존재한다.

### 프로세스의 파일 접근

<img src = "./IMG_README/filesystem.png" width="60%" height="60%">

여러 개의 파일 디스크립터가 동일한 파일 테이블 엔트리를 가리킬 수 있고, 여러 개의 파일 테이블 엔트리가 동일한 아이노드를 가리킬 수 있다. 그림에서 3번 파일 디스크립터는 close 되었기에, 아무것도 가리키지 않는다.

1) 하나의 프로세스가 하나의 파일을 열었을 경우

<img src = "./IMG_README/1.png" width="60%" height="60%">

2) 서로 다른 프로세스가 동일한 하나의 파일을 열었을 경우

<img src = "./IMG_README/2.png" width="60%" height="60%">

프로세스마다 파일을 읽고 쓰는 위치가 다르므로, 파일 테이블 엔트리의 offset은 서로 다르지만, 아이노드 테이블 엔트리는 같다.

3) 하나의 프로세스가 하나의 파일에 대해 두 개의 파일 디스크립터를 가지는 경우

<img src = "./IMG_README/3.png" width="60%" height="60%">

`dup()` 시스템 콜은 위와 같이 파일 디스크립터를 복사한다. 가령 `P > A`와 같이, 프로그램 P의 결과값을 FD 1번 표준 출력에서 리다이렉션(redirection) 하여 프로그램 A에 출력을 하도록 설정하는 것처럼, `A = dup(1)`을 사용하면 FD 1번이 가리키는 파일을 (사용되지 않은 가장 낮은 값인) FD 3번도 같이 가리키게 되어, 프로그램 A에 P의 표준 출력을 리다이렉션 할 수 있다. (뒤에서 좀 더 자세하게 후술할 예정.)

### 파이프(PIPE)

프로세스 간 통신을 위한 메모리 공간(버퍼)를 생성하여, 프로세스간 데이터 송수신을 처리한다.

과제에서는 부모-자식 프로세스 간 통신을 위한 **익명 파이프(Anonymous PIPE)**를 사용한다. 익명 파이프는 한쪽 방향으로만 통신이 가능하기에, 반이중(Half-Duplex) 통신의 특성을 가진다.

- `|` : 이전 명령어의 실행 결과를 다음 명령어로 전달한다.
- `&&` : 이전 명령어가 정상적으로 실행되었을 경우에만 결과를 다음 명령어로 전달한다.
- `<` : 저장소에 위치한 파일의 내용을 쉘에 연결한다.
- `>` : 프로그램의 실행 결과를 저장소의 파일에 저장한다.
- `>>` : 위 명령어와 다르게 저장소의 파일의 내용을 지우지 않고, 프로그램의 실행 결과를 저장소의 파일에 덧붙인다.

### `pipe()`

<img src = "./IMG_README/4.png" width="60%" height="60%">

```c
#include <unistd.h>

int	pipe(int fd[2]);
```

`pipe()` 사용 시, 배열로 두 개의 파일 디스크립터를 할당받는다. `fd[0]`은 input stream, `fd[1]`은 output stream으로 
작동한다. 부모 프로세스가 `fd[1]`에 write 한 데이터를, 자식 프로세스가 `fd[0]`으로 read 할 수 있다.

주의할 점으로, **각 프로세스에서 사용하지 않는 FD는 닫아야 한다**. write end가 닫히면, 이후 read는 EOF를 나타내는 0을 반환한다. read end가 닫히면, 이후 write는 SIGPIPE를 발생시킨다. 만약 write end가 닫히지 않는다면, read는 write가 EOF를 줄 때까지 계속 기다리게 된다. 반대로 read end가 닫히지 않는다면, write는 read가 write를 완료하기 위한 공간을 만들어 줄 때까지 계속 기다리게 된다(혹은 문제가 생기지 않는 것처럼 보이지만, read pipe가 닫힌 이후, write를 하는 일은 오류임에도, read end가 열려있다면 이를 오류로 처리할 수 없다).

참고 자료:
- [https://ko.wikipedia.org/wiki/%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4_%EA%B0%84_%ED%86%B5%EC%8B%A0](https://ko.wikipedia.org/wiki/%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4_%EA%B0%84_%ED%86%B5%EC%8B%A0)
- [https://ddongwon.tistory.com/16](https://ddongwon.tistory.com/16)
- [https://en.wikipedia.org/wiki/File_descriptor](https://en.wikipedia.org/wiki/File_descriptor)
- [https://en.wikipedia.org/wiki/Dup_(system_call)](https://en.wikipedia.org/wiki/Dup_(system_call))
- [https://dar0m.tistory.com/233](https://dar0m.tistory.com/233)
- [https://hyeonski.tistory.com/8](https://hyeonski.tistory.com/8)
- [https://m.blog.naver.com/nywoo19/221708412078](https://m.blog.naver.com/nywoo19/221708412078)
- [https://stackoverflow.com/questions/11599462/what-happens-if-a-child-process-wont-close-the-pipe-from-writing-while-reading](https://stackoverflow.com/questions/11599462/what-happens-if-a-child-process-wont-close-the-pipe-from-writing-while-reading)
