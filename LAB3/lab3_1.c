#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int status;
	pid=fork();

	switch(pid)
	{
		case -1:
		printf("Fork failed");
		break;

		case 0:
		for(int i=0;i<5;i++)
		{
			printf("%d inside child\n", i+1);
			sleep(1);
		}
		exit(0);

		default:
		wait(&status);
		printf("In parent\n");
		printf("Child status %d\n", status);

	}
	return 0;
}