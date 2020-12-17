#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>


int main(int argc, char* argv[])
{

    
    DIR *thedirectory;
    struct dirent *thefile;
    struct stat thestat;

    char buf[512];

    thedirectory = opendir(argv[1]);

    while((thefile = readdir(thedirectory)) != NULL) 
    {
        if(S_ISDIR(thefile))
        {   
        sprintf(buf, "%s/%s", argv[1], thefile->d_name);
        stat(buf, &thestat);
        
        printf( (thestat.st_mode & S_IRUSR) ? " r" : " -");
        printf( (thestat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (thestat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (thestat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (thestat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (thestat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (thestat.st_mode & S_IROTH) ? "r" : "-");
        printf( (thestat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (thestat.st_mode & S_IXOTH) ? "x" : "-");
  
        printf("\t%ld ", thestat.st_nlink);

        printf("%zu",thestat.st_size);
        printf(" %s", thefile->d_name);
        printf(" %s", ctime(&thestat.st_mtime));
    }
}
    closedir(thedirectory);
}