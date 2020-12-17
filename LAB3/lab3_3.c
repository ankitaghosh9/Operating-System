#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	pid=fork();

	if(pid==-1)
		printf("Fork failed");
	else if(pid==0)
	{
		printf("in child process\n");
		printf("Child pid: %d\n",getpid());
		printf("Parent pid: %d\n",getppid());
		exit(0);
	}
	else
	{
		wait(NULL);
		printf("in parent process\n");
		printf("Child pid: %d\n",pid);
		printf("Current process pid: %d\n",getpid());
		printf("Parent pid: %d\n",getppid());
	}

	return 0;
}