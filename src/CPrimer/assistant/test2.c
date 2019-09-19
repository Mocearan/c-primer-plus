#include"test.h"
#include<stdio.h>


#define ANNUAL_RETURN 1.042
#define WAN 10000

void test2() {
	int year = 0;

	const int principal_mofify = 2000;
	int sum = principal_mofify;
	while (scanf("%d",&year)){
		for (int i = 1; i <= year; printf("%d\t", i), ++i);
		printf("\n");
		for (int i = 1; i <= year; ++i) {
			if (sum * (ANNUAL_RETURN - 1) <= 20 * WAN) {
				if (i <= 10)
					 sum = (sum + i * WAN)*ANNUAL_RETURN;
				else
					 sum = (sum + 10 * WAN)*ANNUAL_RETURN;
			}
			else {
				sum *= ANNUAL_RETURN;
			}
			printf("%d\t", sum);
		}
		printf("\n");
		year = 0;
		sum = principal_mofify;
	}
}