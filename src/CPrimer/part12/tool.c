#include "tool.h"

void result_info_initor(result_info_t* result) {
	result->result_info = (char*)malloc(128 * sizeof(char));
	result->info_len = 128 * sizeof(char);
	memset(result->result_info, 0x00, result->info_len);
	result->result_No = -2;

	return;
}

result_info_t* result_info_create() {
	result_info_t* result = (result_info_t*)malloc(sizeof(result_info_t));
	result_info_initor(result);

	return result;
}

void result_info_destroy(result_info_t* result) {
	if (result->result_info)
		free(result->result_info);
	if (result)
		free(result);

	return;
}

double_t get_float(void) {
	double_t input;
	char ch;

	while (scanf("%lf", &input) != 1) {
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an number.\n");
		printf("Please enter a number, such as 2.3, -1.78, or 3: ");
	}
	while (getchar() != '\n')
		continue;
	return input;
}

void getTwoFloat(const char* stdinBuffer, double* outFir, double* outSec)
{
	char InFir[32] = { 0 };
	char InSec[32] = { 0 };
	int i = 0;
	for (; stdinBuffer[i] != ' ' && stdinBuffer[i] != '\0'; InFir[i] = stdinBuffer[i], ++i)
		;
	for (int j = 0; stdinBuffer[i + 1] != '\0'; InSec[j] = stdinBuffer[i + 1], ++i, ++j)
		;
	*outFir = atof(InFir);
	*outSec = atof(InSec);
}

double_t getFloat(char** Buffer) {
	char Float[32] = { 0 };
	size_t i = 0;
	//for (; Buffer[i] != ' '&&Buffer[i] != '\0'; Float[i] = Buffer[i], ++i)
	//	;
	while (**Buffer != ' ' and **Buffer != '\0') {
		Float[i++] = **Buffer;
		(*Buffer)++;
	}
	if (**Buffer == ' ')
		(*Buffer)++;
	return (double_t)atof(Float);
}

double_t* getNFloat(const char* stdinBuf, const size_t count) {
	char* pBuf = stdinBuf;
	//size_t len = count;
	double_t floats[16] = { 0.0 };
	size_t num = 0;
	while (num < count) {
		floats[num++] = getFloat(&pBuf);
	}
	return floats;
}

size_t getFloatArray(const char* stdinBuffer, double_t* outArr)
{
	char intStr[16] = { 0 };
	size_t size;
	int i = 0;
	int j = 0;
	int k = 0;
	for (; stdinBuffer[i] != '\0' and stdinBuffer[i] != '\n'; ++i) {
		if (stdinBuffer[i] == ' ' and !k)
			continue;
		if (!isspace(stdinBuffer[i]))
			intStr[k++] = stdinBuffer[i];
		else {
			outArr[j++] = atof(intStr);
			memset(intStr, 0x00, sizeof(intStr));
			k = 0;
		}
	}

	if (intStr[0] != 0) {
		outArr[j] = atof(intStr); //Handle the last int
		size = ++j;
	}
	else {
		size = j;
	}

	return size;
}

int getInteger(void) {
	int status;
	int i;
	while ((status = scanf("%d", &i)) != 1 or (i < 1 or i > 10)) {
		if (status != 1)
			scanf("%*s");
		printf("Please enter an integer in range [1,10):");
	}
	while (getchar() != '\n')
		continue;
	return i;
}

size_t getIntArray(const char* stdinBuffer, int* outArr) {
	char intStr[16] = { 0 };
	size_t size;
	int i = 0;
	int j = 0;
	int k = 0;
	for (; stdinBuffer[i] != '\0'; ++i) {
		if (stdinBuffer[i] != ' ')
			intStr[k++] = stdinBuffer[i];
		else {
			outArr[j++] = atoi(intStr);
			memset(intStr, 0x00, sizeof(intStr));
			k = 0;
		}
	}

	if (intStr[0] != 0) {
		outArr[j] = atoi(intStr); //Handle the last int
		size = ++j;
	}
	else {
		size = j;
	}

	return size;
}

char* s_gets(char* st, size_t n) {
	char* ret_val = fgets(st, n, stdin);
#ifdef ARRAY_GET
	size_t i = 0;
	if (ret_val) {
		while (st[i] != '\n' and st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
#else
	char* find;
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
#endif
	return ret_val;
}

void put_no_n(const char* string) {
	while (*string) // *string != '\0'
		putchar(*string++);
}

size_t put_len(const char* string) {
	size_t count = 0;
	while (*string) {
		putchar(*string++);
		++count;
	}
	putchar('\n');
	return (count);
}

void fit(char* string, size_t size) {
	if (strlen(string) > size)
		string[size] = '\0';
}

void str_toupper(char* str) {
	while (*str)
		* str++ = toupper(*str);
	return;
}
void str_tolower(char* str) {
	while (*str)
		* str++ = tolower(*str);
	return;
}

void ststr(char* strings[], int num) {
	char* tmp;
	int top, seek;
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (strcmp(strings[top], strings[seek]) > 0) {
				tmp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = tmp;
			}
}

int PunctCont(const char* str) {
	int ct = 0;
	while (*str)
		if (ispunct(*str++)) ct++;
	return ct;
}

char* strblk(const char* string) {
	while (*string != ' ' and *string != '\0')
		string++;
	if (*string == '\0')
		return NULL;
	else
		return (char*)string;/*      const char* -> char*            */
}

size_t getStrListFromText(const char* text, char* pt[], size_t n)
{
	char* p = text;
	pt[0] = p;
	size_t i = 1;
	for (; (*p) and i < n; p++)
		if (*p == '\n') {
			pt[i++] = p + 1;
			*p = '\0';
		}
	return i;
}

/* bug in 80 */
void copyStrArray(char str[][80], char* pt[], size_t row)
{
	for (size_t i = 0; i < row; i++)
		strncpy(str[i], pt[i], 80);
}

size_t getWordsFromLine(const char* line, char* pt[], size_t n)
{
	char* p = line;
	pt[0] = p;
	size_t i = 1;
	for (; (*p) and i < n; p++)
		if (isspace(*p)) {
			pt[i++] = p + 1;
			*p = '\0';
		}
	for (; i < n; i++)
		pt[i] = NULL;
	return i;
}

void sort_int(int ar[], size_t n)
{
	int temp;
	for (size_t i=0; i < n - 1; ++i)
		for (size_t j = i + 1; j < n; ++j)
			if (ar[i] < ar[j]) {
				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
}

void print_intVec(int ar[], size_t n, size_t line_num)
{
	for (size_t i = 0; i < n; ++i) {
		if (i + 1 not_eq n)
			printf("%3d,", ar[i]);
		else
			printf("%3d.", ar[i]);
		if (i % line_num == (line_num -1))
			putchar('\n');
	}
	putchar('\n');
}


