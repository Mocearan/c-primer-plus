#include "example.h"

unsigned int rand0(void) {
	/* Magic formula for generating pseudo-random Numbers */
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

void srand1(unsigned int seed) {
	next = seed;
}

int roll_count = 0;
static int rollem(int sides)
{
	++roll_count;
	return (rand()%sides + 1);
}

int roll_n_dice(int dice, int sides)
{
	int d;
	
	int total = 0;
	if (sides < 2) {
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if (dice < 1) {
		printf("Need at least 1 die.\n");
		return -1;
	}

	for (d = 0; d < dice; d++)
		total += rollem(sides);

	return total;
}

void Game(int result)
{
	int num = 0;
	while (1) {
		printf("Please enter your number:");
		scanf("%d", &num);
		if (num > result)
			puts("big.");
		else if (num < result)
			puts("small.");
		else
			break;
	}
	puts("GUESSED!!!");
}

void guess_number(void) {
	srand((size_t)time(NULL));
	int result = rand() % 100 + 1;
	int input;
	puts("1. to start game.\n2. to quit.");
	while (1) {
		scanf("%d", &input);
		if (input == 1) {
			printf("start.\n");
			Game(result);
			break;
		}
		else if (input == 0) {
			puts("quit.");
			break;
		}
		else
			puts("输入不合法，请重新输入：");
	}
}
