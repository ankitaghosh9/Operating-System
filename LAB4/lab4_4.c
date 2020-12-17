#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	int ret; int ln; int uln;

	ret = stat(argv[1], &sb);

    if(argc==3)
    {
	
	   if(ret)
	    {
		  perror("stat");
	 	  return 1;
	    }
	    else
	    {
	        printf("Creating new soft link\n");
	    	ln=symlink(argv[1],argv[2]);
	    	if(ln)
	    	{
	    		perror("link");
	    		return 1;
	    	}

            printf("Unlinking\n");
            uln=unlink(argv[1]);
            if(uln)
	    	{
	    		perror("link");
	    		return 1;
	        }
        }
    }
    else
      printf("Invalid arguments");
}