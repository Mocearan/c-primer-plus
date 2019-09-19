
#include"subjects.h"

void restoreInput(char** rearBuf, char* firstCh) {
	char* temp = (char*)malloc(1024 * sizeof(char));
	
	(*rearBuf)[0] = *firstCh;
	gets(temp);
	strcat(*rearBuf, temp);
	
	free(temp);
}

result_info* inputControlRestore(char** tempBuffer, char* firstCh) {

	result_info* result = (result_info*)malloc(sizeof(result_info));
	result->result_info = (char*)malloc(128 * sizeof(char));
	result->info_len = 128 * sizeof(char);
	memset(result->result_info, 0x00, result->info_len);

	scanf("%c", firstCh);// gets firdt charactor.
	if ('\t' == *firstCh || 32 == *firstCh)//tab
	{
		getchar();
		result->result_No = BREAK;
		strcpy(result->result_info, "break the loop");
	}
	else if ('\n' == *firstCh)//[enter]
	{
		result->result_No = CONTINUE;
		strcpy(result->result_info, "continue the loop");
	}
	else{// first charactor is not a command. restore input buffer.
		restoreInput(tempBuffer, firstCh);
		result->result_No = NOTHING;
		strcpy(result->result_info, "nothing to do.");
	}

	return result;

}

result_info* inputControlFlush( char* firstCh) {

	result_info* result = (result_info*)malloc(sizeof(result_info));
	result->result_info = (char*)malloc(128 * sizeof(char));
	result->info_len = 128 * sizeof(char);
	memset(result->result_info, 0x00, result->info_len);

	scanf("%c", firstCh);

	if ('\t' == *firstCh || 32 == *firstCh)
	{
		getchar();
		result->result_No = BREAK;
		strcpy(result->result_info, "break the loop");
	}
	else if ('\n' == *firstCh)
	{
		result->result_No = CONTINUE;
		strcpy(result->result_info, "continue the loop");
	}
	else {
		//gets();
		fflush(stdin);
		result->result_No = NOTHING;
		strcpy(result->result_info, "nothing to do.");
	}

	return result;
}

void Subject_1(void){

	//char arr[26] = { 'a' }; err init , only [char] arr can be init for ['0']
	char arr[26] = { 0 };
	printf("[subject 1]\n");
	for (int i = 0; i < 26; ++i)
	{
		arr[i] = 'a' + i;
		printf("%c ", arr[i]);
	}
	printf("\n");

	return;
}

void Subject_2(void){

	char ch = 0;
	char* tempBuffer = NULL;
	tempBuffer = (char*)malloc(1024 * sizeof(tempBuffer));
	memset(tempBuffer, 0x00, sizeof(tempBuffer));
	result_info* result = NULL;

	while (printf("[2] please enter a charactor(space/tab to quit):"))
	{
		result = inputControlRestore(&tempBuffer, &ch);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 2]\n");
		for (int i = 0; i < 5; printf("\n"), ++i)
			for (int j = 0; j <= i; printf("%s", tempBuffer), ++j)
				;
		memset(tempBuffer, 0x00, sizeof(tempBuffer));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0x00, sizeof(result));
	}
	if (tempBuffer != NULL)
		free(tempBuffer);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);

	return;
}

void Subject_3(void)
{
	char ch = 0;
	result_info* result = NULL;
	while (printf("[3] please enter a charactor(space/tab to qut):"))
	{
		result = inputControlFlush(&ch);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 3]\n");
		if (65 > ch || (90 < ch && 97 > ch) || 122 < ch)
			continue;
		else if (90 > ch)
			for (int i = 0; i <= ch - 65; printf("\n"), ++i)
				for (int j = 0; j <= i; printf("%c", ch - j), ++j)
					;
		else
			for (int i = 0; i <= ch - 97; printf("\n"), ++i)
				for (int j = 0; j <= i; printf("%c", ch - j), ++j)
					;

		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));
	}
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_4(void)
{
	char ch = 0;
	result_info* result = NULL;
	while (printf("[4] please enter a charactor(space/tab to qut):"))
	{
		result = inputControlFlush(&ch);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 4]\n");
		if (65 > ch || (90 < ch && 97 > ch) || 122 < ch)
			continue;
		else if (91 > ch)
			for (int i = 0;; printf("\n"), ++i)
				//for(int j=0;j<=i;printf("%c",ch+i+j),++j)
			{
				if (ch > 90) break;
				for (int j = 0; j <= i; printf("%c", ch++), ++j)
					if (ch > 90) break;
			}
		else
			for (int i = 0;; printf("\n"), ++i)
			{
				if (ch > 122) break;
				for (int j = 0; j <= i; printf("%c", ch++), ++j)
					if (ch > 122) break;
			}

		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));

	}
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_5(void)
{
	char ch;
	int lineNum = 0;
	result_info* result = NULL;
	while (printf("[5] please enter a charactor(space/tab to quit):"))
	{
		result = inputControlFlush(&ch);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		if (65 > ch || (90 < ch && 97 > ch) || 122 < ch) {
			printf("[debug: continue to while\b]");
			continue;
		}
		else
		{

			printf("please enter a number of int to set line number:");
			if (0 == scanf("%d%*[^\n]%*c", &lineNum))
			{
				printf("enter err!re-enter!\n");
				scanf("%*[^\n]%*c");
				continue;
			}
			//getchar();

			if (91 > ch) {
				for (int i = 0; i < lineNum; ++i)
				{
					if (ch + i > 90)
					{
						lineNum = i;
						break;
					}
				}
				for (int i = 0; i < lineNum; printf("\n"), ++i)
				{
					for (int j = 0; j < lineNum - i - 1; printf(" "), ++j)
						;
					for (int j = 0; j < i + 1; printf("%c", ch + j), ++j)
						;
					for (int j = 0; j < i; printf("%c", ch + i - j - 1), ++j)
						;
				}
			}
			else {
				for (int i = 0; i < lineNum; ++i)
				{
					if (ch + i > 122)
					{
						lineNum = i;
						break;
					}
				}
				for (int i = 0; i < lineNum; printf("\n"), ++i)
				{
					for (int j = 0; j < lineNum - i - 1; printf(" "), ++j)
						;
					for (int j = 0; j < i + 1; printf("%c", ch + j), ++j)
						;
					for (int j = 0; j < i; printf("%c", ch + i - j - 1), ++j)
						;
				}
			}
		}

		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));
	}
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;

}

void Subject_6(void)
{
	printf("[subject 6]\n");
	printf("get two num for tab start and end,print a tab include square and cube\n");
	printf("too simple to implement!\n");
}

void Subject_7(void)
{
	char cmd;
	char* word = (char*)malloc(24 * sizeof(char));
	memset(word, 0x00, sizeof(word));
	result_info* result = NULL;
	while (printf("[7] please enter a word(space/tab to quit):"))
	{
		result = inputControlRestore(&word, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 7]\n");
		for (int i = 0; i < strlen(word); printf("%c", word[strlen(word) - i - 1]), ++i)
			;
		printf("\n");
		memset(word, 0x00, sizeof(word));
		memset(result->result_info, 0x00, result->info_len);
		memset(result,0, sizeof(result));
	}
	if (word != NULL)
		free(word);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_8(void)
{
	char cmd;
	char* inputBuffer = (char*)malloc(1024 * sizeof(char));
	memset(inputBuffer, 0x00, sizeof(inputBuffer));
	result_info* result = NULL;

	while (printf("[8] please enter two number of float(tab/space to quit)"))
	{
		result = inputControlRestore(&inputBuffer, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 8]\n");
		char first[1024] = { 0 };
		char second[1024] = { 0 };
		int i = 0;
		for (; inputBuffer[i] != ' '&&inputBuffer[i] != '\0'; first[i] = inputBuffer[i], ++i)
			;
		for (int j = 0; inputBuffer[i + 1] != '\0'; second[j] = inputBuffer[i + 1], ++i, ++j)
			;
		double Fir = atof(first);
		double Sec = atof(second);
		//printf("%lf,%lf\n", Fir, Sec);
		if (IS_DOUBLE_ZERO(Sec)) {
			printf("The denominator is zero!\n");
			memset(inputBuffer, 0x00, sizeof(inputBuffer));
			continue;
		}
		printf("(%1f - %1f) / (%1f * %1f) = %lf\n", Fir, Sec, Fir, Sec, (Fir - Sec) / (Fir*Sec));

		memset(inputBuffer, 0x00, sizeof(inputBuffer));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));
	}
	if (inputBuffer != NULL)
		free(inputBuffer);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_9(void)
{
	printf("[subject 9]\n");
	printf("use a function encapsulate a procedure\n");
	printf("it's too easy to implement");
}

void Subject_10(void)
{
	char cmd = 0;
	char* inputBuffer = (char*)malloc(1024 * sizeof(char));
	memset(inputBuffer, 0x00, sizeof(inputBuffer));
	result_info* result = NULL;

	while (printf("[10] please enter two number of float(tab/space to quit)"))
	{
		result = inputControlRestore(&inputBuffer, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 10]\n");
		double Fir, Sec;
		getTwoFloat(inputBuffer, &Fir, &Sec);
		//printf("%lf,%lf\n", Fir, Sec);
		if (IS_DOUBLE_ZERO(Sec)) {
			printf("The denominator is zero!\n");
			memset(inputBuffer, 0x00, sizeof(inputBuffer));
			continue;
		}

		double sum = 0;
		for (int i = 0; (int)ceil(Fir) + i <= (int)floor(Sec); (sum += mySquare(ceil(Fir) + i)), printf("%lf\n",sum), ++i)
			;
		printf("The sum of the square from %lf to %lf is %d : ", Fir, Sec, (int)floor(sum));
		printf("\n");

		memset(inputBuffer, 0x00, sizeof(inputBuffer));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));
	}
	if (inputBuffer != NULL)
		free(inputBuffer);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_11(void)
{
	char cmd;
	char* input_stream = (char*)malloc(128 * sizeof(char));
	memset(input_stream, 0x00, sizeof(input_stream));
	int array_len = 0;
	int out_array[128] = { 0 };
	int len = -1;
	result_info* result = NULL;

	while (printf("[11] please enter a int array,split by space(space/tab to quit):"))
	{
		result = inputControlRestore(&input_stream, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 11]\n");
		getIntArray(input_stream, out_array, &len);
		for (; --len >= 0; printf("%d ", out_array[len]));
		printf("\n");

		memset(input_stream, 0x00, sizeof(input_stream));
		memset(out_array, 0x00, sizeof(out_array));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));
	}
	if (input_stream != NULL)
		free(input_stream);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void  Subject_12(void) {
	char cmd;
	char* input_stream = (char*)malloc(128 * sizeof(char));
	memset(input_stream, 0x00, sizeof(input_stream));
	int out_array[128] = { 0 };
	int len = -1;
	result_info* result = NULL;

	unsigned items = 0;

	while (printf("[12] please enter a int num , Specifies the number of series terms(space/tab to quit):"))
	{
		result = inputControlRestore(&input_stream, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 12]\n");
		getIntArray(input_stream, out_array, &len);
		items = out_array[0];
		printf("the harmonic series sum of  %d items = %f\n", items, harmonic_series(items));
		printf("the alternating harmonic series sum of  %d items = %f\n", items, alternating_harmonic_series(items));

		memset(input_stream, 0x00, sizeof(input_stream));
		memset(out_array, 0x00, sizeof(out_array));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));
	}
	if (input_stream != NULL)
		free(input_stream);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void  Subject_13(void) {
	char cmd;
	char* input_stream = (char*)malloc(128 * sizeof(char));
	memset(input_stream, 0x00, sizeof(input_stream));
	int out_array[128] = { 0 };
	int len = -1;
	result_info* result = NULL;

	unsigned items = 0;
	unsigned* binary_arr = NULL;

	while (printf("[13] please enter a int num , Specifies the number of binary array(space/tab to quit):"))
	{
		result = inputControlRestore(&input_stream, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 13]\n");
		getIntArray(input_stream, out_array, &len);
		items = out_array[0];
		if (items > 0) {
			binary_arr = (int*)malloc(items * sizeof(unsigned));
			memset(binary_arr, 0x00, items * sizeof(unsigned));
			construct_binary_arr(binary_arr, items);
		}

		do{
			printf("items [%d] = %d\n", items - 1, binary_arr[items -1]);
		} while (--items);

		memset(input_stream, 0x00, sizeof(input_stream));
		memset(out_array, 0x00, sizeof(out_array));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));

		if (binary_arr)
			free(binary_arr);
	}
	if (input_stream != NULL)
		free(input_stream);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_14(void)
{
	char cmd;
	char* input_stream = (char*)malloc(128 * sizeof(char));
	memset(input_stream, 0x00, sizeof(input_stream));
	int out_array[128] = { 0 };
	int len = -1;
	result_info* result = NULL;

	unsigned* sum_arr = NULL;

	while (printf("[14] please enter a int array(space/tab to quit):"))
	{
		result = inputControlRestore(&input_stream, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 14]\n");
		getIntArray(input_stream, out_array, &len);
		if (len > 0) {
			sum_arr = (unsigned*)malloc(len * sizeof(unsigned));
			memset(sum_arr, 0x00, len * sizeof(unsigned));
		}

		for(size_t i = 0; i < len; ++i){
			printf("%d\t", out_array[i]);
			if (i > 0)
				sum_arr[i] = sum_arr[i - 1] + out_array[i];
			else
				sum_arr[i] = out_array[i];
		}
		printf("\n");
		for (size_t i = 0; i < len; ++i)
			printf("%d\t", sum_arr[i]);
		printf("\n");


		memset(input_stream, 0x00, sizeof(input_stream));
		memset(out_array, 0x00, sizeof(out_array));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));

		if (sum_arr)
			free(sum_arr);
	}
	if (input_stream != NULL)
		free(input_stream);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_15(void) {
	char cmd;
	char* inString = (char*)malloc(24 * sizeof(char));
	memset(inString, 0x00, sizeof(inString));
	result_info* result = NULL;
	while (printf("[15] please enter a string(space/tab to quit):"))
	{
		result = inputControlRestore(&inString, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 14]\n");
		for (int i = 0; i < strlen(inString); printf("%c", inString[strlen(inString) - i - 1]), ++i)
			;
		printf("\n");
		memset(inString, 0x00, sizeof(inString));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));
	}
	if (inString != NULL)
		free(inString);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_16(void) {
	const float Daphne_rate = 0.1f;
	const float Deirdre_rate = 0.05f;

	char cmd = 0;
	char* input_stream = (char*)malloc(128 * sizeof(char));
	memset(input_stream, 0x00, sizeof(input_stream));
	int out_array[128] = { 0 };
	int len = -1;
	result_info* result = NULL;

	double initial_amount = 0.0l;
	double Daphne_sum = 0.0l;
	double Deirdre_sum = 0.0l;

	while (printf("[16] please enter a int number to set the initial amount.(space/tab to quit):"))
	{
		result = inputControlRestore(&input_stream, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 16]\n");
		getIntArray(input_stream, out_array, &len);
		initial_amount = out_array[0];
		Daphne_sum = Deirdre_sum = initial_amount;

		size_t year = 0u;
		while (Deirdre_sum <= Daphne_sum){
			Daphne_sum += initial_amount * Daphne_rate;
			Deirdre_sum += Deirdre_sum * Deirdre_rate;
			++year;
		}
		printf("after [ %d ] year Deirdre's amount[ %lf ] beyond Daphne's amount[ %lf ].\n", year, Deirdre_sum, Daphne_sum);

		memset(input_stream, 0x00, sizeof(input_stream));
		memset(out_array, 0x00, sizeof(out_array));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));
	}
	if (input_stream != NULL)
		free(input_stream);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_17(void)
{
	const float annual_consume = 100000.0l;
	const float annual_rate = 0.08l;

	char cmd = 0;
	char* input_stream = (char*)malloc(128 * sizeof(char));
	memset(input_stream, 0x00, sizeof(input_stream));
	int out_array[128] = { 0 };
	int len = -1;
	result_info* result = NULL;

	double amount = 0.0l;

	while (printf("[17] please enter a int number to set the initial amount.(space/tab to quit):"))
	{
		result = inputControlRestore(&input_stream, &cmd);
		if (result->result_No == BREAK)
			break;
		else if (result->result_No == CONTINUE)
			continue;

		printf("[subject 17]\n");
		getIntArray(input_stream, out_array, &len);
		amount = (double)(out_array[0]);
		
		size_t year = 0u;
		while (amount > 0) {
			amount = amount *(1 + annual_rate) - annual_consume;
			++year;
		}
		printf("after [%d] year Lucky zero.\n", year);

		memset(input_stream, 0x00, sizeof(input_stream));
		memset(out_array, 0x00, sizeof(out_array));
		memset(result->result_info, 0x00, result->info_len);
		memset(result, 0, sizeof(result));
	}
	if (input_stream != NULL)
		free(input_stream);
	if (result->result_info != NULL)
		free(result->result_info);
	if (result != NULL)
		free(result);
	return;
}

void Subject_18(void)
{
	const size_t initial_num = 5;
	const size_t Dunbar_number = 150;
	size_t friend_number = initial_num;
	printf("[subject 18]\n");

	for (size_t i = 1; friend_number < Dunbar_number; ++i) {
		friend_number = (friend_number - i) * 2;
		printf("[ %d ] week have %d friends.\n", i, friend_number);
	}


}
