#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() 
{ 
    pid_t pid;
    pid = fork(); 
    
    if(pid==-1)
        printf("Fork failed\n");
    else if(pid==0)
    {
        printf("in child %d\n",getpid());
        exit(0); 
    }
    else
    {
        sleep(10);
        printf("in parent %d\n",getpid());
    }        
    return 0; 
} 