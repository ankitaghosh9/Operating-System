#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() 
{ 
    pid_t pid;
    int status;
    pid = fork(); 
    
    if(pid==-1)
        printf("Fork failed\n");
    else if(pid==0)
    {
        printf("in child: parent id %d\n",getppid());
        sleep(10);
        printf("in child: parent id %d\n",getppid());
        exit(0); 
    }
    else
    {
        //wait(&status);
        printf("in parent %d\n",getpid());
        //printf("child status %d\n", status);
    }        
    return 0; 
} 