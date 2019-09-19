#include "subject.h"

void sub1_service(const stream_t* path) {
	char ch;
	size_t count = 0;
	FILE* fp = fopen(path->stream, "r");

	if (fp == NULL) {
		printf("Failed to open file [%s]. reinput.\n", path->stream);
		//abort();
		return;
	}

	while ((ch = getc(fp)) != EOF)
		++count;
	fclose(fp);

	printf("The number of charactor is %d in your file [%s].\n", count, path->stream);

	return;
}
void Subject_1(void) {
	// test : 
	//		./test/textFile.txt

	const char* tips = "[1] please enter the path of your file.(space/tab to quit):";
	
	subjectBash(tips, sub1_service);
	return;
}

void sub2_bytes_done(char ch, size_t* count) {

	if (ch >= SPACE) //字符输出
		printf("%c ", ch);
	else if (ch == '\n' || ch == '\t')//换行符和制表符输出
		printf("%s", ch == '\n' ? "\\n" : "\\t");
	else //一般控制字符
		printf("^%c", ch + CTRL);
	printf("%-5d", ch);
	if (ch == '\n')
		*count = 0;
	if ((*count)%COL == 0)//10对换行
		printf("\n");

	return;
}
void sub2_service(const stream_t* input) {
	char ch;
	size_t count = 0;
	char* pInput = input->stream;
	while (*pInput != '\0') {
		++count;
		sub2_bytes_done(*pInput, &count);
		++pInput;
	}
	printf("\\n10");
	printf("\n");

	while ((ch = getchar()) != EOF) {
		++count;

		if (ch >= SPACE) //字符输出
			printf("%c ", ch);
		else if (ch == '\n' || ch == '\t')//换行符和制表符输出
			printf("%s", ch == '\n' ? "\\n" : "\\t");
		else //一般控制字符
			printf("^%c", ch + CTRL);
		printf("%-5d", ch);
		if (ch == '\n')
			count = 0;
		if (count%COL == 0)//10对换行
			printf("\n");
	}
	printf("%c\n", ch);

	return;
}
void Subject_2(void) {
	const char * tips = "[2] please enter a text string. EOF to end input.(space/tab to quit):\n";

	subjectBash(tips, sub2_service);

	return;
}

void checking_ch(char ch, size_t* lo, size_t* up) {
	if (islower(ch))
		++*lo;
	if (isupper(ch))
		++*up;
}
void sub3_service(const stream_t* input) {
	size_t n_lower = 0, n_upper = 0;
	char ch;
	char* pInput = input->stream;
	while (*pInput != '\0') {
		checking_ch(*pInput, &n_lower, &n_upper);
		++pInput;
	}

	while ((ch = getchar()) != EOF)
		checking_ch(ch, &n_lower, &n_upper);

	printf("lower:[ %d ], upper: [ %d ]\n", n_lower, n_upper);

	return;
}
void Subject_3(void) {
	const char * tips = "[3] please enter a text string include Upper and Lower charactor. EOF to end input.(space/tab to quit):\n";

	subjectBash(tips, sub3_service);

	return;
}

void sub4_checking_ch(char ch, size_t* chars, bool* inword, size_t* words) {
	if (not isspace(ch) and not ispunct(ch))
		++*chars;
	if (not isspace(ch) and not ispunct(ch) and not *inword) {
		*inword = true;
		++*words;
	}
	if (isspace(ch) or ispunct(ch) and *inword) 
		*inword = false;

	return;
}
void sub4_service(const stream_t* input) {
	size_t chars = 0, words = 0;
	bool inword;
	char ch;
	char* pInput = input->stream;
	while (*pInput not_eq '\0') {
		sub4_checking_ch(*pInput, &chars, &inword, &words);
		++pInput;
	}

	while ((ch = getchar()) != EOF)
		sub4_checking_ch(ch, &chars, &inword, &words);
	++words;
	printf("There are %d words and %d letters\n", words, chars);
	printf("The average number of letters of each word is %.2f.\n", ((double)chars / (double)words));

		return;
}
void Subject_4(void) {
	const char * tips = "[4] please enter a text string. EOF to end input.(space/tab to quit):\n";

	subjectBash(tips, sub4_service);
}

void guess_initor(guess_t* guess) {
	memset(guess, 0x00, sizeof(guess));
	guess->lower = 0;
	guess->upper = 100;
	guess->guess = (guess->lower + guess->upper) / 2;

	return;
}
guess_t* create_guess() {
	guess_t* guess = (guess_t*)malloc(sizeof(guess_t));
	guess_initor(guess);
	return guess;
}
void guess_destroy(guess_t* guess) {
	if (guess) {
		free(guess);
		guess = NULL;
	}
}
void sub5_checking_ch(char ch, guess_t* guess) {
	if (ch == 's') {
		guess->lower = guess->guess;
		guess->guess = (guess->guess + guess->upper) / 2;
	}
	else if (ch == 'b') {
		guess->upper = guess->guess;
		guess->guess = (guess->guess + guess->lower) / 2;
	}
	else
		printf("Sorry, I understand only y,s,and b.\n");
	printf("Well, then, is it %d?", guess->guess);

	if (guess->guess == 99)
		guess->guess++;

	return;
}
void sub5_service(const stream_t* input) {
	char response = 0;
	char* pInput = input->stream;

	guess_t* guess = create_guess();
	//printf("Is your number %d?\n",guess->guess);
	sub5_checking_ch(*pInput, guess);

	while ((response = getchar()) != 'y') {
		sub5_checking_ch(response, guess);

		while (getchar() != '\n')
			continue;
	}
	printf("I knew i could do it!\n");
	guess_destroy(guess);
	return;
}
void Subject_5(void) {
	const char* tips = "[5] Pick an integer from 1 to 100.\nRespond with a y if guess is right, with an s if it is small and with a b if it is big.\nI will try to guess it:(space/tab to quit):\nIs your number 50?";

	subjectBash(tips, sub5_service);
	return;
}

char get_first1(void) {
	char ch;
	while (isspace(ch = getchar()))
		continue;
	while (getchar() != '\n')
		continue;

	return ch;
}
void sub6_service(const stream_t* input) {
	if (*input->stream != EOF) {
		putchar(*input->stream);
		printf("\n");
	}
	char ch;
	while ((ch = get_first1()) != EOF) {
		putchar(ch);
		printf("\n");
	}
}
void Subject_6(void) {
	const char* tips = "[6] test get_first:";
	
	subjectBash(tips, sub6_service);
	return;
}


void Subject_7(void) {
	printf("第七章代码都丢了还改啥呀！！！！！！！\n");
	return;
}

char get_choice1(stream_t* input, bool* fg) {
	int ch;
	if (*fg) {
		ch = *input->stream;
		*fg = false;
	}
	else {
		const char* tips = "**********************************************************\n*\t1. add\t\t\t2. substract\n*\t3. multiply\t\t4. divide\n*\tq. quit\n***********************************\n(space/tab to quit):";
		printf("%s", tips);
		ch = get_first1();
	}
	while ((ch < '1' or ch > '4') and ch not_eq 'q') {
		printf("Please respond with 1, 2, 3, 4 and q:");
		ch = get_first1();
	}

	return ch;
}
double_t get_float(void) {
	double_t input;
	char ch;

	while (scanf("%lf", &input) != 1) {
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an number.\n");
		printf("Please enter a number, such as 2.3, -1.78, or 3: ");
	}
	while (getchar() != '\n')
		continue;
	return input;
}
void chose_bash_done(stream_t* input) {
	int choice;
	double_t num1, num2;
	bool flag = true;

	while ((choice = get_choice1(input, &flag)) != 'q') {
		printf("Enter first number: ");
		num1 = get_float();
		printf("Enter second number: ");
		num2 = get_float();
		switch (choice)
		{
		case '1':
			printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
			break;
		case '2':
			printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
			break;
		case '3':
			printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
			break;
		case '4':
			if (!num2) {
				printf("Enter a number other than 0: ");
				num2 = get_float();
			}
			printf("%.2f / %.2f = %.2f\n",num1, num2, num1 / num2);
			break;
		default:
			printf("Program error!\n");
			break;
		}
	}
	printf("Bye.\n");
}
void sub8_service(stream_t* input) {
	chose_bash_done(input);
}
void Subject_8(void) {
	const char* tips = "**********************************************************\n*\t1. add\t\t\t2. substract\n*\t3. multiply\t\t4. divide\n*\tq. quit\n***********************************\n(space/tab to quit):";

	subjectBash(tips, sub8_service);
	return;
}