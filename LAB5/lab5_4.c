#include <stdio.h>
#include <stdlib.h>
 
int main()
{
  FILE *fptr;
  int num;
  int num1=0;
  char buf[50];char newbuf[50];
  fptr = fopen("demo.bin","wb+");
 
  printf("Enter input: \n");
  gets(buf);
 
   fwrite(buf, sizeof(char), 50, fptr); 
 
  printf("Write finished \n");
  fclose(fptr);
 
  fptr = fopen("demo.bin","rb");
 
    fread(newbuf, sizeof(char), 50, fptr); 
    printf("%s\n",newbuf);
  printf("Read finished\n");
}