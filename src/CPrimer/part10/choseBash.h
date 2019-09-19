#ifndef __PART_9_H__
#define __PART_9_H__

#include "common.h"
#include "tool.h"
#include "subject.h"
/*
	chose one subject display on shell.
*/
void choseSubject(int Subject);

/*
	bash for loop.
	Handle input buffering issues.
*/

void bashRunv2();

#define BASH_CMD_LEN 128u
//const size_t bash_cmd_len = 128u;

size_t cmdAttach(const char first, char* str_attach);
result_info_t* cmd_service(char* tempBuffer, size_t len);



#endif // !__PART_1_H__
