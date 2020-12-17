#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	int ret;

	if(argc == 2)
	{
		ret = stat (argv[1], &sb);
		if (ret)
		{
			perror("stat");
			return 1;
		}

		printf("Inode number: %ld\n",sb.st_ino);

	}
	else
		printf("Invalid arguements\n");
}