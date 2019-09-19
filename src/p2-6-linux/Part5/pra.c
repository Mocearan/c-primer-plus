#include<stdio.h>

/*********************
* practice 1
********************/
#define SECOND_PER_MIN 60.0

void pra_1(void)
{
	float hours = 0.0;
	float minutes = 0.0;
	float seconds = 0.0;
	
	printf("input minutes(<=0 to quit):");
	//scanf_s("%d",&minutes); vs下提供的安全输入，可以指定边界
	scanf("%f",&minutes);

	while(minutes>0)
	{
		getchar();
		hours = (float)minutes/SECOND_PER_MIN;
		seconds = minutes*SECOND_PER_MIN;
		printf("%.2f minutes = %.2f hours or %.2f seconds\n",minutes,hours,seconds);
	
		
		printf("input minutes(<=0 to quit):");
		scanf("%f",&minutes);
	}

	return;
}

void pra_2()
{
	int input = 0;

	printf("please input a integer number:");
	scanf("%d",&input);
	getchar();//get "\n"

	printf("the ten integers after %d are: \n",input);
	for(int i =0;i<=10;++i)
	{
		printf("%d\t",input++);
	}
	printf("\n");

	return;
}

void pra_3()
{
	int days=0;

	printf("please input the num of day\n");
	scanf("%d",&days);//for enter loop

	while(days)
	{
		printf("%d days are %d weeks and %d days\n",days,days/7,days%7);
		scanf("%d",&days);
	}
	
	return;
}

#define CM_PER_INCH 2.54f
#define CM_PER_FEET 30.38f
void pra_4()
{
	float heightCm = 0;
	int heightFeet = 0;
	float heightInch = 0;
	
	printf("Enter a height in centimeters: ");
	scanf("%f",&heightCm);
	getchar();

	while(heightCm)
	{
		heightFeet = (int)(heightCm/CM_PER_FEET);
		heightInch = (int)(heightCm/CM_PER_INCH);
		printf("%.1f cm = %d feet and %.1f inch \n",heightCm,heightFeet,heightInch);

		printf("Enter a height in centimeters: ");
		scanf("%f",&heightCm);
	}

	return;	
}

void pra_5(void)
{
	int count = 0,sum = 0;
	
	printf("work days:");
	scanf("%d",&count);
	/*while(count--)
	{
		sum+=count;
	}
	*/
	while(count)
	{
		do{
		sum+=count;
		}while(count--);
		printf("sum = %d\n",sum);
		sum = 0;

		printf("work days:");
		scanf("%d",&count);
	}
	return;
}

void pra_6(void)
{
        int count = 0,sum = 0;
        
        printf("work days:");
        scanf("%d",&count);
	getchar();
        
        /*while(count--)
        {
                sum+=count;
        }
        */
        while(count)
        {
                do{
          	      sum+=count*count;
                }while(count--);
                printf("sum = %d\n",sum);
                sum = 0;

                printf("work days:");
                scanf("%d",&count);

        }
        return;
}

#define SQUATR(x) (x)*(x)
double Cube(double x)
{
	return x*x*x;
}
void pra_7(void)
{
	double input = 0.0;
	printf("please enter a double number:");
	scanf("%lf",&input);
	getchar();
	
	while(input)
	{
		printf("cube of your num is %lf\n",Cube(input));
	
		printf("please enter a double number:");
		scanf("%lf",&input);
	}
	return;
}

int main(void)
{	
	//pra_1();
	//pra_2();
	//pra_3();
	//pra_4();
	//pra_5();
	//pra_6();
	pra_7();

	return 0;
}

