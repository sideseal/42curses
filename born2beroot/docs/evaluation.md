# 평가 준비

## Debian을 설치한 이유

1. 가상머신 초보라 ㅎㅎ
2. 안정성을 매우 중시하는 리눅스 배포판(아무 패키지나 다루지 않는다)
3. 감동적인 오픈소스 정신

## apt vs. aptitude

모두 패키지 관리 도구. 하지만 aptitude가 좀 더 다양한 일들을 한번에 할 수 있다고 한다. 하지만 가상머신에서 그렇게 복잡한 패키기 관리를 할 일이 없을 것 같고, apt 관련 자료가 더 많아서 apt 사용.

## SELinux vs. AppArmor

SELinux는 설정이 복잡하지만, 그만큼 사용자가 보안을 위해 할 수 있는 일들이 많다.
AppArmor는 SELinux보다 직관적.

SELinux와 AppArmor는 모두 MAC 보안을 제공. 즉 보안 정책을 사용하여 프로세스의 행동을 제어한다.

SELinux는 주로 파일 시스템 단위로 보안 모델을 다루고, AppArmor는 주로 응용프로그램 단위로 보안 모델을 다루는 듯하다.

AppArmor는 Debian 10 이후 버전에 자동으로 깔려있음. (`aa-status`로 확인)

## 명령어들

### hostname 변경

```sh
hostnamectl set-hostname <machine-name>
```


