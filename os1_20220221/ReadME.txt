
<helloworld.c 소스코드 내용>

#include "types.h"   // 기본 데이터 타입 사용을 위해 필요 (정수형, 구조체 등)
#include "stat.h"    // 파일 시스템의 상태 관리를 위해 필요 (파일의 크기, 수정시간 등)
#include "user.h"    // 사용자 프로그램에서 사용할 함수들을 포함 (printf 함수 정의)

int main(int argc, char **argv){   // main 함수 정의, 인자 수와 배열을 받음
    printf(1, "Hello World\n");   // 터미널 상에서 "HelloWorld"를 출력
    exit();   // 프로그램 종료
}



<Makefile 소스코드 수정 내용>
상기 helloworld.c 컴파일을 위해 Makefile 내에 있는 UPROGS 부분과 EXTRA 부분에 각각 내용을 추가.

UPROGS=\
	_cat\
	_echo\
	_forktest\
	_grep\
	_init\
	_kill\
	_ln\
	_ls\
	_mkdir\
	_rm\
	_sh\
	_stressfs\
	_usertests\
	_wc\
	_zombie\
	_helloworld\   #추가사항


EXTRA=\
	mkfs.c ulib.c user.h cat.c echo.c forktest.c grep.c kill.c\
	ln.c ls.c mkdir.c rm.c stressfs.c usertests.c wc.c zombie.c\
	printf.c umalloc.c\
	README dot-bochsrc *.pl toc.* runoff runoff1 runoff.list\
	.gdbinit.tmpl gdbutil\
	helloworld.c\    #추가사항
