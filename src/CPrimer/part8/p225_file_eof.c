#include "example.h"
#include <stdio.h>	//FILE
#include <stdlib.h>

void getStreamFromFile(const char* FilePath) {
	int ch = 0;
	FILE* fp = NULL;

	fp = fopen(FilePath, "r");
	if (fp == NULL) {
		printf("Failed to open file. Bye\n");
		abort();
	}

	while ((ch = getc(fp)) != EOF)
		putchar(ch);
	fclose(fp);

	return;
}


void guess_number() {
	int guess = 1;
	printf("Pick an integer from 1 to 100.I will try to guess ");
	printf("it.\nRespond with a y if my guess is right and with");
	printf("\nan n if it is wrong.\n");
	printf("Uh...is your number %d?\n", guess);
	char response;
	while ((response = getchar()) != 'y') {
		if (response == 'n')
			printf("well, then, is it %d?\n", ++guess);
		else
			printf("Sorry, I understand only y or n.\n");

		while (getchar() != '\n')
			continue;
	}
	printf("I knew I could do it!\n");

	return;
}

void display(char cr, int lines, int width) {
	int row, col;
	for (row = 1; row <= lines; row++) {
		for (col = 1; col <= width; putchar(cr), ++col);
		putchar('\n');
	}
}

void showcahr2() {
	int ch;
	int rows, cols;

	printf("Enter a character and two intefers:\n");
	while ((ch = getchar()) != '\n') {
		if (scanf("%d %d", &rows, &cols) != 2)
			break;
		display(ch, rows, cols);
		while (getchar() != '\n')	//刷掉缓冲区
			continue;
		printf("Enter another character and two integers;\n");
		printf("Enter a newline to quit.\n");
	}
	printf("Bye.\n");

	return;
}


/*
	带验证的获取一个long
*/
long get_long(void) {
	long input;
	char ch;

	while (scanf("%ld", &input) != 1) {
		while ((ch = getchar()) != '\n')
			putchar(ch);	//处理错误输入
		printf(" is not an interger.\nPlease enter an interger value, such as 25, -178, or 3: ");
	}

	return input;
}

int get_int(void) {
	int input;
	char ch;

	while (scanf("%d", &input) != 1) {
		while ((ch = getchar()) != '\n'){
			putchar(ch);
		}
		printf(" is not an integer.\nPlease enter an ");
		printf("integer value, such as 25, -178, or 3: ");
	}

	return input;
}


/*
	验证输入范围
*/
bool bad_limit(bool isLog, long begin, long end, long low, long hight) {
	bool not_good = false;
	if (begin > end) {
		LOG(isLog, "%ld isn't smaller than %ld.\n", begin, end);
		not_good = true;
	}
	if (begin < low or end < low) {
		not_good = true;
		LOG(isLog, "Values must be %ld or greater.\n", low);
	}
	if (begin > hight or end > hight) {
		not_good = true;
		LOG(isLog, "Values must be %ld or less.\n", hight);
	}

	return not_good;
}

double sum_squares(long a, long b) {
	double total = 0;
	long i;

	for (i = a; i <= b; i++)
		total += (double)i * (double)i;

	return total;
}

void checking(void) {
	const long MIN = -10000000L; //low limit
	const long MAX = +10000000L; //high limit
	long start;			//user min
	long stop;			//user max
	double answer;

	printf("This program computes the sum of the squares of"
		"integers in a range.\nThe lower bound should not"
		"be less than -10000000 and\nthe upper bound "
		"limits (enter 0 for both limits to quit):\n"
		"lower limit: ");

	start = get_long();
	printf("upper limit: ");
	stop = get_long();
	while (start not_eq 0 or stop not_eq 0)
	{
		if (bad_limit(true, start, stop, MIN, MAX))
			printf("Please try again.\n");
		else
		{
			answer = sum_squares(start, stop);
			printf("The sum of the squares of the integers ");
			printf("from %ld to %ld is %g\n", start, stop, answer);
		}
		printf("Enter the limits (enter 0 for both "
			"limits to quit):\n");
		printf("lower limit: ");
		start = get_long();
		printf("upper limit: ");
		stop = get_long();
	}
	printf("Done.\n");

	return 0;
}

char get_first(void) {
	int ch;
	bool flag = false;
	do {
		ch = getchar();
		while (getchar() not_eq '\n')
			continue;

		if (flag = isspace(ch))
			LOG(true, "The charactor you input is invalid.\nPlease reinput a non-space charactor:");
		else
			break;
	} while (flag);

	return ch;
}

char get_choice(void) {
	int ch;

	printf("Enter the letter of your choice:\n");
	printf("a. advice			b.bell\n");
	printf("c. count			q.quit\n");
	//ch = getchar();
	ch = get_first();
	while ((ch <'a' or ch > 'c') and ch not_eq 'q') {
		printf("Please respond with a, b, c, or q.\n");
		ch = get_first();
	}
	return ch;
}

int count(void) {
	int n, i;
	printf("Count how far? Enter an integer:\n");
	n = get_int();
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
	while (getchar() != '\n')
		continue;
}

void do_choice(void) {
	int choice;

	while ((choice = get_choice()) != 'q') {
		switch (choice)
		{
		case 'a':
			printf("Buy low, sell high.\n");
			break;
		case 'b':
			putchar('\a');
			break;
		case 'c':
			count();
			break;
		default:
			printf("Program error!\n");
			break;
		}
	}
	printf("Bye.\n");

	return;
}



// unit test
void test() {
	//getStreamFromFile("./test/textFile.txt");
	//guess_number();
	//showcahr2();
	//checking();
	do_choice();

	return;
}