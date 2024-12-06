#과제 목적
xv6에 없는 Copy-on-Write (CoW) 기능을 구현하고 실행하기

#작성 및 수정 파일
1. 새로 작성한 파일
1-1. t3.c
CoW을 테스트 하기 위한 파일

2. 수정 파일
2-1. Makefile
t3.c의 실행을 위해 해당 파일 추가

2-2. syscall.h
#define SYS_getNumFreePages 22 추가

2-3. syscall.c
아래 항목 추가
extern int sys_getNumFreePages(void);
[SYS_getNumFreePages]  sys_getNumFreePages

2-4. user.h
아래 항목 추가
int getNumFreePages(void);

2-5. usys.S
아래 항목 추가
SYSCALL(getNumFreePages)

2-6. defs.h
아래 항목 추가
int		getNumFreePages(void);
uint		get_refcount(uint pa);
void		inc_refcount(uint pa);
void		dec_refcount(uint pa);
void		pagefault(void);

2-7. kalloc.c
과제 명세에 맞춰 변수 선언 및 여러 함수 수정
uint pgrefcount[PHYSTOP >> PTXSHIFT];
uint num_free_pages;
int getNumFreePages(void);
uint  get_refcount(uint pa);
void inc_refcount(uint pa);
void dec_refcount(uint pa);
page reference count
free pages
+ 다수의 함수 수정

2-8. trap.c
page fault 관련 추가

2-9. vm.c
copyuvm 함수 수정 및 pagefault 함수 정의





