#include "tools.h"

void restoreSingleLineInput(char** rearBuf, char* firstCh) {
	char* temp = (char*)malloc(1024 * sizeof(char));

	(*rearBuf)[0] = *firstCh;
	gets(temp);
	strcat(*rearBuf, temp);

	free(temp);
}

//void restoreMultiLineInput(char** rearBuf, char* firstCh) {
//	char ch = 0;
//	size_t len = 1;
//
//	(*rearBuf)[0] = *firstCh;
//	while ((ch = getchar()) != SPACE_STOP) {
//		(*rearBuf)[len++] = ch;
//	}
//	(*rearBuf)[len] = STOP;
//}

result_info_t* inputControlRestore(char** tempBuffer, char* firstCh) {

	result_info_t* result = (result_info_t*)malloc(sizeof(result_info_t));
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
	else {// first charactor is not a command. restore input buffer.
		restoreSingleLineInput(tempBuffer, firstCh);
		result->result_No = NOTHING;
		strcpy(result->result_info, "nothing to do.");
	}

	return result;

}

result_info_t* inputControlMultiRestore(char* input) {
	result_info_t* result = (result_info_t*)malloc(sizeof(result_info_t));
	result->result_info = (char*)malloc(128 * sizeof(char));
	result->info_len = 128 * sizeof(char);
	memset(result->result_info, 0x00, result->info_len);

	char ch = 0;
	size_t len = 0u;


	while ((ch = getchar()) != SPACE_STOP) {
		input[len++] = ch;
	}
	input[len] = SPACE_STOP;

	char* firstCh = input;
	getchar();
	if (SPACE_STOP == *firstCh)//tab
	{
		result->result_No = BREAK;
		strcpy(result->result_info, "break the loop");
	}
	else if (LINE_BREAK == *firstCh)//[enter]
	{
		result->result_No = CONTINUE;
		strcpy(result->result_info, "continue the loop");
	}
	else {// first charactor is not a command. restore input buffer.
		fflush(stdin);
		result->result_No = NOTHING;
		strcpy(result->result_info, "nothing to do.");
	}

	return result;

}

result_info_t* inputControlFlush(char* firstCh) {

	result_info_t* result = (result_info_t*)malloc(sizeof(result_info_t));
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
		char ch = 0;
		while ((ch = getchar()) != '\n');
		result->result_No = NOTHING;
		strcpy(result->result_info, "nothing to do.");
	}

	return result;
}

bool isPrime(bool isLog, unsigned long num, unsigned long* divs, size_t* len) {
	bool _isPrime = false;
	unsigned div = 0lu;
	size_t count = 0u;
	for (div = 2, _isPrime = true; (div * div) <= num; ++div) {
		if (num % div == 0) {
			if (divs != NULL) {  //不传出约束集
				if ((div * div) != num) {
					divs[count++] = div;
					divs[count++] = num / div;
					LOG(isLog, "%lu is divisible by %lu and %lu.\n", num, div, num / div);
				}
				else {
					divs[count++] = div;
					LOG(isLog, "%lu is divisible by %lu.\n", num, div);
				}
			}

			_isPrime = false;	//不是素数
		}
	}
	if(len != NULL) //不传出约束集
		*len = count;
	if (_isPrime)
		LOG(isLog, "%lu is prime.\n", num);

	return _isPrime;
}

void word_info_initor(word_info_t* w_info){
	w_info->ch_num = 0u;
	w_info->word_num = 0u;
	w_info->partial_num = 0u;
	w_info->line_num = 0u;
}

#include <ctype.h>
word_info_t* StatisticPart(const char * part)
{
  	word_info_t* words = (word_info_t*)malloc(sizeof(word_info_t));
	word_info_initor(words);
	
	char ch = 0;	// 读入字符
	char prev = '\n';	//读入的前一个字符,用于识别完整的行
	bool inword = false;	//如果c在单词中，inword == true


	while ((ch = *part++) != STOP) {
		++words->ch_num;		//	统计字符
		if (ch == '\n')
			++words->line_num;	//统计行
		if (!isspace(ch) && !inword) {
			inword = true;		//新单词
			++words->word_num;	//统计单词
		}
		if (isspace(ch) && inword) 
			inword = false;		//单词末尾
		
		prev = ch;		//保存字符的值
	}

	if (prev != '\n')
		++words->partial_num;

	return words;
}

void space_info_initor(space_info_t * space)
{
	space->n_space = 0u;
	space->n_tab = 0u;
	space->n_lineBreak = 0u;
	space->n_another = 0u;
}

space_info_t * StatisticSpace(const char * part)
{
	space_info_t* space = (space_info_t*)malloc(sizeof(space_info_t));
	space_info_initor(space);

	char ch = 0;	// 读入字符

	//printf("%s", part);
	while ((ch = *part++) != SPACE_STOP) {
		if (isspace(ch)) {
			if (ch == SPACE)
				++space->n_space;
			else if (ch == TAB)
				++space->n_tab;
			else if (ch == LINE_BREAK)
				++space->n_lineBreak;
		}
		else
			++space->n_another;
	}

	return space;
}


void getIntArray(const char* stdinBuffer, int* outArr, size_t* len) {
	char intStr[16] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	for (; stdinBuffer[i] != '\0' && stdinBuffer[i] != SPACE_STOP; ++i) {
		if (stdinBuffer[i] != ' ')
			intStr[k++] = stdinBuffer[i];
		else {
			outArr[j++] = atoi(intStr);
			memset(intStr, 0x00, sizeof(intStr));
			k = 0;
		}
	}
	outArr[j] = atoi(intStr); //Handle the last int
	*len = j;
}

void odd_even_info_initor(odd_even_info_t * oven)
{
	oven->n_oddSize = 0u;
	oven->odd_average = 0.0f;
	oven->n_evenSize = 0u;
	oven->even_average = 0.0f;
	return;
}

odd_even_info_t * StatisticOddEven(const int * IntSet)
{
	odd_even_info_t* oden = (odd_even_info_t*)malloc(sizeof(odd_even_info_t));
	odd_even_info_initor(oden);

	int index = 0;
	size_t len = 0u;
	while ((index = IntSet[len++]) != SPACE_STOP) {
		if (index % 2 == 1) {
			oden->odd_average = (oden->odd_average * (++oden->n_oddSize-1) + index) / oden->n_oddSize;
		}
		else {
			oden->even_average = (oden->even_average * (++oden->n_evenSize-1) + index) / oden->n_evenSize;
		}
	}
	return oden;
}

void in_replace_initor(in_replace_t * replace)
{
	replace->n_exclamation = 0u;
	replace->n_period = 0u;
	replace->sz_replaced = NULL;
}

in_replace_t * StaticInReplace(char * part)
{
	char* outPart = (char*)malloc(1024*sizeof(char));
	memset(outPart, 0x00, 1024 * sizeof(char));
	in_replace_t* replace = (in_replace_t*)malloc(sizeof(in_replace_t));
	in_replace_initor(replace);

	char index = 0;
	size_t len = 0u;
	while ((index = *part++) != SPACE_STOP) {
		if ('.' == index || '。' == index) {
			outPart[len++] = index;
			replace->n_period++;
		}
		else if ('!' == index || '！' == index) {
			outPart[len++] = index;
			outPart[len++] = index;
			replace->n_exclamation++;
		}
		else
			outPart[len++] = index;
	}
	replace->sz_replaced = outPart;

	return replace;
}

in_replace_t * StaticInReplaceBySwitch(char * part)
{
	char* outPart = (char*)malloc(1024 * sizeof(char));
	memset(outPart, 0x00, 1024 * sizeof(char));
	in_replace_t* replace = (in_replace_t*)malloc(sizeof(in_replace_t));
	in_replace_initor(replace);

	char index = 0;
	size_t len = 0u;
	while ((index = *part++) != SPACE_STOP) {
		switch (index)
		{
		case '.':
			outPart[len++] = index;
			replace->n_period++;
			break;
		case '。':
			outPart[len++] = index;
			replace->n_period++;
			break;
		case '!':
			outPart[len++] = index;
			outPart[len++] = index;
			replace->n_exclamation++;
			break;
		case '！':
			outPart[len++] = index;
			outPart[len++] = index;
			replace->n_exclamation++;
			break;
		default:
			outPart[len++] = index;
			break;
		}	
	}
	replace->sz_replaced = outPart;

	return replace;
}

void check_substr_initor(check_substr_t * sub)
{
	sub->n_count = 0u;
}

check_substr_t * checkSubstr(const char *input, const char* sub)
{
	check_substr_t* info = (check_substr_t*)malloc(sizeof(check_substr_t));
	check_substr_initor(info);

	size_t sub_len = 0u;
	while (sub[sub_len++] != SPACE_STOP);
	sub_len--;


	char index = *input;
	size_t len = 0u;
	while ((index = *input++) != SPACE_STOP)
	{
		if (index != sub[len++]) {
			len = 0u;
			continue;
		}

		if (len == sub_len) {
			info->n_count++;
			len = 0u;
		}
		
	}

	return info;
}

void tax_info_initor(tax_info_t * tax)
{
	tax->n_income = 0.0f;
	tax->n_tax = 0.0f;
	tax->n_total = 0.0f;
}

tax_info_t * incomoHelper(double work_hours)
{
	tax_info_t* tax_info = (tax_info_t*)malloc(sizeof(tax_info_t));
	tax_info_initor(tax_info);

	double total_income = 0;
	double tax = 0;
	double  net_income = 0;

	if (work_hours > 40)
	{
		work_hours = (work_hours - 40) * 1.5 + 40;
	}

	total_income = work_hours * 1000;
	if (total_income <= 300)
	{
		tax = total_income * SUB_RATE1;
		net_income = total_income - tax;
	}
	else if (total_income <= 450)
	{
		tax = 300 * SUB_RATE1 + (total_income - 300) * SUB_RATE2;
		net_income = total_income - tax;
	}
	else
	{
		tax = 300 * SUB_RATE1 + 150 * SUB_RATE2 + (total_income - 450) * SUB_RATE3;
		net_income = total_income - tax;
	}

	tax_info->n_total = total_income;
	tax_info->n_tax = tax;
	tax_info->n_income = net_income;

	return tax_info;
}


menu_info_t* menu_inputControl(char* firstCh) {
	menu_info_t* result = (menu_info_t*)malloc(sizeof(menu_info_t));
	result->result_info = (char*)malloc(128 * sizeof(char));
	result->info_len = 128 * sizeof(char);
	memset(result->result_info, 0x00, result->info_len);

	scanf("%c", firstCh);

	if ('5' == *firstCh)
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

bool s8_menu()
{
	printf("[ 8 ]\n");
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $8.75/hr\t\t\t2) $9.33/hr\n");
	printf("3) $10.00/hr\t\t\t4) $11.20/hr\n");
	printf("5) quit\n");
	printf("****************************************************************\n");
	printf("please enter your choice to specified your hourly wage:");

	return true;
}

void tax_service(int option) {
	double hourly_wage = 0.0f;
	size_t hour = 0u;
	char* tempBuffer = (char*)malloc(32 * sizeof(char));
	memset(tempBuffer, 0x00, 32 * sizeof(char));
	int* out_array = (int*)malloc(128 * sizeof(int));
	memset(out_array, 0, 128 * sizeof(int));
	size_t len = 0;

	result_info_t* result_x = NULL;
	tax_info_t* tax = NULL;

	switch (option)
	{
	case 1:
		hourly_wage = 8.75f;
		break;
	case 2:
		hourly_wage = 9.33f;
		break;
	case 3:
		hourly_wage = 10.00f;
		break;
	case 4:
		hourly_wage = 11.20f;
		break;
	default:
		hourly_wage = 8.5f;
		break;
	}

	printf(" Enter a number to specified your weekly working hour( # to terminate):\n");
	result_x = inputControlMultiRestore(tempBuffer);
	memset(out_array, 0, 128 * sizeof(int));
	getIntArray(tempBuffer, out_array, &len);
	hour = out_array[0];

	tax = incomoHelper(hour);
	printf("total income = %lf, tax = %lf, net income = %lf\n", tax->n_total, tax->n_tax, tax->n_income);

	if (result_x->result_info)
		free(result_x->result_info);
	if (result_x)
		free(result_x);
	if (tempBuffer)
		free(tempBuffer);
	if (out_array)
		free(out_array);
	if (tax)
		free(tax);

}

bool s10_menu()
{
	printf("[ 10 ]\n");
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the tax type or action:\n");
	printf("1) single\t\t\t2) household\n");
	printf("3) married,shared\t4) married,divorced\n");
	printf("5) quit\n");
	printf("****************************************************************\n");
	printf("please enter your choice to specified your hourly wage:");

	return true;
}

void s10_tax_service(int option) {
	double base_tax = 0.0f;
	double income = 0.0f;
	double total_tax = 0.0f;
	char* tempBuffer = (char*)malloc(32 * sizeof(char));
	memset(tempBuffer, 0x00, 32 * sizeof(char));
	int* out_array = (int*)malloc(128 * sizeof(int));
	memset(out_array, 0, 128 * sizeof(int));
	size_t len = 0;

	result_info_t* result_x = NULL;

	switch (option)
	{
	case 1:
		base_tax = 17850.00f;
		break;
	case 2:
		base_tax = 23900.00f;
		break;
	case 3:
		base_tax = 29750.00f;
		break;
	case 4:
		base_tax = 14875.00f;
		break;
	default:
		base_tax = 17850.00f;
		break;
	}

	printf("	Enter a number to specified your income( # to terminate):\n");
	result_x = inputControlMultiRestore(tempBuffer);
	memset(out_array, 0, 128 * sizeof(int));
	getIntArray(tempBuffer, out_array, &len);
	income = out_array[0];
	if ((income - base_tax) > 0)
		total_tax = base_tax * 0.15 + (income - base_tax)*0.28;
	else
		total_tax = income * 0.15;
	
	printf("total tax =  %lf\n", total_tax);

	if (result_x->result_info)
		free(result_x->result_info);
	if (result_x)
		free(result_x);
	if (tempBuffer)
		free(tempBuffer);
	if (out_array)
		free(out_array);
}




result_info_t* chose_inputControl(char* cmd) {
	result_info_t* result = (result_info_t*)malloc(sizeof(result_info_t));
	result->result_info = (char*)malloc(128 * sizeof(char));
	result->info_len = 128 * sizeof(char);
	memset(result->result_info, 0x00, result->info_len);

	scanf("%c", cmd);

	if ('q' == *cmd)
	{
		getchar();
		result->result_No = BREAK;
		strcpy(result->result_info, "break the loop");
	}
	else if ('\n' == *cmd)
	{
		result->result_No = CONTINUE;
		strcpy(result->result_info, "continue the loop");
	}
	else {
		char ch = 0;
		while ((ch = getchar()) != '\n');
		//fflush(stdin); // 只要最近一次缓冲区操作不是输入操作，才可以刷新输入缓冲区
		result->result_No = NOTHING;
		strcpy(result->result_info, "nothing to do.");
	}

	return result;
}

order_t* order_initor()
{
	order_t* order = (order_t*)malloc(sizeof(order_t));
	order->artichoke_pounds = 0.0f;
	order->beet_pounds = 0.0f;
	order->carrot_pounds = 0.0f;
	order->discount = 1.0f;
	order->freight_cost = 0.0f;
	order->order_cost = 0.0f;
	order->total_cost = 0.0f;
	order->total_pounds = 0.0f;
	order->vagetables_cost = 0.0f;
	return order;
}

void order_destroy(order_t* order) {
	if (order)
		free(order);
}

double_t getFloatFromBytes(const char * input)
{
	char InFloat[32] = { 0 };
	int i = 0;
	for (; input[i] != ' ' and input[i] != '\0'and input[i] != SPACE_STOP; InFloat[i] = input[i], ++i)
		;
	return atof(InFloat);
}

void order_pounds_calc(order_t * order)
{
	order->total_pounds = order->artichoke_pounds + order->beet_pounds + order->carrot_pounds;
}

void vagetable_cost(order_t * order)
{
	order->vagetables_cost = order->artichoke_pounds * ARTICHOKE_PRICE \
		+ order->beet_pounds * BEET_PRICE \
		+ order->carrot_pounds * CARROT_PRICE;
}

bool s11_menu() {
	printf("[ 11 ]\n");
	printf("*****************************************************************\n");
	printf("Please select the goods you want to purchase or action:\n");
	printf("a) artichoke\t\t\tb) beet\n");
	printf("c) carrot\t\n");
	printf("q) quit\n");
	printf("****************************************************************\n");
	return true;
}

double_t weight_inputControl() {
	char* inputBuffer = (char*)malloc(32 * sizeof(char));
	memset(inputBuffer, 0x00, 32 * sizeof(char));

	char ch = 0;
	size_t len = 0u;

	while ((ch = getchar()) != '\n') {
		inputBuffer[len++] = ch;
	}
	inputBuffer[len] = SPACE_STOP;

	double_t pounds = getFloatFromBytes(inputBuffer);
	if (inputBuffer)
		free(inputBuffer);
	return pounds;
}

void WeightPlatform(order_t* order, char V_type) {
	printf("please enter weight you want buy of ");
	double_t pounds = 0.0f;
	switch (V_type)
	{
	case  'a':
		printf("artichoke:");
		pounds = weight_inputControl();
		order->artichoke_pounds += pounds;
		break;
	case 'b':
		printf("beet:");
		pounds = weight_inputControl();
		order->beet_pounds += pounds;
		break;
	case 'c':
		printf("carrot:");
		pounds = weight_inputControl();
		order->carrot_pounds += pounds;
		break;
	default:
		break;
	}

	order_pounds_calc(order);
	
}

void settlementPlatform(order_t* order) {
	// vagetable cost calc
	vagetable_cost(order);
	// discount cost
	if (order->vagetables_cost > 100.00)
		order->discount -= DISCOUNT;
	// freight calc
	if (order->total_pounds <= 0.0)
		order->freight_cost = 0.0;
	else if (order->total_pounds <= 5.0)
		order->freight_cost = 6.5;
	else if (order->total_pounds <= 20.0)
		order->freight_cost = 14.0;
	else
		order->freight_cost = 14.0 + (order->total_pounds - 20.0)* 0.5;
	// order cost
	order->order_cost = order->vagetables_cost + order->freight_cost;
	// total cost
	order->total_cost = order->order_cost * order->discount;
}

void order_show(order_t* order) {
	printf("\n=================[ order info ]=========================\n");
	printf("*******[ vagetables price ]***********\n");
	printf("[vagetables type] \t\t\t [vagetables pounds]\n");
	printf("[ artichoke ] : %.2lf\t\t\t\t%.2lf\n", ARTICHOKE_PRICE,order->artichoke_pounds);
	printf("[ beet ] : %.2lf\t\t\t\t\t%.2lf\n", BEET_PRICE,order->beet_pounds);
	printf("[ carrot ] : %.2lf\t\t\t\t%.2lf\n", CARROT_PRICE, order->carrot_pounds);
	printf("**************************************\n");
	printf("{ order total pounds } : %lf\n", order->total_pounds);
	printf("{ order vagetables cost } : %lf\n", order->vagetables_cost);
	printf("{ order freight cost } : %lf\n", order->freight_cost);
	printf("{ order cost } : %lf\n", order->order_cost);
	printf("{ order discount } : %lf\n", order->discount);
	printf("{ order total cost } : %lf\n", order->total_cost);
	printf("========================================================\n\n");
}

void ChoosePlatform() {
	char cmd = 0;
	result_info_t* result = NULL;
	order_t* order = order_initor();

	while (s11_menu()) {
		result = chose_inputControl(&cmd);
		if (result->result_No == BREAK)
			break;
		if (result->result_No == CONTINUE)
			continue;

		//printf("%c\n\n\n\n", cmd);    // debug
		if (cmd != 'a' and cmd != 'b' and cmd != 'c' and cmd != 'q') {
			printf("[ ========= the cmd you input out of range ========== ]");
			continue;
		}

		WeightPlatform(order, cmd);
	}
	settlementPlatform(order);
	order_show(order);
	order_destroy(order);
	if (result->result_info)
		free(result->result_info);
	if (result)
		free(result);
	return;
}
