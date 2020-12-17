#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <fcntl.h>


void print_lines(int argc,char *argv[])
{
	int fd,r,j=0;
	int lineno=0; char temp,line[100];
	int count;
	for(int i=1;i<argc;i++)
	{
	   if((fd=open(argv[i],O_RDONLY)) != -1)
       {
       	printf("Filename: %s\n",argv[i]);
       	count=0;
        while((r=read(fd,&temp,sizeof(char)))!= 0)
        {
            if(temp!='\n')
            {
                line[j]=temp;
                j++;
            }
            else
            {
                lineno++; count++;
                line[j]='\0';
                if(lineno%20==0)
                {
                  printf("%d\t%s\n",count,line);
                  printf("Enter a key to see more lines: ");
                  char c = getchar();

                }
                else
                {
                  printf("%d\t%s\n",count,line);
                }
                memset(line,0,sizeof(line));
                j=0;

            }

        }
      }   
	}
}

int main(int argc,char *argv[])
{
    print_lines(argc,argv);
}