#include "choseBash.h"
#include "tool.h"

void choseSubject(int Subject)
{
	switch (Subject)
	{
	case 1:
		Subject_1();
		break;
	case 2:
		Subject_2();
		break;
	case 3:
		Subject_3();
		break;
	case 4:
		Subject_4();
		break;
	case 5:
		Subject_5();
		break;
	case 6:
		Subject_6();
		break;
	case 7:
		Subject_7();
		break;
	case 8:
		Subject_8();
		break;
	case 9:
		Subject_9();
		break;
	case 10:
		Subject_10();
		break;
	case 11:
		Subject_11();
		break;
	default:
		printf("{** Error Chose **}  without this subject\n");
		break;
	}
	return;
}


size_t cmdAttach(const char first, char* str_attach) {
	char ch;
	int res = 0;
	size_t i;

	if ('0' > first or '9' < first) {
		char ch;
		while ((ch = getchar()) != '\n');
		goto Lab_return;
	}
	else {
		str_attach[0] = first;
		++res;
	}

	for (i = 1; (ch = getchar()) != '\n'; ++i)
		if ('0' > ch or '9' < ch) {
			while ((ch = getchar()) != '\n');
			res = 0;
			break;
		}
		else {
			++res;
			str_attach[i] = ch;
		}

Lab_return:
	return res;
}

result_info_t* cmd_service(char* tempBuffer, size_t len) {
	char subject = 0;
	char ch;
	result_info_t* result = result_info_create();

	scanf("%c", &subject);
	if ('\t' == subject || 32 == subject)
	{
		while ((ch = getchar()) != '\n');
		result->result_No = BREAK;
		strcpy(result->result_info, "break the loop.");
	}
	else if ('\n' == subject)
	{
	Lab_Continue:
		result->result_No = CONTINUE;
		strcpy(result->result_info, "continue the loop");
	}
	else
	{
		if (cmdAttach(subject, tempBuffer))
			choseSubject(atoi(tempBuffer));
		else {
			printf("{** Error Input **}  Subject number must consist entirely of positive integers.\n");
			goto Lab_Continue;
		}
		//result->result_No = NOTHING;
		//strcpy(result->result_info, "nothing to do.");
	}

	return result;
}

void bashRunv2() {
	char* tempBuffer = (char*)malloc(BASH_CMD_LEN * sizeof(char));
	memset(tempBuffer, 0x00, BASH_CMD_LEN * sizeof(char));
	result_info_t* result = NULL;
	//bash here
	while (printf("[chose bash] Please enter a number of int to choose a subject(space/tab to quit):"))
	{
		//choseSubject(atoi(subject)); atoi for string
		result = cmd_service(tempBuffer, BASH_CMD_LEN);
		if (result->result_No == BREAK) {
			result_info_destroy(result);
			break;
		}
		else if (result->result_No == CONTINUE) {
			result_info_destroy(result);
			continue;
		}
	}

	if (tempBuffer)
		free(tempBuffer);
	return;
}
