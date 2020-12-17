#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	int i=-9;
	unsigned int ui=89;
	float f=2.345;
	double d=68354.65897406;
	char c='a';
	char s[]="hello";
	errno = EPERM;

	printf("Integer : %d\n",i);
	printf("Unsigned Integer : %u\n",ui);
	printf("Float : %f\n",f);
	printf("Double : %lf\n",d);
	printf("Char : %c\n", c);
	printf("String : %s\n",s);
    printf("Error NO. : %m\n");
	return 0;
}