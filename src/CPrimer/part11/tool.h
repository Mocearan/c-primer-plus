#ifndef __TOOL_H__
#define __TOOL_H__

#include "common.h"

enum result_No { BREAK = -1, CONTINUE = 0, NOTHING = 1 };

typedef struct RESULT_INFO {
	int		result_No;
	char*	result_info;
	size_t		info_len;
}result_info_t;

void result_info_initor(result_info_t* result);

result_info_t* result_info_create();

void result_info_destroy(result_info_t* result);

double_t get_float(void);
double_t getFloat(char** Buffer);
double_t* getNFloat(const char* stdinBuf, const size_t count);
size_t getFloatArray(const char* stdinBuffer, double_t* outArr);
void getTwoFloat(const char* stdinBuffer, double* outFir, double* outSec);

int getInteger(void);
size_t getIntArray(const char* stdinBuffer, int* outArr);


char* s_gets(char* st, size_t n);

void put_no_n(const char* string);
size_t put_len(const char* string);

void fit(char* string, size_t size);// shorten string length

void str_toupper(char* str);
void str_tolower(char* str);

void ststr(char* strings[], int num);
int PunctCont(const char* str);

char* strblk(char* string);

size_t getStrListFromText(const char* text, char* pt[], size_t n);
void copyStrArray(char str[][80], char* pt[], size_t row);

size_t getWordsFromLine(const char* line, char* pt[], size_t n);
#endif // !__TOOL_H__
