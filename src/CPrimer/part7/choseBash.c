
#include"choseBash.h"

void choseSubject(int Subject)
{
	switch (Subject)
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
	case 11:
		Subject_11();
		break;
	default:
		printf("without this subject\n");
		break;

	}
	return;
}

void bashRunv1() {

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
	return;
}

void bashRunv2() {
	//bash here
	while (printf("[chose bash] Please enter a number of int to choose a subject(space/tab to quit):"))
	{
		char subject = 0;
		char tempBuffer[1024] = { 0 };

		scanf("%c", &subject);
		if ('\t' == subject || 32 == subject)
		{
			getchar();
			break;
		}
		else if ('\n' == subject)
		{
			continue;
		}
		else
		{

			char temp[1024] = { 0 };
			tempBuffer[0] = subject;
			//fgets(temp,1024,stdin);
			gets(temp);
			strcat(tempBuffer, temp);
			//printf("[DEBUG] : %s,%d\n",tempBuffer,strlen(tempBuffer));
			//all enter in temp,need segmentation
			memset(temp, 0x00, strlen(temp));
		}
		//choseSubject(atoi(subject)); atoi for string

		int subjkt = atoi(tempBuffer);
		if (subjkt)
			choseSubject(atoi(tempBuffer));
		else
			continue;
	}

	return;
}

