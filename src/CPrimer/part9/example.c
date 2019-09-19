#include "example.h"


void lethead1(void) {
	starbar();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	starbar();

	return;
 }

void starbar(void) {
	int count;
	for (count = 1; count <= WIDTH; count++) {
		putchar('*');
	}
	putchar('\n');
	
	return;
}

void content1(void) {
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);

	return;
}

void cb_starbar(void(*func)(void)) {
	starbar();
	func();
	starbar();

	return;
}

void usehotel(void) {
	int nights;
	double hotel_rate;
	int code;

	while ((code = menu()) != QUIT) {
		switch (code)
		{
		case 1:
			hotel_rate = HOTEL1;
			break;
		case 2:
			hotel_rate = HOTEL2;
			break;
		case 3:
			hotel_rate = HOTEL3;
			break;
		case 4:
			hotel_rate = HOTEL4;
			break;
		default:
			hotel_rate = 0.0;
			printf("Oops!\n");
			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("Thank you and goodbye.\n");

	return;
}

void loccheck(void) {
	int pooh = 2, bah = 5;

	printf("In loccheck(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In loccheck(), bah = %d and &bah = %p\n", bah, &bah);
	mikado(pooh);

	return;
}

void mikado(int bah) {
	int pooh = 10;

	printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);
	return;
}


void swap_test(void)
{
	int x = 5, y = 11;
	printf("before swap: x = %d, y= %d\n", x, y);
	swap(&x, &y);
	printf("after swap: x= %d, y= %d\n", x, y);
	
	return;
}

void swap(int * a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	return;
}


void make_choice(void) {
	int res;
	showtmenu();
	while ((res = getchoice(1, 4)) != 4) {
		printf("I like choice %d.\n", res);
		showtmenu();
	}
	printf("Bye.\n");
	return ;
}

void showtmenu(void) {

	printf("Please choose ont of the following:\n");
	printf("1) copy files                    2) move files\n");
	printf("3) remove files                  3) quit\n");
	printf("Enter the number you want:");

	return;
}

int getchoice(int low, int high) {
	int ans;
	int good;
	good = scanf("%d", &ans);
	while (good == 1 and (ans < low || ans > high)) {
		printf("%d is not a valid choice; try again\n", ans);
		showtmenu();
		scanf("%d", &ans);
	}if (good != 1) {
		printf("Non-numeric input.");
		ans = 4;
	}
	return ans;
}

// unit test
void test() {
	//lethead1();
	//cb_starbar(content1);

	//uksehotel();

	//loccheck();
	//swap_test();
	make_choice();



	//printf("test.\n");
	return;
}