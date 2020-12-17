#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>

void printdir(char *dir, int depth) {
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "cannot open dir: %s\n", dir);
		return;
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name, &statbuf);
		if(!S_ISDIR(statbuf.st_mode)) 
		{
			printf("%s\t%ld\n",entry->d_name,statbuf.st_ino);

		}	
	}
	chdir("..");
	closedir(dp);
}

int main(int argc, char* argv[]){
	if(argc != 2) {
		printf("Invalid args. Only enter required directory.");
	}
	printdir(argv[1], 0);
	return 0;
}