#include "subject.h"

static int critic(void) {
	int answer;

	puts("No luck, my frient. Try again.");
	scanf("%d", &answer);
	while (getchar() != '\n')
		getchar();

	return answer;
}
void sub1_service(const stream_t* stream) {
	int units;

	getIntArray(stream->stream, &units);
	while (units != 56)
		units = critic();
	puts("You must have looked it up!");
}
void subject_1(void) {
	const char* tips = "[1]:How many pounds to a firkin of butter :";

	subjectBash(tips, sub1_service, BASH_INTERFACE, BASH_LINE);
	return;
}

/* pe12_2b.c */
#include "pe12-2a.h"
void sub2_service(const stream_t* stream) {
	int mode;
	
	getIntArray(stream->stream, &mode);
	while (mode >= 0) {
		set_mode(mode);
		get_info();
		show_info();
		puts("Enter 0 for metric mode, 1 for US mode : ");
		printf("(-1 to quit): ");
		scanf("%d", &mode);
		while (getchar() != '\n')
			continue;
	}
	printf("Done.\n");
}
void subject_2(void) {
	const char* tips = "[2]:Enter 0 for metric mode, 1 for US mode(space/tab to quit) : ";

	subjectBash(tips, sub2_service, BASH_INTERFACE, BASH_LINE);
	return;
}


int set_mode1(int mode) {
	int last_mode = 0;
	if (mode not_eq 0 and mode not_eq 1)
		printf("Invalid mode specified. Mode %s used.\n",
			last_mode == 0 ? "0(metric)" : "1(US)");
	else
		last_mode = mode;
	return last_mode;
}
void show_info1(double_t* distance, double_t* fuel, int mode) {
	printf("Fuel consumption is ");
	if (set_mode1(mode) == 0)
		printf("%.2f liters per 100km.\n", (*fuel / *distance) * 100);
	else
		printf("%.1f miles per gallon.\n", *distance / *fuel);
}
void get_info1(int mode) {
	double_t* p1, * p2;
	double_t distance, fuel;

	printf("Enter distance travel in %s: ",
		set_mode1(mode) == 0 ? "Killometers" : "miles");
	scanf("%lf", &distance);
	printf("Enter fuel consumed in %s: ",
		set_mode1(mode) == 0 ? "liters" : "gallons");
	scanf("%lf", &fuel);
	p1 = &distance;
	p2 = &fuel;
	show_info1(p1, p2, mode);
}
void sub3_service(const stream_t* stream) {
	int mode;
	getIntArray(stream->stream, &mode);
	while (mode >= 0) {
		get_info1(mode);;
		printf("Enter 0 for metric mode, 1 for US mode:");
		printf("(-1 to quit):");
		scanf("%d", &mode);
		while (getchar() != '\n')
			continue;
	}
	puts("Done.");
	return;
}
void subject_3(void) {
	const char* tips = "[ 3 ] Enter 0 for metric mode, 1 for US mode:(space/tab to quit):";

	subjectBash(tips, sub3_service, BASH_INTERFACE, BASH_LINE);
	return;
}

static volatile called_times;
void called(void) {
	printf("%d\n", ++called_times);
}
void sub4_service(const stream_t* stream) {
	if(*(stream->stream) == '#'){}
		called();
}
void subject_4(void) {
	const char* tips = "[ 4 ] '#' to calling one more time:(space/tab to quit)\n";

	subjectBash(tips, sub4_service, BASH_INTERFACE, BASH_LINE);
	return;
}


void sub5_service(const stream_t* stream) {
	int size;
	getIntArray(stream->stream, &size);
	int* ar = (int*)malloc(size * sizeof(int));
	srand((size_t)time(NULL));
	for (size_t i = 0; i < size; i++)
		ar[i] = rand() % 10 + 1;
	puts("Original vector:");
	print_intVec(ar, size, 10);
	sort_int(ar, size);
	puts("Sorted vector:");
	print_intVec(ar, size, 10);
}
void subject_5(void) {
	const char* tips = "[ 5 ] Please input number of vector size:(space/tab to quit)";

	subjectBash(tips, sub5_service, BASH_INTERFACE, BASH_LINE);
	return;
}



void sub6_service(const stream_t* stream) {
	int i, j;
	int count[10];
	unsigned int seeds[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (j = 0; j < 10; j++) {
		for (i = 0; i < 10; i++)
			count[i] = 0;
		srand(seeds[j]);
		printf("seed = %d:\n", seeds[j]);
		for (i = 0; i < 1000; i++)
			count[rand() % 10]++;
		for (i = 0; i < 10; i++) {
			printf("%d:%-5d ", i + 1, count[i]);
			if (i == 4)
				putchar('\n');
		}
		putchar('\n');
	}
}

void subject_6(void) {
	const char* tips = "[ 6 ]\n";

	subjectBash(tips, sub6_service);
	return;
}

void roll_count1(int sets, int sides, int dice) {
	int i, j;
	int roll;
	if (sides < 2) {
		printf("Need at least 2 sides.\n");
		goto END;
	}
	if (dice < 1) {
		printf("Need at least 1 die.\n");
		goto END;
	}
	srand((size_t)time(NULL));
	for (i = 0; i < sets; i++) {
		roll = 0;
		for (j = 0; j < sides; ++j)
			roll += rand() % sides + 1;
		printf("%d ", roll);
	}
	putchar('\n');
END:
	return;
}
void sub7_service(const stream_t* stream) {
	int sets;
	int sides, dice;

	srand((size_t)time(NULL));
	getIntArray(stream->stream, &sets);
	 do{
		printf("How many sides and how many dices?");
		scanf("%d%d", &sides, &dice);
		printf("here are %d sets of %d %d-sided throws.\n",
			sets, dice, sides);
		roll_count1(sets, sides, dice);
		printf("How many sets? Enter q to stop: ");
	 } while (scanf("%d", &sets) == 1);
	 while (getchar() != '\n');
	puts("Bye.");
}

void subject_7(void) {
	const char* tips = "[ 7 ] Please Enter the number of sets:(space/tab to quit)";

	subjectBash(tips, sub7_service, BASH_INTERFACE, BASH_LINE);
	return;
}


int* make_array(int elem, int val) {
	int* pt = (int*)malloc(elem * sizeof(int));
	if (pt)
		if (val == 0 or val == -1)
			memset(pt, val, elem * sizeof(int));
		else
			for (size_t i = 0; i < elem; i++)
				pt[i] = val;
	return pt;
}
void free_array(int* arr) {
	if (arr) {
		free(arr);
		arr = NULL;
	}
}
void sub8_service(const stream_t* stream) {
	int size;
	int value;
	int* pa;
	getIntArray(stream->stream, &size);
	do {
		fputs("Enter the initialization value: ",stdout);
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa) {
			print_intVec(pa, size, 8);
			free_array(pa);
		}
		printf("Enter the number of elements:(-1 to quit)");
	} while (scanf("%d", &size) == 1 and size > 0);
	while (getchar()!='\n');
	puts("Done");
}
void subject_8(void) {
	const char* tips = "[ 8 ] Enter the number of elements:(space/tab to quit)";

	subjectBash(tips, sub8_service, BASH_INTERFACE, BASH_LINE);
	return;
}


char** make_ar(int n, size_t words_len) {
	char ch;
	char** pt = (char**)malloc(n * sizeof(char*));
	for (size_t i = 0; i < n; i++)
		pt[i] = (char*)malloc(words_len);

	return pt;
}
void free_ar(char** ar, int n) {
	if (ar) {
		for (size_t i = 0; i < n; i++)
			if (ar[i]) {
				free(ar[i]);
				ar[i] = NULL;
			}
		free(ar);
		ar = NULL;
	}
}
void init_words_list(char** list, int size, int words_len) {
	char ch;
	for (size_t i = 0; i < size; i++) {
		while (isspace(ch = getchar()));
		list[i][0] = ch;
		size_t j = 1;
		for (; !isspace(list[i][j] = getchar()); j++);
		list[i][j] = '\0';
	}
}
void print_words_list(char** list, int size) {
	for (size_t i = 0; i < size; i++)
		puts(list[i]);
}
void sub9_service(const stream_t* stream) {
	int words;
	getIntArray(stream->stream, &words);
	printf("Enter %d words now.\n", words);
	char** st = make_ar(words, 32);
	init_words_list(st, words, 32);
	puts("Your words list:");
	print_words_list(st, words);
	free_ar(st, words);
}

void subject_9(void) {
	const char* tips = "[ 9 ] How many words do you wish to enter:(space/tab to quit)";

	subjectBash(tips, sub9_service, BASH_INTERFACE, BASH_LINE);
	return;
}
