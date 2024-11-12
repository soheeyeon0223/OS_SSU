#define MAXCPROC 10
#define LASTPID (mainpid+MAXCPROC)
#include "types.h"
#include "stat.h"
#include "user.h"

int main (void) {
	int p;

	for (int i = 0; i< MAXCPROC; i++) {
		p = fork();

		if (p == 0) {
			int cpid = getpid();

			set_proc_priority(cpid, i%10+1);

			int pri = get_proc_priority(cpid);
			printf(1, "Process %d started with initial priority level: %d\n", cpid, pri);


			int t_start = uptime();
			int t_end;
			int t_elipsed;

			while(1) {
				int newpri = get_proc_priority(cpid);

				if(newpri != pri) {
					t_end = uptime();
					t_elipsed = t_end - t_start;
					printf(1, "Process %d priority updated from %d to %d after %d ticks\n", cpid, pri, newpri, t_elipsed);

					t_start = t_end;
				}
			pri = newpri;
			}
		}
	}

while(1);
}
