#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	struct stat sb; int ln; int uln;
	int ret;

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
	    	printf("Creating new hard link\n");
	    	ln=link(argv[1],argv[2]);
	    	if(ln)
	    	{
	    		perror("link");
	    		return 1;
	    	}

            printf("Unlinking\n");
            uln=unlink(argv[2]);
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