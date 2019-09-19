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
void getTwoFloat(const char* stdinBuffer, double* outFir, double* outSec);
int getInteger(void);
size_t getIntArray(const char* stdinBuffer, int* outArr);
#endif // !__TOOL_H__
