#include<stdio.h>

void Jolly()
{
	printf("For he's jolly good fellow!\n");
}

void deny()
{
	printf("which nobody can deny!\n");
}

int main(void)
{
	int count=0;
	while(count<3)
	{
		Jolly();
		++count;
	}
	deny();

	return 0;
}
