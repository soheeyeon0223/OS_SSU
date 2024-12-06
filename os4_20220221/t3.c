#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int p;

    printf(1, "Parent Process  PID : %d\n", getpid());
    printf(1, "Step1. (Parent) Before fork\n");
    printf(1, "Available free pages : %d\n\n", getNumFreePages());

    p = fork();

    if(p < 0){
        printf(1, "fork error\n");
    }
    else if(p > 0){
        wait();
        
        printf(1, "Step3. (Parent) After child process terminates\n");
        printf(1, "Available free page : %d\n\n", getNumFreePages());
    }
    else{
        printf(1, "Child Process PID : %d\n", getpid());
        printf(1, "Step 2: (Child) After fork\n");
        printf(1, "Available free pages: %d\n\n", getNumFreePages());
    }

    exit();
}
