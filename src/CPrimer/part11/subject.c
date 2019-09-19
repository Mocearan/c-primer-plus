#include "subject.h"

char* getN(const char* in, char* out, size_t n) {
	size_t i = 0;
	for(;i < n and in[i] not_eq '\0'; ++i)
		out[i] = in[i];
	out[i] not_eq '\0' ? out[i] = '\0' : 1;

	return out;
}
void sub1_service(const stream_t* stream) {
	char str[SIZE1] = { 0 };
	getN(stream->stream, str, 10);
	puts(str);

	return 0;
}
void subject_1(void) {
	const char* tips = "[1]:\n";

	subjectBash(tips, sub1_service, BASH_INTERFACE, BASH_LINE);
	return;
}


char* getN_blk(const char* in, char* out, size_t n) {
	size_t i = 0;
	for (; i < n and in[i] not_eq '\0'; ++i) {
		if (isspace(*(in + i)))
			break;
		*(out + i) = *(in + i);
	}
	out[i] not_eq '\0' ? out[i] = '\0' : 1;
	
	return out;
}
void sub2_service(const stream_t* stream) {
	char str[SIZE2] = { 0 };

	getN_blk(stream->stream, str, 10);
	puts(str);

	return;
}

void subject_2(void) {
	const char* tips = "[2]:Enter some charactors:\n";

	subjectBash(tips, sub2_service, BASH_INTERFACE, BASH_LINE);
	return;
}

//去除前置空白符在这个shell下没法测试。。。因为空白符被用作命令了。。。
void get_word(const char* in, char* out) {
	char* p = in;
	while (isspace(*in))
		continue;
	do
		*out++ = *p++;
	while (not isspace(*p));
	*out = '\0';
	while (*p)
		*p++ = '\0';
}
void sub3_service(const stream_t* stream) {
	char* str[SIZE1];

	get_word(stream->stream, str, 10);
	puts(str);

	return;
}
void subject_3(void) {
	const char* tips = "[ 3 ] Please enter some words:(space/tab to quit)\n";

	subjectBash(tips, sub3_service, BASH_INTERFACE, BASH_LINE);
	return;
}

void get_word_s(const char* in, char* out, size_t n) {
	char* p = in;
	size_t i = 0;

	while (isspace(*in))
		continue;
	do {
		*(out + i) = *(p++);
		i++;
	}
	while (not isspace(*p) and i < (n -1));
	*(out + i) = '\0';
	while (*p)
		* p++ = '\0';
}
void sub4_service(const stream_t* stream) {
	char str[10] = { 0 };

	get_word_s(stream->stream, str, 10);
	puts(str);

	return;
}

void subject_4(void) {
	const char* tips = "[ 4 ] Please input a series of integer to init a int arrat:(space/tab to quit)\n";

	subjectBash(tips, sub4_service, BASH_INTERFACE, BASH_LINE);
	return;
}


char* strch(const char* str, char c){
	char* p = str;
	while (*p not_eq '\0')
		if (*p == c)
			break;
		else
			p++;
	if (*p == '\0')
		p = NULL;

	return p;
}
void sub5_service(const stream_t* stream) {
	char str[SIZE2] = { 0 };
	char* pch = NULL;

	puts("Please enter a charactor for search: ");
	char ch = getchar();
	while (getchar() not_eq '\n');
	pch = strch(stream->stream, ch);
	if (pch not_eq NULL)
		printf("Find.\n The string start with the %c:\n""%s\n", ch, pch);
	else
		puts("Can't find it.");
}
void subject_5(void) {
	const char* tips = "[ 5 ] Please input a string:(space/tab to quit)\n";

	subjectBash(tips, sub5_service, BASH_INTERFACE, BASH_LINE);
	return;
}


bool is_within(char* p, char c) {
	while (*p not_eq '\0')
		if (*p == c)
			break;
		else
			p++;
	if (*p == '\0')
		return false;
	else return true;
}
void sub6_service(const stream_t* stream) {
	char* str[SIZE2] = { 0 };
	
	puts("Please enter a charactor for search: ");
	char ch = getchar();
	while (getchar() not_eq '\n');
	if(is_within(stream->stream, ch))
		printf("Find.\n The string start with the %c\n", ch);
	else
		puts("Can't find it.");
}

void subject_6(void) {
	const char* tips = "[ 6 ] please input a string:(space/tab to quit)\n";

	subjectBash(tips, sub6_service, BASH_INTERFACE, BASH_LINE);
	return;
}


char* mystrncpy(char* des, const char* src, size_t n) {
	char* p = src;
	size_t i = 0;
	for (; i < n and *p; ++i)
		* (des + i) = *p++;
	if (i < n)
		*(des + i) = '\0';
	return src;
}
void sub7_service(const stream_t* stream) {
	char* str1[SIZE2] = { 0 };
	int n;

	do {
		puts("Please input a positive integer of copied size.");
		scanf("%d", &n);
	} while (n < 0 );
	while (getchar() not_eq '\n');

	mystrncpy(str1, stream->stream, n);
	puts(str1);
	return;
}

void subject_7(void) {
	const char* tips = "[ 7 ] Please input a string:(space/tab to quit)\n";

	subjectBash(tips, sub7_service, BASH_INTERFACE, BASH_LINE);
	return;
}


char* substr_at(const char* str, const char* sub) {
	size_t i = 0;
	bool finded = false;
	char* res = NULL;

	for (; *(str + i); ++i) {
		size_t j = 0;
		for (; *(sub + j); ++j) {
			if (*(sub + j) not_eq *(str + i +j))
				break;
		}

		if (not *(sub + j)) {
			finded = true;
			break;
		}
	}

	if (finded)
		res = str + i;
	return res;
}
void sub8_service(const stream_t* stream) {
	char* sub[SIZE1] = { 0 };
	puts("Input the sub string for search");
	s_gets(sub, SIZE1);

	char* search = substr_at(stream->stream, sub);
	if (search)
		printf("Finded.\n%s\n",search);
	else
		puts("Can't find.");
}

void subject_8(void) {
	const char* tips = "[ 8 ] Please input a string:(space/tab to quit)\n";

	subjectBash(tips, sub8_service, BASH_INTERFACE, BASH_LINE);
	return;
}

void strinvt(char* str) {
	size_t len = strlen(str);
	char tmp;
	for (size_t i = 0; i < len - i -1; ++i) {
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	str[len] = '\0';
}
void sub9_service(const stream_t* stream) {
	strinvt(stream->stream);
	puts(stream->stream);
}

void subject_9(void) {
	const char* tips = "[ 9 ] Please input a string:(space/tab to quit)\n";

	subjectBash(tips, sub9_service, BASH_INTERFACE, BASH_LINE);
	return;
}

void strdelspc(char* str) {
	char cp[SIZE2] = { 0 };
	size_t i = 0;
	char* p = str;
	while (*p) {
		if (*p not_eq ' ')
			cp[i++] = *p;
		p++;
	}
	memset(str, 0x00, strlen(str));
	strncpy(str, cp, i + 1);
}
void sub10_service(const stream_t* stream) {
	strdelspc(stream->stream);
	puts(stream->stream);
}
void subject_10(void) {
	const char* tips = "[ 10 ] Please enter a string:(CTRL+Z to end,space/tab to quit)\n";

	subjectBash(tips, sub10_service, BASH_INTERFACE, BASH_LINE);
	return;
}

char get_choice(void) {
	char ch;
	fputs( "a.print string list.\t\t\t", stdout);
	puts("b.print order of ASCII.");
	fputs("c.print in order of length.\t\t\t", stdout);
	puts("d.print in order of the first word's length.");
	puts("q.quit");
	puts("Enter a charactor (a,b,c,d,q):");
	ch = getchar();
	while (ch<'a' or ch > 'd' and ch not_eq 'q') {
		puts("Enter a charactor (a,b,c,d,q):");
		ch = getchar();
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	return ch;
}
void print_list(char* st[], size_t row) {
	for (size_t i = 0; i < row; i++)
		puts(st[i]);
}
void print_ascii(char* st[], int n) {
	int i, j;
	char* temp;
	for(i = 0; i < n-1; i++)
		for(j = i +1;j<n;j++)
			if (strcmp(st[i], st[j]) > 0) {
				temp = st[j];
				st[j] = st[i];
				st[i] = temp;
			}
	for (i = 0; i < n; i++)
		puts(st[i]);
}
void print_length(char* st[], int n) {
	int i, j;
	char* temp;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (strlen(st[i]) > strlen(st[j])) {
				temp = st[j];
				st[j] = st[i];
				st[i] = temp;
			}
	for (i = 0; i < n; i++)
		puts(st[i]);
}
int first_length(char* st) {
	int i = 0;
	int count = 0;
	while (!isalpha(st[i]))
		i++;
	while(isalpha(st[i])) {
		i++;
		count++;
	}
	return count;
}
void print_first_word(char* st[], int n) {
	int i, j;
	char* temp;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (first_length(st[i]) > first_length(st[j])) {
				temp = st[j];
				st[j] = st[i];
				st[i] = temp;
			}
	for (i = 0; i < n; i++)
		puts(st[i]);
}
void choice(char* st[], size_t n) {
	char choice;
	while ((choice = get_choice()) != 'q') {
		puts("");
		switch (choice)
		{
		case 'a':
			print_list(st, n);
			break;
		case 'b':
			print_ascii(st, n);
			break;
		case 'c':
			print_length(st, n);
			break;
		case 'd':
			print_first_word(st, n);
			break;
		default:
			puts("Error");
			break;
		}
	}
	puts("Bye.");
}
void sub11_service(const stream_t* stream) {
	char str[10][80] = { 0 };
	char* ptr[10];
	size_t row = getStrListFromText(stream->stream, ptr, 10);
	copyStrArray(str, ptr, row);

	for (size_t i = 0; i < row; i++)
		ptr[i] = str[i];
	choice(ptr, row);
}
void subject_11(void) {
	const char* tips = "[ 11 ] Please enter 10 string or end of EOF:\n";

	subjectBash(tips, sub11_service, BASH_INTERFACE, BASH_TEXT);
	return;
}


void sub12_service(const stream_t* stream) {
	char* pch = stream->stream;
	int word = 0, upper = 0, lower = 0;
	int punct = 0, digit = 0, inword = 0;

	do {
		if (!isspace(*pch) and (!ispunct(*pch)) and (!inword)) {
			inword = 1;
			if(*(pch+1))
				word++;
		}
		if (isspace(*pch) or ispunct(*pch) and inword)
			inword = 0;
		if (isupper(*pch))
			upper++;
		if (islower(*pch))
			lower++;
		if (ispunct(*pch))
			punct++;
		if (isdigit(*pch))
			digit++;
	} while (*pch++);
	printf("words: %d, upper: %d, lower: %d, punct: %d, digit: %d.\n", word, upper, lower, punct, digit);
}
void subject_12(void) {
	const char* tips = "[ 12 ]:(CTRL+Z to end,space/tab to quit)\n";

	subjectBash(tips, sub12_service, BASH_INTERFACE, BASH_TEXT);
	return;
}

void sub13_service(void) {
	const char* code = "#include <stdio.h>\n"
		"int main(int argc, char* argv[])\n"
		"{\n"
		"\tintcount;\n\n"
		"\tfor(count = argc - 1; count > 0; count--\n"
		"\t\tprintf(\"%s\",argv[count]);\n\n"
		"\treturn 0;\n"
		"}\n";
	puts(code);
}
void subject_13(void) {
	const char* tips = "[ 13 ] this bash can't support cmd line.but show the code here:\n";
	
	subjectBash(tips, sub13_service, BASH_DEFAULT);
	return;
}

double mypower(double n, int exp) {
	double pow;

	if (exp > 0)
		for (pow = 1; exp > 0; exp--)
			pow *= n;
	else if (exp < 0) {
		if (!n)
			printf("It's not defined!\n");
		for (pow = 1; exp < 0; exp++)
			pow *= (1 / n);
	}
	else if (n)
		pow = 1;
	else {
		pow = 1 / n;
		printf("It's not defined!\n");
	}

	return pow;
}
void sub14_service(const stream_t* stream) {
	char str[2][16] = { 0 };
	char* ptr[2];
	size_t nWrods = getWordsFromLine(stream->stream, ptr, 2);
	for (size_t i = 0; i < 2; i++)
		strncpy(str[i], ptr[i], 16);

	for (size_t i = 0; i < nWrods; i++)
		ptr[i] = str[i];
	printf("pow:%g\n", mypower(atof(ptr[0]), atoi(ptr[1])));
}
void subject_14(void) {
	const char* tips = "[ 14 ] Please enter double to n, integer to exp(space/tab to quit):";

	subjectBash(tips, sub14_service, BASH_INTERFACE, BASH_LINE);
}

int myatoi(char* st) {
	int sum = 0;
	for (; *st; st++)
		if (isdigit(*st))
			sum = 10 * sum + (*st - '0');
		else
			return 0;
	return sum;
}
void sub15_service(const stream_t* stream) {
	char str[40];
	printf("%d\n", myatoi(stream->stream));
}
void subject_15(void) {
	const char* tips = "[ 15 ] Please enter double (space/tab to quit):";
	subjectBash(tips, sub15_service, BASH_INTERFACE, BASH_LINE);
	return;
}


void sub16_service(const stream_t* stream) {
	// get arguments
	char argv[2][16] = { 0 };
	char* ptr[2];
	//const char* name = "subject_16";
	//argv[0] = name;
	//...
	size_t argc = getWordsFromLine(stream->stream, ptr, 2);

	for (size_t i = 0; i < 2; i++)
		if(ptr[i])
			strncpy(argv[i], ptr[i], 16);

	for (size_t i = 0; i < argc; i++)
		ptr[i] = argv[i];

	// logic
	int col;
	int i;
	int row = 0;
	char str[10][80];
	while (row < 10 and fgets(str[row], 80, stdin) != NULL) {
		if (argc == 1);
		else if (!strcmp(argv[0], "-p"));
		else if (!strcmp(argv[0], "-l"))
			for (col = 0; str[row][col] != '\0'; col++)
				str[row][col] = toupper(str[row][col]);
		else if (!strcmp(argv[0], "-u"))
			for (col = 0; str[row][col] != '\0'; col++)
				str[row][col] = tolower(str[row][col]);
		row++;
	}
	for (i = 0; i < row; i++)
		fputs(str[i], stdout);
	puts("");
}
void subject_16(void) {
	const char* tips = "[ 16 ] Please enter the arguments:(space/tab to quit):";
	subjectBash(tips, sub16_service, BASH_INTERFACE, BASH_LINE);
	return;
}
