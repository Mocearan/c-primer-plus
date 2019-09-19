#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<math.h> //use -lm in gcc

/**
* compile : gcc -o pra.exe pra.c -lm
*/






int print(char ch)
{
	int ret=0;
	if(ret=printf("%c",ch))
		;

	return ret;
}

void Subject_1(void)
{
	//char arr[26] = { 'a' }; err init , only [char] arr can be init for ['0']
	char arr[26];
	printf("[subject 1]\n");
	for(int i = 0; i<26 ; ++i)
	{
		arr[i] ='a'+i;
		printf("%c ",arr[i]);
	}
	printf("\n");

}

#include<stdbool.h>
void Subject_2(void)
{
	char ch;
	char tempBuffer[1024] = {0};

	while(printf("[2] please enter a charactor(space/tab to quit):"))
	{
		scanf("%c",&ch);

		if('\t'==ch||32==ch)
		{       
			getchar();
			break;
		}
		else if('\n' == ch)
		{
			continue;
		}
		else
		{
			char temp[1024]={0};
			tempBuffer[0] = ch;
			gets(temp);
			strcat(tempBuffer,temp);
//			printf("%s\n",tempBuffer);
			memset(temp,0x00,sizeof(temp));
		}

		printf("[subject 2]\n");
		for(int i=0;i<5;printf("\n"),++i)
			for(int j=0;j<=i;printf("%s",tempBuffer),++j)
				;
		memset(tempBuffer,0x00,sizeof(tempBuffer));
	}

	return;
}


void Subject_3(void)
{
	char ch;
	while(printf("[3] please enter a charactor(space/tab to qut):"))
	{
		scanf("%c",&ch);
		if('\t' == ch || 32 == ch)
		{
			getchar();
			break; 
		}
		else if('\n' == ch)
		{
			continue;
		}
		else
		{
			char* temp;
			gets(temp);
			memset(temp,0x00,sizeof(temp));
		}

		printf("[subject 3]\n");
		if(65>ch || (90<ch && 97>ch) ||122<ch)
			continue;
		else if(90 > ch)
			for(int i = 0;i<=ch-65;printf("\n"),++i)
				for(int j=0;j<=i;printf("%c",ch-j),++j)
					;
		else
			for(int i = 0;i<=ch-97;printf("\n"),++i)
				for(int j=0;j<=i;printf("%c",ch-j),++j)
					;
	}
	return;
}

void Subject_4(void)
{
	char ch;      

	while(printf("[4] please enter a charactor(space/tab to qut):"))
	{
		scanf("%c",&ch);

		if('\t' == ch || 32 == ch)
		{       
			getchar();
			break; 
		}
		else if('\n' == ch)
		{
			continue;
		}
		else{
			gets();
		}

		printf("[subject 4]\n");
		if(65>ch || (90<ch && 97>ch) ||122<ch)
			continue;
		else if(91 > ch)
			for(int i = 0;;printf("\n"),++i)
				//for(int j=0;j<=i;printf("%c",ch+i+j),++j)
			{
				if(ch>90) break;
				for(int j=0;j<=i;printf("%c",ch++),++j)
					if(ch>90) break;
			}
		else
			for(int i = 0;;printf("\n"),++i)
			{
				if(ch>122) break;
				for(int j=0;j<=i;printf("%c",ch++),++j)
					if(ch>122) break;
			}

	}
	return;
}

void Subject_5(void)
{
	char ch;
	int lineNum=0;

	while(printf("[5] please enter a charactor(space/tab to quit):"))
	{
		scanf("%c",&ch);

		if('\t' == ch || 32 == ch)
		{
			getchar();
			break;
		}
		else if('\n' == ch){
			continue;
		}
		else 
			gets();

		if(65>ch || (90<ch && 97>ch) ||122<ch){
			printf("[debug: continue to while\b]");
			continue;
		}
		else
		{

			printf("please enter a number of int to set line number:");
			if(0 == scanf("%d%*[^\n]%*c",&lineNum))
			{
				printf("enter err!re-enter!\n");
				scanf("%*[^\n]%*c");
				continue;
			}
			//getchar();

			if(91 > ch){
				for(int i =0;i<lineNum;++i)
				{
					if(ch+i>90)
					{
						lineNum=i;
						break;
					}
				}
				for(int i = 0;i<lineNum;printf("\n"),++i)
				{
					for(int j=0;j<lineNum-i-1;printf(" "),++j)
						;
					for(int j=0;j<i+1;printf("%c",ch+j),++j)
						;		
					for(int j=0;j<i;printf("%c",ch+i-j-1),++j)
						;
				}
			}
			else{
				for(int i =0;i<lineNum;++i)
				{
					if(ch+i>122)
					{
						lineNum=i;
						break;
					}
				}
				for(int i = 0;i<lineNum;printf("\n"),++i)
				{
					for(int j=0;j<lineNum-i-1;printf(" "),++j)
						;       
					for(int j=0;j<i+1;printf("%c",ch+j),++j)
						;	
					for(int j=0;j<i;printf("%c",ch+i-j-1),++j)
						;
				}
			}
		}
	}
	return;

}

void Subject_6(void)
{
	printf("[subject 6]\n");
	printf("get two num for tab start and end,print a tab include square and cube\n");
	printf("too simple to implement!\n");
}

void Subject_7(void)
{                       
	char cmd;                        
	char word[20];
	while(printf("[7] please enter a word(space/tab to quit):"))
	{  
		scanf("%c",&cmd);
		if('\t'==(cmd) || 32==(cmd ))
		{
			getchar();
			break;
		}
		else if('\n' == cmd)
			continue;
		else{
			char temp[1024];
			word[0]=cmd;
			gets(temp);// although have a worning for c99,but can ignore a \n
			//fgets(temp,1024,stdin); // safe,but have a \n for pint
			strcat(word,temp);
			memset(temp,0x00,strlen(temp));
		}

		printf("[subject 7]\n");
		for(int i=0;i<strlen(word);printf("%c",word[strlen(word)-i-1]),++i)
			;
		memset(word,0x00,sizeof(word));
		printf("\n");
	}
	return;        
}

#define MIN_VALUE 1e-8  //根据需要调整这个值
#define IS_DOUBLE_ZERO(d) (abs(d) < MIN_VALUE)

void Subject_8(void)
{
	char cmd;
	char stdinBuffer[1024]={0};
	while(printf("[8] please enter two number of float(tab/space to quit)"))
	{
		scanf("%c",&cmd);
		if('\t'==cmd || 32 == cmd)
		{
			getchar();
			break;
		}	
		else if('\n' == cmd){
			continue;
		}
		else{
			char temp[1024]={0};
			stdinBuffer[0]=cmd;
			//fgets(temp,1024,stdin);
			gets(temp);
			strcat(stdinBuffer,temp);
			//printf("[DEBUG]%s,%d\n",stdinBuffer,strlen(stdinBuffer));
			//all enter in temp,need segmentation
			memset(temp,0x00,strlen(temp));	
		}

		printf("[subject 8]\n");
		char first[1024]={0};
		char second[1024]={0};
		int i=0;
		for(;stdinBuffer[i]!=' '&&stdinBuffer[i]!='\0'; first[i]=stdinBuffer[i],++i)
			;
		for(int j=0;stdinBuffer[i+1]!='\0';second[j]=stdinBuffer[i+1],++i,++j)
			;
		double Fir = atof(first);
		double Sec = atof(second);
		printf("%lf,%lf\n",Fir,Sec);
		if(IS_DOUBLE_ZERO(Sec)){
			printf("The denominator is zero!\n");
			memset(stdinBuffer,0x00,sizeof(stdinBuffer));
			continue;
		}
		printf("%lf\n",(Fir-Sec)/(Fir*Sec));
		memset(stdinBuffer,0x00,sizeof(stdinBuffer));
	}
	return;
}

void Subject_9(void)
{
	printf("[subject 9]\n");
	printf("use a function encapsulate a procedure\n");
	printf("it's too easy to implement");
}

void getTwoFloat(const char* stdinBuffer,double* outFir,double* outSec)
{
	char InFir[1024]={0};
	char InSec[1024]={0};
	int i=0;
	for(;stdinBuffer[i]!=' '&&stdinBuffer[i]!='\0'; InFir[i]=stdinBuffer[i],++i)
	printf("111\n");
		;       
	for(int j=0;stdinBuffer[i+1]!='\0';InSec[j]=stdinBuffer[i+1],++i,++j)
		;
	*outFir = atof(InFir);
	*outSec = atof(InSec);
}

double mySquare(double inDouble)
{
	return inDouble*inDouble;
}


void Subject_10(void)
{
	char cmd;
	char stdinBuffer[1024]={0};
	while(printf("[10] please enter two number of float(tab/space to quit)"))
	{
		scanf("%c",&cmd);
		if('\t'==cmd || 32 == cmd)
		{
			getchar();
			break;
		}	
		else if('\n' == cmd){
			continue;
		}
		else{
			char temp[1024]={0};
			stdinBuffer[0]=cmd;
			//fgets(temp,1024,stdin);
			gets(temp);
			strcat(stdinBuffer,temp);
			//printf("[DEBUG]%s,%d\n",stdinBuffer,strlen(stdinBuffer));
			//all enter in temp,need segmentation
			memset(temp,0x00,strlen(temp));	
		}

		printf("[subject 10]\n");
		double Fir,Sec;
		getTwoFloat(stdinBuffer,&Fir,&Sec);
		printf("%lf,%lf\n",Fir,Sec);
		if(IS_DOUBLE_ZERO(Sec)){
			printf("The denominator is zero!\n");
			memset(stdinBuffer,0x00,sizeof(stdinBuffer));
			continue;
		}

		double sum = 0;
		for(int i=0;(int)ceil(Fir)+i < (int)floor(Fir);sum+=mySquare(ceil(Fir)+i),++i)
			;
		printf("The sum of the square from %lf to %lf is %lf : ",Fir,Sec,sum);
		printf("\n");
		memset(stdinBuffer,0x00,sizeof(stdinBuffer));
	}
}

void choseSubject(int Subject)
{
	switch(Subject)
	{
		case 1:
			Subject_1();
			break;
		case 2:
			Subject_2();
			break;
		case 3:
			Subject_3();
			break;
		case 4:
			Subject_4();
			break;
		case 5:
			Subject_5();
			break;
		case 6:
			Subject_6();
			break;
		case 7:
			Subject_7();
			break;
		case 8:
			Subject_8();
			break;
		case 9:
			Subject_9();
			break;
		case 10:
			Subject_10();
			break;
		default:
			printf("without this subject\n");
			break;			

	}
	return;
}

int main()
{
	//char c;

	/*
	   while(printf("please enter a charactor,(space/double enter/tab to quit):"))
	   {
	   if(scanf("%c%*[^\n]%*c",&c)==0)
	   {
	   fflush(stdin);
	   printf("enter err!\n");
	   continue;
	   }
	   getchar(); // get '\n'

	   if('\t'==c||'\n'==c||32==c)
	   {
	   break;
	   }
	   for(int i=0;i<4;printf("\n"),++i)
	   for(int j=0;j<8;printf("%c",c),++j)
	   ;
	   }
	 */

	//bash here
	while(printf("[chose bash] Please enter a number of int to choose a subject(space/tab to quit):"))
	{
		char subject = 0;
		char tempBuffer[1024]={0};

		scanf("%c",&subject);
		if('\t'==subject || 32 == subject)
		{
			getchar();
			break;
		}
		else if('\n'==subject)
		{
			continue;
		}
		else
		{

			char temp[1024]={0};
			tempBuffer[0]=subject;
			//fgets(temp,1024,stdin);
			gets(temp);
			strcat(tempBuffer,temp);
			//printf("[DEBUG] : %s,%d\n",tempBuffer,strlen(tempBuffer));
			//all enter in temp,need segmentation
			memset(temp,0x00,strlen(temp));
		}





		//choseSubject(atoi(subject)); atoi for string
		
		int subjkt= atoi(tempBuffer);
		if(subjkt)
			choseSubject(atoi(tempBuffer));
		else
			continue;
	}

	return 0;
}
