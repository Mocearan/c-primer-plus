#include "subject.h"

double_t _min(double_t x, double_t y) {
	return (x < y) ? x : y;
}
void sub1_service(const stream_t* stream) {
	double_t num1, num2;

	getTwoFloat(stream->stream, &num1, &num2);
	printf("The smaller ont is %lf\n", _min(num1, num2));

	return;
}
void Subject_1(void) {
	const char* tips = "[1] please enter two double number(space/tab to quit):";

	subjectBash(tips, sub1_service);
	return;
}

void chline(char ch, int i, int j) {
	int k = 0;
	while (i--) {
		while (k++ < j)
			putchar(ch);
		putchar('\n');
		k = 0;
	}
}
void sub2_service(const stream_t* stream) {
	int status;
	int row, col;
	char ch = stream->stream[0];
	printf("Please enter row:");
	row = getInteger();
	printf("Please enter col:");
	col = getInteger();

	chline(ch, row, col);

	return;
}
void Subject_2(void) {
	const char* tips = "[2] please enter a charactor(space/tab to quit):";

	subjectBash(tips, sub2_service);
	return;
}

void sub3_service(const stream_t* stream) {
	int status;
	int row, col;
	char ch = stream->stream[0];
	printf("Please enter row:");
	row = getInteger();
	printf("Please enter col:");
	col = getInteger();

	chline(ch, row, col);

	return;
}
void Subject_3(void) {
	const char* tips = "[3] please enter a charactor(space/tab to quit):";

	subjectBash(tips, sub3_service);
	return;
}

double_t har_avrg(double_t a, double_t b) {
	return 2*a*b / (a + b);
}
void sub4_service(const stream_t* stream) {
	double_t num1, num2;
	getTwoFloat(stream->stream, &num1, &num2);
	printf("The harmony average of %lf and %lf is %lf\n", num1, num2, har_avrg(num1, num2));
	return;
}

void Subject_4(void) {
	const char* tips = "[4] please enter two float number(space/tab to quit):";

	subjectBash(tips, sub4_service);
	return;
}


void larger_of(double_t* a, double_t* b) {
	(*a > *b) ? (*b = *a) : (*a = *b);
	return;
}
void sub5_service(const stream_t* stream) {
	double_t num1, num2;
	getTwoFloat(stream->stream, &num1, &num2);
	larger_of(&num1, &num2);
	printf("Now num1 is %lf , num2 is %lf\n", num1, num2);
	return;
}
void Subject_5(void) {
	const char* tips = "[5] please enter two float number(space/tab to quit):";

	subjectBash(tips, sub5_service);
	return;
}

void rank3(double_t* a, double_t* b, double_t* c) {
	double_t temp;
	if (*a > *b) {
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*a > *c) {
		temp = *a;
		*a = *c;
		*c = temp;
	}
	if (*b > *c){
		temp = *b;
		*b = *c;
		*c = temp;
	}
	return;
}
void sub6_service(const stream_t* stream) {
	double_t* nums;
	double_t num1, num2, num3;
	nums = getNFloat(stream->stream, 3);
	num1 = nums[0];
	num2 = nums[1];
	num3 = nums[2];
	rank3(&num1, &num2, &num3);
	printf("%lf, %lf, %lf\n", num1, num2, num3);
	return;
}

void Subject_6(void) {
	const char* tips = "[6] please enter three float number(space/tab to quit):";

	subjectBash(tips, sub6_service);
	return;
}

void sub7_service(const stream_t* stream) {
	int res;
	char ch;
	const char* p = stream->stream;
 	while (ch = (*p++)) {
		if (isalpha(ch))
			res = tolower(ch) - 'a' + 1;
		else
			res = -1;
		printf("%d ", res);
	}
	printf("\n");
	return;
}
void Subject_7(void) {
	const char* tips = "[7] please enter a text:(space/tab to quit):\n";

	subjectBash(tips, sub7_service);
	return;
}

double_t power(double_t n, int p) {
	int count = abs(p);
	double_t pow = 1;

	if (n == 0 and p not_eq 0)
		pow = 0;
	else if (p > 0)
		while (count--) pow *= n;
	else if (p < 0)
		while (count--) pow /= n;

	return pow;
}

void sub8_service(const stream_t* stream) {
	double_t x, xpow;
	int exp[8] = { 0 };
	int exp_size;
	const char* p = stream->stream;
	x = getFloat(&p);
	exp_size = getIntArray(p, exp);

	xpow = power(x, exp[0]);
	printf("%.3g to the number %d is %g\n", x, exp[0], xpow);

	return;
}

void Subject_8(void) {
	const char* tips = "[8] Please enter a number and a power(space/tab toquit):";

	subjectBash(tips, sub8_service);

	return;
}

double_t power_recur(double_t n, int p) {
	double_t pow;
	if (n not_eq 0)
		if (p > 0) pow = n * power_recur(n, --p);
		else if (p < 0) pow = power_recur(n, ++p) / n;
		else pow = 1;
	else
		if (p == 0) pow = 1;
		else pow = 0;

	return pow;
		
}

void sub9_service(const stream_t* stream) {
	double_t x, xpow;
	int exp[8] = { 0 };
	int exp_size;
	const char* p = stream->stream;
	x = getFloat(&p);
	exp_size = getIntArray(p, exp);

	xpow = power_recur(x, exp[0]);
	printf("%.3g to the number %d is %g\n", x, exp[0], xpow);

	return;
}

void Subject_9(void) {
	const char* tips = "[9] Please enter a number and a power(space/tab toquit):";

	subjectBash(tips, sub9_service);

	return;
}

INT64 base_N_2_dec(INT32 baseN, INT8 scale) {
	INT64 dex = 0;
	size_t step = 0;
	do {
		dex += baseN % 10 * power(scale, step++);
	} while ((int)(baseN /= 10));
	return dex;
}

INT64 dec_to_base_N(INT32 dex, INT8 scale) {
	INT64  baseN = 0;
	size_t step = 0;
	do {
		baseN += dex % scale * power(10, step++);
	} while ((int)(dex) /= scale);
	return baseN;
}

void sub10_service(const stream_t* stream) {
	int chose;
	int scale;
	INT32 base;
	const char* p = stream->stream;
	getIntArray(p, &chose);


	printf("Please enter your scale:");
	scanf("%d", &scale);
	if (chose == 1) {
		printf("Please enter a number of %d scale:", scale);
		scanf("%d", &base);
		printf("(10)%lld\n", base_N_2_dec(base, scale));
	}
	else if (chose == 2) {
		printf("Please enter a number of dex:");
		scanf("%d", &base);
		printf("(%d)%lld\n", scale, dec_to_base_N(base, scale));
	}

	while (getchar() != '\n')
		continue;
	
	return;
}

void Subject_10(void) {
	const char* tips = "[10] \n1) any scale to dex 2) dex to any scale\nPlease chose(space/tab toquit):";

	subjectBash(tips, sub10_service);

	return;
}

unsigned long Fibonacci(unsigned n) {
	if (n > 2)
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	else
		return 1;
}

unsigned long Fibonacci_loop(unsigned n) {
	int last = 1;
	int llast = 0;
	unsigned long fib = last + llast;
	for (size_t step = 2; step <= n; ++step) {
		fib = last + llast;
		llast = last;
		last = fib;
	}
	return fib;
}

void sub11_service(const stream_t* stream) {
	int n;
	getIntArray(stream->stream, &n);
	printf("The Fib %d you check is [%lu]\n", n, Fibonacci_loop(n));

	return;
}

void Subject_11(void) {
	const char* tips = "[11] Please enter an integer specified the Fibonacci you want check:(space/tab to quit):";

	subjectBash(tips, sub11_service);

	return;

}