# Philosophers

## Overview

운영체제 과목에서 데드락 상태와 함께 자주 등장하는 문제. 다섯 명의 철학자가 원탁에 앉아 원탁 가운데에 놓인 스파게티를 먹는다. 철학자 한 명에게 포크 하나가 배정되고, 각각의 철학자는 다른 철학자와 이야기(정보 전달)를 할 수 없다(심지어 다른 철학자가 죽는지도 모른다!). 그리고 철학자는 스파게티를 먹기 위해선 포크 두 개를 사용해야 한다. 즉, 자신의 포크와 함께, 양 옆의 철학자 중 한 명의 포크를 사용해야 한다는 뜻. 모든 철학자들이 굶어죽지 않고(기아 상태에 빠지지 않고) 스파게티를 먹을 수 있도록 설계해야 한다.

철학자는 세 가지 행동을 가질 수 있다.
- 먹기(eat) : 두 개의 포크를 사용해서 스파게티를 먹는 상태. 먹기가 끝나면 철학자는 포크를 반납하고 잠에 빠진다.
- 생각하기(thinking) : 잠에서 깨어나 생각을 하는 상태. 생각하기가 끝난 다음 철학자는 먹기를 시작한다.
- 자기(sleep) : 잠에 빠지는 상태. 잠에서 깨어나면 철학자는 생각하기를 시작한다.

철학자가 굶어 죽을 경우, 시뮬레이션은 종료된다.

참고 : [https://namu.wiki/w/식사하는 철학자 문제](https://namu.wiki/w/%EC%8B%9D%EC%82%AC%ED%95%98%EB%8A%94%20%EC%B2%A0%ED%95%99%EC%9E%90%20%EB%AC%B8%EC%A0%9C)

## Rules

* 프로그램(`philo`)은 다음의 인자들을 처리해야 한다.
	- `number_of_philosophers` : 문제에서 처리해야 하는 철학자의 수. 철학자의 수는 포크의 개수와 동일하다.
	- `time_to_die` : 철학자가 마지막 식사를 한 후, milliseconds 단위의 시간인 `time_to_die`가 지나가기 전에 식사를 하지 못하면, 철학자는 굶어죽는다.
	- `time_to_eat` : 철학자가 식사를 하는데 걸리는 milliseconds 단위의 시간. 이 시간 동안 철학자는 두 개의 포크를 점유한다.
	- `time_to_sleep` : 철학자가 잠을 자는데 걸리는 milliseconds 단위의 시간.
	- `number_of_times_each_philosopher_must_eat` (optional argument) : 만약 모든 철학자들이 해당 인자로 들어온 수만큼 식사를 마치게 된다면 시뮬레이션이 종료되어야 한다.

* 철학자들은 번호 순서대로 원탁에 앉는다. (1 -> 2 -> 3 -> 4 -> 1)

* 철학자는 다음과 같은 형식의 로그를 남겨야 한다.
	```
	timestamp_in_ms X has taken a fork
	timestamp_in_ms X is eating
	timestamp_in_ms X is sleeping
	timestamp_in_ms X is thinking
	timestamp_in_ms X died
	```
	- `timestamp_in_ms`에는 milliseconds 단위로 나타낸 timestamp가 표시되어야 한다.
	- `X`는 해당 행위를 수행하는 철학자의 번호를 표시해야 한다.
	- 로그는 다른 메시지와 섞이면 안된다.
	- 철학자가 죽는 순간 나타나는 메시지는, 철학자가 실제로 죽는 시간보다 10 ms 이상 차이나면 안된다.

* 프로그램에서 데이터 레이스(data races)가 발생하면 안된다.
* 철학자는 쓰레드로 처리되어야 한다.

## 허용함수

### `usleep`

```c
#include <unistd.h>

int	usleep(useconds_t usec);
int	usleep(unsigned int usecs);
```

`usec` 마이크로 초동안 현재 동작중인 프로세스를 정지시킨다. `useconds_t`는 `unsigned int`로 대체하여 사용할 수 있다. `usecs`의 범위는 0에서 1000000(1초)까지 이다. 성공 시 0, 실패 시 -1을 반환한다.

### `gettimeofday`

```c
#include <sys/time.h>

int	gettimeofday(struct timeval *tv, struct timezone *tz);

struct timeval
{
	long	tv_sec;		// 초
	long	tv_usec;	// 마이크로 초
}
```

`tz` 구조체에 대해선 무시하고 NULL을 넣어주면 된다. 현재 시간을 초와 마이크로 초 단위로 얻는다. 성공 시 0, 실패 시 -1을 반환한다.

### `pthread_create`

```c
#include <pthread.h>

int	pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```

- `thread` : 성공적으로 함수가 호출되면, 해당 인자에 쓰레드 ID가 저장된다.
- `attr` : 쓰레드의 특성을 정의하는 인자로, NULL 전달 시 기본 값으로 쓰레드를 생성한다. 만약 쓰레드의 속성을 지정하려 하면, `pthread_attr_init` 등의 함수로 초기화해야 한다.
- `start_routine` : 어떤 로직을 할지 함수 포인터를 전달받는 인자.
- `arg` : `start_routine`에 전달되는 인자로, `start_routine` 함수에게 해당 인자를 전달한다. `start_routine`이 별도의 인자를 요구하지 않는 경우, NULL을 전달하면 된다.

컴파일할 때, `-pthread`를 링크해야 한다. 성공 시 0과 함께 `thread`에 쓰레도 ID를 저장, 실패 시 `thread`에 쓰레드 ID가 설정되지 않고, 0이 아닌 에러 코드가 반환된다.

main 함수가 끝나면 생성된 쓰레드도 함께 종료하게 되는데, 이를 방지하기 위해선 `pthread_join` 함수를 사용해야 한다.

### `pthread_join`

```c
#include <pthread.h>

int	pthread_join(pthread_t thread, void **retval);
```

- `thread` : join하고자 하는 쓰레드의 ID.
- `retval` : 해당 쓰레드의 작업(`start_routine`)이 반환하는 값을 저장한다. 반환하는 값을 저장하지 않아도 되는 경우, NULL을 전달한다.

생성된 쓰레드의 작업이 끝날 때까지 대기하는 함수. `wait / waitpid`와 비슷한 개념이라고 생각할 수 있을 것 같다. 성공 시 0, 실패 시 0이 아닌 값을 반환한다.

### `pthread_detach`

```c
#include <pthread.h>

int	pthread_detach(pthread_t thread);
```

join으로 쓰레드의 종료를 기다리지 않고, 쓰레드가 독립적으로 행동하고 알아서 끝내도록 설정한다. `pthread_join`과 `pthread_detach`를 동시에 사용할 수 없다.`pthread_deatch`로 실행되는 쓰레드는 종료 시, 자원을 자동으로 반환한다. `pthread_create`로 생성한 쓰레드는 자원을 자동으로 반환하지 않는다는 점을 기억하자. 함수 성공 시 0, 실패 시 0이 아닌 에러 넘버를 반환한다.

### `pthread_mutex_init`

```c
#include <pthread.h>

int	pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
```
