#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>


int get_ch(void) {
	char ch;
	int res;
	printf("Input text:\n");
	while ((ch = getchar()) != EOF) {
		if (isalpha(ch))
			res = tolower(ch) - 'a' + 1;
		else
			res =  -1;
		printf("%d ", res);
	}
	return 0;
}


double power(double n, int p) {
	int count = p;
	double pow = 1;

	if (n == 0 && p != 0)
		pow = 0;

	if (p == 0)
		pow = 1;
	else if (p > 0)
		while (count--) pow *= n;
	else
		while (count--) pow /= n;

	return pow;
}

void pow_test(void) {
	double x, xpow;
	int exp;

	printf("Enter a numer and a power(less than two input quit):");
	while (scanf("%lf,%d", &x, &exp) == 2) {
		xpow = power(x, exp);
		printf("%.3g to the number %d is %g\n", x, exp, xpow);
		printf("Enter the next pair of number or q to quit.\n");

		printf("Enter a numer and a power(less than two input quit):");
	}
	printf("Bye.\n");
	return;
}
int main(void) {
	//get_ch();
	pow_test();

	return 0;
}