#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
	int pid, priority1, priority2;

	pid = getpid();
	printf(1, "PID of the current process : %d\n", pid);

	priority1 = get_proc_priority(pid);
	printf(1, "Priority before setting - PID(%d) = %d\n", pid, priority1);

	set_proc_priority(pid, 10);
	priority2 = get_proc_priority(pid);
	printf(1, "Priority after setting - PID(%d) = %d\n", pid, priority2);

	exit();
}



