# 과제 목적
이미 존재하는 fork와 exec 시스템 콜을 결합하여 새로운 시스템 콜인 'forknexec' 구현
가상 메모리 시스템과 프로세스 설정 및 관리에 대한 이해


# 작성 및 수정 파일
1. 새로 작성한 파일
1-1. test.c
과제 명세에서 제시한 user application 포함
새로 만든 시스템 콜 테스트

2. 수정 파일
2-1. Makefile
test.c을 실행하기 위해 test.c와 _test 추가

2-2. syscall.h
#define SYS_forknexec 22 추가
syscall.c에서 사용

2-3. syscall.c
extern int sys_forknexec(void)와 [SYS_forknexec] sys_forknexec 추가

2-4. sysfile.c
sys_forknexec syscall 래퍼 함수 정의

2-5. usys.S
SYSCALL(forknexec) 추가

2-6. user.h
int forknexec(char*, char**) 추가

2-7. defs.h
//proc.c 하단에 int forknexec(char , char*) 추가

2-8. proc.c
forkexec 함수 정의
파일 최상단에 헤더 추가
proc.c에 추가한 소스코드의 길이가 가장 길고 복잡하기 때문에, 코드에 대한 설명은 주석처리 하였음

