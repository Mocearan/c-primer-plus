#include "subjectHelper.h"

void stream_initor(stream_t* stream, size_t bytes_len) {
	stream->stream = (char*)malloc(bytes_len * sizeof(char));
	memset(stream->stream, 0x00, bytes_len * sizeof(char));
	stream->len = 0;
	stream->capacity = bytes_len;

	return;
}

stream_t* stream_create(size_t bytes_len) {
	stream_t * stream = (stream_t*)malloc(sizeof(stream_t));
	stream_initor(stream, bytes_len);
	return stream;
}

void stream_clear(stream_t* stream) {
	memset(stream->stream, 0x00, stream->len * sizeof(char));
	stream->len = 0;
	return;
}

void stream_destroy(stream_t* stream) {
	if (stream->stream) {
		free(stream->stream);
		stream->stream = NULL;
	}
	if (stream) {
		free(stream);
		stream = NULL;
	}

	return;
}

void restoreInput(char firstCh, stream_t* stream, INT8 end_flag) {
	char ch;
	//char* temp = (char*)malloc(128*sizeof(char));
	//memset(temp, 0x00, 128 * sizeof(temp));
	char temp[128] = { 0 };
	size_t i = 0;

	temp[0] = firstCh;
	while ((ch = getchar()) != end_flag)
		temp[++i] = ch;
	strncpy(stream->stream, temp, 128);
	stream->len = i;

	return;
}

result_info_t* subject_service(stream_t* stream, INT8 end_flag) {
	char cmd;
	char ch;
	result_info_t* result = result_info_create();

	scanf("%c", &cmd);
	if ('\t' == cmd || 32 == cmd)
	{
		while ((ch = getchar()) != '\n');
		result->result_No = BREAK;
		strcpy(result->result_info, "break the loop.");
	}
	else if ('\n' == cmd)
	{
	Lab_Continue:
		result->result_No = CONTINUE;
		strcpy(result->result_info, "continue the loop");
	}
	else
	{
		restoreInput(cmd, stream,end_flag);
		result->result_No = NOTHING;
		strcpy(result->result_info, "nothing to do.");
	}

	return result;
}

void subjectBash(const char* bash_tips, ...) {
	va_list va,vb;
	va_start(va, bash_tips);
	va_copy(vb, va);
	typedef void(*FUNC)(const stream_t*);
	FUNC func
		= va_arg(va, FUNC);
	typedef void(*SERVICE)(void);
	SERVICE service = va_arg(vb, SERVICE);

	if (va_arg(va,char*) == BASH_INTERFACE) {
		stream_t* input_stream = stream_create(BASH_CMD_LEN);
		result_info_t* result = NULL;
		INT8 flag = va_arg(va, INT8);

		while (printf("%s", bash_tips)) {
			result = subject_service(input_stream, flag);
  			if (result->result_No == BREAK) {
				result_info_destroy(result);
				break;
			}
			else if (result->result_No == CONTINUE) {
				result_info_destroy(result);
				continue;
			}

			(*func)(input_stream);
			stream_clear(input_stream);
		}
		stream_destroy(input_stream);
	}
	else {

		printf("%s", bash_tips);
		(*service)();
	}
}

