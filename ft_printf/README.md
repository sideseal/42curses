# ft_printf

프로토타입:
```c
int	ft_printf(const char *, ...);
```
- 출력한 문자의 개수를 반환한다.
- 만약 에러가 발생할 경우, -1을 반환한다.

C언어의 `printf()` 작동방식을 구현하는 과제.
`libftprintf.a` 아카이브 파일도 함께 제출해야 한다.

기본적으로 다음의 서식을 구현해야 한다:

- `%c` : 문자 하나를 출력
- `%s` : 문자열을 출력
- `%p` : 포인터의 주소를 16진수로 출력
- `%d` : 숫자를 10진수로 출력
- `%i` : 10진수의 정수를 출력
- `%u` : 숫자를 양수의 10진수로 출력
- `%x` : 숫자를 소문자 16진수로 출력
- `%X` : 숫자를 대문자 16진수로 출력
- `%%` : % 문자를 출력

## 신경써야 할 점

- `%c`의 경우, 문자가 아닌 숫자가 들어오는 경우, 아스키코드로 인식해야 한다.
- `%s`에 NULL 포인터가 오는 경우도 처리해야 한다.
- `%p`에 NULL 주소가 들어오는 경우, `0x0`으로 출력해야 할 것 같다.
- `%i`와 `%d`는 `printf()`의 아웃풋에서는 차이가 없다고 한다.
- `printf()`는 함수를 버퍼에 저장했다가 한 번에 출력하는데, 이를 동일하게 구현해야 할 것 같다. (X)
	- 아니다, 프로젝트에서 버퍼 매니지먼트는 구현하지 말라고 한다.
- 반환 값이 INT_MAX 이상이면 -1을 반환한다고 한다...
- `va_arg`에 들어가는 바이트를 각 서식에 맞게 설정해주어야 한다.
	- `c, d, i` : `va_arg(ap, int)`
	- `u, x, X` : `va_arg(ap, unsigned int)`
	- `s, p` : `va_arg(ap, void *)`
		- 이 경우, `long long` 8바이트 값으로 설정한다.

## 가변 인자

헤더 파일 :
```c
#include <stdarg.h>
```
<br />

함수에서 가변 인자를 정의하기 위해선, 고정 매개변수가 하나 이상 있어야 하며, 고정 매개변수 뒤에 ...를 붙여 매개변수의 개수가 정해지지 않았다는 표시를 해야 한다.

- `va_start` : 가변 인자를 가져올 수 있도록 포인터를 설정.
	- 함수에 전달되는 인수는 `va_list` 형태여야 한다.
- `va_copy` : 현재 상태의 인수의 복사본을 만듬.
- `va_arg` : 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옴.
- `va_end` : 가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화.

코딩도장 예제:
```c
#include <stdio.h>
#include <stdarg.h>    // va_list, va_start, va_arg, va_end가 정의된 헤더 파일

void printNumbers(int args, ...)    // 가변 인자의 개수를 받음, ...로 가변 인자 설정
{
    va_list ap;    // 가변 인자 목록 포인터

    va_start(ap, args);    // 가변 인자 목록 포인터 설정
    for (int i = 0; i < args; i++)    // 가변 인자 개수만큼 반복
    {
        int num = va_arg(ap, int);    // int 크기만큼 가변 인자 목록 포인터에서 값을 가져옴
                                      // ap를 int 크기만큼 순방향으로 이동
        printf("%d ", num);           // 가변 인자 값 출력
    }
    va_end(ap);    // 가변 인자 목록 포인터를 NULL로 초기화

    printf("\n");    // 줄바꿈
}

int main()
{
    printNumbers(1, 10);                // 인수 개수 1개
    printNumbers(2, 10, 20);            // 인수 개수 2개
    printNumbers(3, 10, 20, 30);        // 인수 개수 3개
    printNumbers(4, 10, 20, 30, 40);    // 인수 개수 4개

    return 0;
}
```
<br />

## BONUS (X)

시간이 없어서 기본만 구현하였다...

참고자료:  
- [https://dojang.io/mod/page/view.php?id=577](https://dojang.io/mod/page/view.php?id=577)
- [https://docs.microsoft.com/ko-kr/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170](https://docs.microsoft.com/ko-kr/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170)
