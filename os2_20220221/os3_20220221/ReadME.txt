# 과제 목적
scheduler 함수를 수정하고, 우선 순위 개념을 이용해 시스템 콜을 구현하여
선점형 방식의 우선 순위 스케줄링 시스템을 구현

# 작성 및 수정 파일
1. 새로 작성한 파일
1-1. test2.c
새로 추가한 시스템 콜을 테스트

1-2. t1.c, t2.c
구현한 스케줄러를 테스트


2. 수정 파일
2-1. Makefile
test2.c, t1.c, t2.c의 실행을 위해 해당 파일 추가

2-2. syscall.h
proc.c에 새로 구현한 네 개의 시스템 콜 정의
#define SYS_get_proc_priority 22
#define SYS_set_proc_priority 23
#define SYS_get_proc_isconst  24
#define SYS_set_proc_isconst  25

2-3. syscall.c
아래 항목 추가
[SYS_get_proc_priority]   sys_get_proc_priority
[SYS_set_proc_priority]   sys_set_proc_priority
[SYS_get_proc_isconst]  sys_get_proc_isconst
[SYS_set_proc_isconst]  sys_set_proc_isconst

2-4. proc.c
네 개의 시스템 콜 구현 및 fork, allocproc 함수 수정
get_proc_priority
set_proc_priority
get_proc_isconst
set_proc_isconst

2-5. proc.h
아래 항목 추가
int priority;
int isconst;
int runcount[10];

2-6.usys.S
아래 항목 추가
SYSCALL(get_proc_priority)
SYSCALL(set_proc_priority)
SYSCALL(get_proc_isconst)
SYSCALL(set_proc_isconst)

2-7. defs.h
proc.c 하단에 구현한 시스템 콜 추가

2-8. sysproc.c
구현한 시스템 콜에 대한 wrapper 함수 정의

2-9. param.h
NPCU 인자 값을 1로 변경

2-10. user.h
시스템 콜 부분에 아래 항목 추가
int get_proc_priority(int);
void set_proc_priority(int, int);
int get_proc_isconst(int);
void set_proc_isconst(int, int);







