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