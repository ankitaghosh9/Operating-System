#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	pid=fork();

	switch(pid)
	{
		case -1:
		printf("Fork failed");
		break;

		case 0:
		printf("%d\n", getpid());
		execlp("./lab3_1","lab3_1",NULL);
		//sleep(1);

		default:
        wait(NULL);
		//sleep(1);
		printf("Child complete\n");
		printf("%d\n", getpid());
		exit(0);

	}
	return 0;
}