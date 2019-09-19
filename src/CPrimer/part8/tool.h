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

#endif // !__TOOL_H__
