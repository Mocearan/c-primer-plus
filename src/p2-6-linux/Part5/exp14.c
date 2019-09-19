#include <stdio.h>

int main(void)
{
	
	char ch;
	int i;
	float f;

	f = i = ch = 'C';
	printf("ch = %c , i = %d , f = %2.2f\n",ch,i,f);

	ch = 1107;
	printf("ch = %c\n",ch);//%256
	ch = 80.89;
	printf("ch = %c\n",ch);
	return 0;
}
