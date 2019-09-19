#include<stdio.h>
#include<string.h>

int print(char ch)
{
	int ret=0;
	if(ret=printf("%c",ch))
		;

	return ret;
}

int main()
{
	char c;

	while(printf("please enter a charactor,(space/double enter/tab to quit):"))
	{
		if(scanf("%c%*[^\n]%*c",&c)==0)
		{
			fflush(stdin);
			printf("enter err!\n");
			continue;
		}
		//getchar();
		
		if('\t'==c||'\n'==c||32==c)
		{
			break;
		}
		for(int i=0;i<4;printf("\n"),++i)
			for(int j=0;j<8;printf("%c",c),++j)
				;
	}

	return 0;
}
