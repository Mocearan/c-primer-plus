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
	for (; stdinBuffer[i] != ' '&&stdinBuffer[i] != '\0'; InFir[i] = stdinBuffer[i], ++i)
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

double_t* getNFloat(const char* stdinBuf,const size_t count) {
	char* pBuf = stdinBuf;
	size_t len = count;
	double_t floats[16] = { 0.0 };
	size_t num = 0;
	while (num < count) {
		floats[num++]=getFloat(&pBuf);
	}
	return floats;
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