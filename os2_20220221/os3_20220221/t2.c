#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int p;
    const int MAXPROC = 10;

    for (int i = 0; i < MAXPROC; i++) {
        p = fork();
        if (p == 0) { // 자식 프로세스
            int cpid = getpid();
            int initial_priority = (i % 10) + 1; // 1 ~ 10의 우선순위로 설정
            set_proc_priority(cpid, initial_priority);

            printf(1, "Process %d started with initial priority %d\n", cpid, initial_priority);

            int exec_count = 0; // 프로세스 실행 횟수
            int t_start = uptime();
            int t_end, t_elapsed;

            while (exec_count < 5) { // 5번 우선순위 변경 확인
                int newpri = get_proc_priority(cpid);
                if (newpri != initial_priority) { // 우선순위가 변경되었을 경우
                    t_end = uptime();
                    t_elapsed = t_end - t_start;
                    printf(1, "Process %d priority changed from %d to %d after %d ticks\n",
                           cpid, initial_priority, newpri, t_elapsed);
                    initial_priority = newpri; // 현재 우선순위 업데이트
                    t_start = t_end;
                    exec_count++; // 실행 횟수 증가
                }
                // 간단한 작업 수행
                for (int j = 0; j < 1000000; j++) asm("nop"); // CPU 대기 작업
            }

            printf(1, "Process %d completed test with final priority %d\n", cpid, initial_priority);
            exit();
        }
    }

    // 부모 프로세스는 종료하지 않고 대기
    while (1);
}

