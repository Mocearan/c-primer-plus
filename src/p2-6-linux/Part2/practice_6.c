#include<stdio.h>


void Print()
{
	printf("Smile!");
}

int main(void)
{
	int i=3;
	while(i)
	{
		int j=0;
		while(i-j)
		{
			Print();
			++j;
		}
		printf("\n");
		--i;
	}
	return 0;
}
