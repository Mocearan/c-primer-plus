#include "pra.h"

void t1(void) {
	char name[] = { 'F', 'e', 's', 's' };//char array
}

void t2(void) {
	char note[] = "See you at the snack bar.";
	char* ptr;

	ptr = note;
	puts(ptr);
	puts(++ptr);
	note[7] = '\0';
	puts(note);
	puts(++ptr);
	return ;
}

void t3(void) {
	char food[] = "Yummy";
	char* ptr;

	ptr = food + strlen(food);
	while (--ptr >= food)
		puts(ptr);

	return ;
}

void t4(void) {
	char goldwyn[40] = "art of it all ";
	char samuel[40] = "I read p";
	const char* quote = "the way through.";

	strcat(goldwyn, quote);
	strcat(samuel, goldwyn);
	puts(samuel);
	return ;
}

char* pr(char* str) {
	char* pc;

	pc = str;
	while (*pc)
		putchar(*pc++);
	do {
		putchar(*--pc);
		//putchar(--*pc);
	} while (pc - str);
	return (pc);
}
void t5(void) {
	char* x = pr("Ho Ho Ho!");
	//char* x = pr("");
	putchar('\n');

	return;
}

void t6(void) {
	char sign = '$';
	/*字符常量，默认按照int类型来处理*/
	printf("%u %u %u\n", sizeof sign, sizeof '$', sizeof "$"); //'$' -> char

	return;
}


char M2[40] = "Beat the clock.";
char* M3 = "chat";
void t7() {
	char words[80];
	printf(M1);
	puts(M1);
	puts(M2);
	puts(M2 + 1);
	strcpy(words, M2);
	strcat(words, " Win a toy.");
	puts(words);
	words[4] = '\0';
	puts(words);
	while (*M3)
		puts(M3++);
	puts(--M3);
	puts(--M3);
	M3 = M1;
	puts(M3);
	return ;
}

void t8(void) {
	char str1[] = "gawsie";
	char str2[] = "bletinism";
	char* ps;
	int i = 0;
	for (ps = str1; *ps not_eq '\0'; ps++) {
		if (*ps == 'a' or *ps == 'e')
			putchar(*ps);
		else
			(*ps)--;
		putchar(*ps);
	}
	putchar('\n');
	while (str2[i] not_eq '\0') {
		printf("%c", i % 3 ? str2[i] : '*');
		i++;
	}
	return ;
}

size_t _strlen(const char* s) {
	int ct = 0;
	while (*s++)
		ct++;
	return ct;
}

void t13(void) {
	char try[SIZE];
	puts("Who is buried in Grant's tomb?");
	s_gets(try, SIZE);
	str_toupper(try);
	while (strcmp(try, ANWSER) != 0) {
		puts("No, that's wrong. Try again.");
		s_gets(try, SIZE);
		str_toupper(try);
	}
	puts("That's right!");
	return;
}



int pra_test(void) {

	//t6();
	//t7();
	//t8();
	t13();

	return 0;
}