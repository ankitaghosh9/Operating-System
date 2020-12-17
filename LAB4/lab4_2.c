#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	int ret;

	ret = stat(argv[1], &sb);

    if(argc==2)
    {
	
	   if(ret)
	    {
		  perror("stat");
	 	  return 1;
	    }
	    else
	    {
	    	printf("ID of device: %ld\n",sb.st_dev);
	    	printf("Inode number: %ld\n",sb.st_ino);
	    	printf("Permissions: %d\n",sb.st_mode);
	    	printf("No. of hard links: %ld\n",sb.st_nlink);
	    	printf("User ID: %d\n",sb.st_uid);
	    	printf("Group ID: %d\n",sb.st_gid);
	    	printf("Device ID (special file): %ld\n",sb.st_rdev);
	    	printf("Total size: %ld bytes\n",sb.st_size);
	    	printf("Block size: %ld\n",sb.st_blksize);
	    	printf("No. of blocks: %ld\n",sb.st_blocks);
	    	printf("Last access time: %ld\n",sb.st_atime);
	    	printf("Last modification time: %ld\n",sb.st_mtime);
	    	printf("Last status change time: %ld\n",sb.st_ctime);

	    }
    }
    else
      printf("Invalid arguments");
}