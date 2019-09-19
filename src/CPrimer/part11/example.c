#include "example.h"

void p_and_s(void) {
	const char* mesg = "Don't be fool!";
	const char* copy;

	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
	printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
}

void fgets1(void) {
	char words[STRLEN];

	puts("Enter a string , please.");
	fgets(words, STRLEN, stdin);
	printf("Your string twice (puts(), then fputs():\n");
	puts(words);
	fputs(words, stdout);

	puts("Enter another string, please.");
	fgets(words, STRLEN, stdin);
	puts(words);
	fputs(words, stdout);
	puts("Done");

}

void fgets2(void) {
	char words[STRLEN];

	puts("Enter strings (empty line to quit):");
	while (fgets(words, STRLEN, stdin) != NULL and words[0] != '\n')
		fputs(words, stdout);
	puts("Done.");

}

void fgets3(void) {
	char words[STRLEN];
	int i;

	puts("Enter strings (empty line to quit):");
	while (fgets(words, STRLEN, stdin) != NULL and words[0] != '\n') {
		i = 0;
		while (words[i] != '\n' and words[i] != '\0')
			i++;
		if (words[i] == '\n')
			words[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		puts(words);
	}
	puts("Done.");
}

void put_out(void) {
	char str1[80] = "An array was initialized to me.";
	const char* str2 = "A pointer was initialized to me.";

	puts("I'm an argument to puts().");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]);
	puts(str2 + 4);
}

void nono(void) {
	char side_a[] = "Side A";
	char dont[] = { 'W', 'O', 'W', '!' };
	char side_b[] = "Side_B";

	//puts(side_a);
	puts(dont);
	//puts(side_b);
}

void put_driver(void) {
	put_no_n("If I'd as much money");
	put_no_n(" as I could spend,\n");
	printf("I could %d charactors.\n",
		put_len("I never would cry old chairs to mend."));
	return;
}

void fit_driver(void) {
	char mesg[] = "Things should be as simple as possible,"
		"but not simpler.";

	puts(mesg);
	fit(mesg, 38);
	puts(mesg);
	puts("Let's look at some more of the string.");
	puts(mesg + 39);
}

void str_cat(void) {
	char flower[STRSIZE];
	char addon[] = "s smell like old shoes.";

	puts("What is your favorite flower?");
	if (s_gets(flower, STRSIZE)) {
		strcat(flower, addon);
		puts(flower);
		puts(addon);
	}
	else puts("End of file encountered!");
	puts("bye");
}

void join_chk(void) {
	char flower[ENAFSIZE];
	char addon[] = "s smell like old shoes.";
	char bug[BUGSIZE];
	int available;

	puts("What is your favorite flower?");
	s_gets(flower, ENAFSIZE);
	if ((strlen(addon) + strlen(flower) + 1) < ENAFSIZE)
		strcat(flower, addon);
	puts(flower);
	puts("What is your favorite bug?");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat(bug, addon, available);
	puts(bug);
}

void nogo(void) {
	char try[CMPSIZE];

	puts("Who is buried in Grant's tomb?");
	s_gets(try, CMPSIZE);
	while (try != ANSWER) {
		puts("No , that's wrong. Try again.");
		s_gets(try, CMPSIZE);
	}
	puts("That's right!");
	return;
}

void compare(void) {
	char try[CMPSIZE];

	puts("Who is buried in Grant's tomb?");
	s_gets(try, CMPSIZE);
	while (strcmp(try, ANSWER)) {
		puts("No , that's wrong. Try again.");
		s_gets(try, CMPSIZE);
	}
	puts("That's right!");
	return;
}

void to_ul(void) {
	char in[CMPSIZE];
	puts("Please enter string:");
	s_gets(in, CMPSIZE);
	str_toupper(in);
	puts(in);
	str_tolower(in);
	puts(in);
}

void quit_chk(void) {
	char input[LIM][STRSIZE];
	int ct = 0;

	printf("Enter up to %d lines (typ quit to quit):\n", LIM);
	while (ct < LIM
		and s_gets(input[ct], STRSIZE) != NULL
		//and strcmp(input[ct], STOP) != 0)
		and input[ct][0])
		++ct;
	printf("%d strings entered\n", ct);
}

void starsrch(void) {
	const char* list[LISTSIZE] = {
		"astronomy", "astounding",
		"astrophysics", "ostracize",
		"asterism","astrophobia"
	};
	int count = 0;
	int i;

	for(i = 0; i < LISTSIZE; i++)	
		if (strncmp(list[i], "astro", 5) == 0) {
			printf("Fount: %s\n", list[i]);
			count++;
		}
	printf("The list contained %d words beginning"
		" with astro.\n", count);
	return;
}

void copy1(void) {
	char qwords[LLIM][COPYSIZE] = { 0 };
	char temp[COPYSIZE] = { 0 };
	size_t i = 0;

	printf("Enter %d words beginning with q:\n", LLIM);
	while (i < LLIM and s_gets(temp, COPYSIZE)) {
		if (temp[0] != 'q')
			printf("%s doesn't begin with q!\n", temp);
		else {
			strcpy(qwords[i], temp);
			i++;
		}
	}
	puts("Here are the words accepted:");
	for (i = 0; i < LLIM and qwords[i][0]; i++)
		puts(qwords[i]);

	return;
}

void copy2(void) {
	const char* orig = WORDS;
	char copy[COPYSIZE] = "Be the best that you can be.";
	char *ps;

	puts(orig);
	puts(copy);
	ps = strcpy(copy + 7, orig);
	puts(copy);
	puts(ps);
}

void copy3(void) {
	char qwords[LLIM][TARGSIZE] = { 0 };
	char temp[COPYSIZE] = { 0 };
	size_t i = 0;

	printf("Enter %d words beginning with q:\n", LLIM);
	while (i < LLIM and s_gets(temp, COPYSIZE)) {
		if (temp[0] != 'q')
			printf("%s doesn't begin with q!\n", temp);
		else {
			strncpy(qwords[i], temp, TARGSIZE - 1);
			qwords[i][TARGSIZE - 1] = '\0';
			i++;
		}
	}
	puts("Here are the words accepted:");
	for (i = 0; i < LLIM and qwords[i][0]; i++)
		puts(qwords[i]);
}

void sort_str(void) {
	char input[SORTLIM][SORTSIZE] = { 0 };
	char* ptstr[SORTLIM] = { 0 };
	int ct = 0;
	int k;

	printf("Input up tp %d lines, and I will sort them.\n", SORTLIM);
	printf("To stop, press the Enter key at a line's start.\n");
	while (ct < SORTLIM and s_gets(input[ct], SORTSIZE) != NULL and input[ct][0]!= '\0') {
		ptstr[ct] = input[ct];
		ct++;
	}
	ststr(ptstr, ct);
	puts("\nHere's the sorted list:\n");
	for (k = 0; k < ct; k++)
		puts(ptstr[k]);
	return;
}

void mod_str(void) {
	char line[SORTSIZE];
	char* find;

	puts("Please enter a line:");
	fgets(line, SORTSIZE, stdin);
	if ((find = strchr(line, '\n'))) 
		*find = '\0';
	str_toupper(line);
	puts(line);
	printf("That line has %d punctuation charactors.\n", PunctCont(line));
	return;
}

void strcnvt(void) {
	char number[CNVTLIM] = { 0 };
	char* end = NULL;
	long value;

	puts("Enter a number:");
	while (s_gets(number, CNVTLIM) and number[0]) {
		value = strtol(number, &end, 10);
		printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
		value = strtol(number, &end, 16);
		printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
		puts("Next number:");
	}
	puts("Bye!");

	return 0;
}


// unit test
void test() {
	//p_and_s();
	//fgets1();
	//fgets2();
	//fgets3();
	//put_out();
	//nono();
	//put_driver();
	//fit_driver();
	//str_cat();
	//join_chk();
	//nogo();
	//compare();
	//to_ul();
	//quit_chk();
	//starsrch();
	//copy1();
	//copy2();
	//copy3();
	//sort_str();
	//mod_str();
	 strcnvt();

	//printf("test.\n");
	return;
}