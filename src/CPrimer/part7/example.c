#include "example.h"

void page_177() {
	const int FREEZING = 0;
	float temperature = 0.0f;
	int cold_days = 0;
	int all_days = 0;

	printf("Enter the list of daily low twmperatures.\n");
	printf("Use Celsius, and enter q to quit.\n");

	while (scanf("%f", &temperature) == 1) {
		all_days++;
		if (temperature < FREEZING)
			cold_days++;
	}

	if (all_days != 0)
		printf("%d days total: %.1f%% where below freezing.\n",
			all_days, 100.0 * (float)cold_days / all_days);
	if (all_days == 0)
		printf("No data entered!\n");

	return;
}


void page_181() {
	char ch = 0;
	//ch = getchar();
	//while (ch != '\n') {
	while(
		(ch = getchar()) 
						!= '\n'){
		if (ch == SPACE)
			putchar(ch);
		else
			putchar(ch + 1);;
	}
	putchar(ch);	//\n

	return;
}

#include <ctype.h>
void page_182() {
	char ch = 0;
	while (
		(ch = getchar())
						!= '\n') {
		if (isalpha(ch))
			putchar(ch + 1);
		else
			putchar(ch);
	}
	putchar(ch);//\n

	return;
}

#define RATE1 0.13230	//首次使用360kwh的费率
#define RATE2 0.15040	//接着再使用108kwh的费率
#define RATE3 0.30025	//接着再使用252kwh的费率
#define RATE4 0.34025	//使用超过720kwh的费率
#define BREAK1 360.0	//费率的第一个分界点
#define BREAK2 468.0	//费率的第二个分界点
#define BREAK3 720.0	//费率的第三个分界点
//使用360kwh的费用
#define BASE1 (SUB_RATE1 * BREAK1)
//使用468kwh的费用
#define BASE2 (BASE1 +(SUB_RATE2 * (BREAK2 - BREAK1)))
//使用720kwh的费用
#define BASE3 (BASE2 + BASE1 + (SUB_RATE3 * (BREAK3 - BREAK2)))

void page_184() {
	double kwh = 0.0F;
	double bill = 0.0F;

	printf("Please enter the kwh used.\n");
	scanf("%lf", &kwh);
	if (kwh <= BREAK1)
		bill = SUB_RATE1 * kwh;
	else if (kwh <= BREAK2)
		bill = BASE1 + SUB_RATE2 * (kwh - BREAK1);
	else if (kwh <= BREAK3)
		bill = BASE2 + SUB_RATE3 * (kwh - BREAK2);
	else
		bill = BASE3 + RATE4 * (kwh - BREAK3);

	printf("The charge for %.1f kwh is $%1.2f.\n", kwh, bill);

	return;
}

void page_188() {
	unsigned long num = 0ul;	//待测试的数
	unsigned long div[32] = { 0ul };	//可能的约数
	size_t div_num = 0;				//约数个数
	//bool _isPrime = false;		//素数标记

	while (printf("Please enter an integer for analysis;Enter q to quit.\n")) {
		if (scanf("%lu", &num) == 1) {
			if (isPrime(RUNTIME, num, div, &div_num))
				printf("%lu is prime.\n", num);
			else if (div_num == 1)
				printf("%lu is divisible by %lu.\n", num, div[0]);
			else
				for (size_t i = 0u; i < div_num; printf("%lu is divisible by %lu and %lu.\n", num, div[i++], div[i++]));
				
		}else{
			break;
		}
	}
	printf("Bye.\n");

	return ;
}

void page_192()
{
	char ch = 'b';
	if (ch == 'a' or ch == 'c')
		printf("it's not b\n");
	else
		printf("it's %c \n", ch);

	return;
}

void page_195()
{
	char ch = 0;
	size_t len = 0u;
	char* input = (char*)malloc(1024 * sizeof(char));
	memset(input, 0x00, 1024 * sizeof(char));
	word_info_t* info = NULL;

	printf("Enter text to be analyzed( | to terminate):\n");
	while ((ch = getchar()) != STOP) {
		input[len++] = ch;
	}
	input[len] = STOP;

	info = StatisticPart(input);

	printf("charactor = %u, words = %u, lines = %u, partial lines = %u\n", info->ch_num, info->word_num, info->line_num, info->partial_num);

	if (input)
		free(input);
	if (info)
		free(info);

}

void page_197() {
	int sq_feet;
	int cans;

	printf("Enter number of square feet to be painted:\n");
	while (scanf("%d", &sq_feet)) {
		cans = sq_feet / COVERAGE;
		cans += ((sq_feet % COVERAGE) == 0) ? 0 : 1;
		printf("you need %d %s of paint.\n", cans, cans == 1 ? "can" : "cans");
		printf("Enter next value (q to quit):\n");
	}

	return ;
}

void page_198() {
	const float MIN = 0.0f;
	const float MAX = 100.0f;

	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;

	printf("Enter the first score (q to quit):");
	while (scanf("%f", &score)) {
		if (score < MIN || score > MAX) {
			printf("%0.1f is an invalid value. Try again:", score);
			continue;
		}

		printf("Accepting %0.1f:\n", score);
		min = (score < min) ? score : min;
		max = (score > max) ? score : max;
		total += score;
		++n;
		printf("Enter next score (q to quit) :");
	}
	if (n > 0) {
		printf("Average of %d scores is %0.1f.\n", n, total / n);
		printf("Low = %0.1f, high = %0.1f\n", min, max);
	}
	else {
		printf("No valid score were entered.\n");
	}

	return ;
}