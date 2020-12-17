#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


void printdir(char *dir) 
{
	DIR *dp;
	struct dirent *entry;
	struct stat sb;
	struct stat statbuf;
	int ret;

	if((dp = opendir(dir)) == NULL) 
	{
		fprintf(stderr, "cannot open dir: %s\n", dir);
		return;
	}
    
    ret=stat(dir,&sb);
    if(ret)
    {
    	perror("stat");
    	return;
    }
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
	printf("\n\n");


	chdir(dir);
	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);
		if(!S_ISDIR(statbuf.st_mode)) 
		{
			printf("%s\tInode number:%ld\n",entry->d_name,statbuf.st_ino);

		}	
	}
	chdir("..");
	closedir(dp);
}

int main(int argc, char* argv[])
{
	if(argc != 2) 
	{
		printf("Invalid args. Only enter required directory.");
	}
	printdir(argv[1]);
	return 0;
}