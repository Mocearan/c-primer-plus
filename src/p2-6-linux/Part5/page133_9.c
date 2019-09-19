#include<stdio.h>

int main(void)
{
	char n='a'-1;
	while(n++<'g')
		printf("%-5c",n);
	printf("\n");	

	return 0;
}
