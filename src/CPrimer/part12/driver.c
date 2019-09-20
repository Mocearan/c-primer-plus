#include "driver.h"

void r_driver0(void) {
	int count;
	for (count = 0; count < 5; count++)
		printf("%d\n", rand0());
}

void r_driver1(void) {
	int count;
	unsigned seed;

	printf("Please enter your choice for seed.\n");
	while (scanf("%u", &seed) == 1) {
		srand1(seed);
		for (count = 0; count < 5; count++)
			printf("%d\n", rand0());
		printf("Please enter next seed (q to quit):\n");
	}
	puts("Done");
}


void manydice(void)
{
	int dice, roll;
	int sides;
	int status;

	srand((size_t)time(NULL));//seed
	printf("Enter the number of sides per die, 0 to stop:");
	while (scanf("%d", &sides) == 1 and sides > 0) {
		puts("How many dice?\n");
		if ((status = scanf("%d", &dice)) != 1) {
			if (status == EOF)
				break;
			else {
				printf("You should have entered an integer.");
				printf(" Let's begin again.\n");
				while (getchar() != '\n')
					continue;
				printf("How many sides? Enter 0 to stop.\n");
				continue;
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d using %d %d-sides dice.\n",
			roll, dice, sides);
		printf("How many sides? Enter 0 to stop.\n");
	}
	printf("The rollem() function was called %d times.\n",
		roll_count);
	printf("GOOD FORTUNE TO YOU!\n");
}

void guess_driver(void)
{
	guess_number();
}

void dyn_driver(void)
{
	dyn_arr();
}

void mem_leak_driver(void)
{
	double glad[2000];
	int i;
	for (i = 0; i < 100000000; i++)
		gobble(glad, 2000);
}

void test() {
	//r_driver0();
	//r_driver1();
	//puts("test.");
	//manydice();
	//guess_driver();
	//dyn_driver();
	mem_leak_driver();

	return;
}