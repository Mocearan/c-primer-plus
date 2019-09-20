#ifndef __SUBJECT_HELPER_H__
#define __SUBJECT_HELPER_H__

#include "tool.h"

enum BASH_MODE { BASH_INTERFACE = 1, BASH_DEFAULT = 0 };

enum BASH_END { BASH_LINE = '\n', BASH_TEXT = EOF };

#define BASH_CMD_LEN 128u

typedef struct STREAM_T {
	char* stream;
	size_t len;
	size_t capacity;
}stream_t;

void stream_initor(stream_t* stream, size_t bytes_len);

stream_t* stream_create(size_t bytes_len);

void stream_clear(stream_t* stream);


void stream_destroy(stream_t* stream);

void restoreInput(char firstCh, stream_t* stream, INT8 end_flag);

result_info_t* subject_service(stream_t* stream, INT8 end_flag);

void subjectBash(const char* bash_tips, ...);

#endif // !__SUBJECT_HELPER_H__
