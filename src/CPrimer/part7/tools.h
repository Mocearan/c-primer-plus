#ifndef __TOOLS_H__
#define __TOOLS_H__

#include "common.h"

/*
	Processing input instruction.
	return : [struct] result info
*/
enum result_No { BREAK = -1, CONTINUE = 0, NOTHING = 1 };

typedef struct RESULT_INFO {
	int		result_No;
	char*	result_info;
	int		info_len;
}result_info_t;

/*
	param:
		[tempBuffer] : char**, out, input buffer data.
*/

/*
	get a stream from input stream.
*/
result_info_t* inputControlRestore(char** tempBuffer, char* firstCh);
result_info_t* inputControlMultiRestore(char* input);
/*
	get a charactor from input stream.
*/
result_info_t* inputControlFlush(char* firstCh);


//feature extraction

/*
	param:
		[rearBuf]: char ** in/out, Input stream data except the first character
		[firstCh]: char* in, first charactor in input buffer
*/
void restoreSingleLineInput(char** rearBuf, char* firstCh);




/*
	tools
*/

#define LOG(isLog,_Format, ...) isLog?printf(_Format, ##__VA_ARGS__):1


/*
	Parameter：
		isLog : 是否打开日志
		num:	待测数据
		divs：	除余约数的集合，如果是非素数，将返回所有约数的集合
		len：	约数集合的长度，共有多少约数
*/
bool isPrime(bool isLog, unsigned long num, unsigned long* divs, size_t* len);



#define STOP '|'

typedef struct WORD_INFO {
	size_t	ch_num;
	size_t	word_num;
	size_t	line_num;
	size_t	partial_num;
} word_info_t;

void word_info_initor(word_info_t* w_info);

word_info_t* StatisticPart(const char* part);





typedef struct SPACE_INFO {
	size_t n_space;
	size_t n_tab;
	size_t n_lineBreak;
	size_t n_another;
}space_info_t;

void space_info_initor(space_info_t* space);


#define SPACE_STOP '#'
#define SPACE ' '
#define LINE_BREAK '\n'
#define TAB '\t'
space_info_t* StatisticSpace(const char* part);


void getIntArray(const char* stdinBuffer, int* outArr, size_t* len);

typedef struct ODD_EVEN_INFO {
	size_t n_oddSize;
	double odd_average;
	size_t n_evenSize;
	double even_average;
}odd_even_info_t;
void odd_even_info_initor(odd_even_info_t* oven);

odd_even_info_t* StatisticOddEven(const int* IntSet);

typedef struct IN_REPLACE {
	size_t n_period;
	size_t n_exclamation;
	char*  sz_replaced;
} in_replace_t;
void in_replace_initor(in_replace_t* replace);

in_replace_t* StaticInReplace(char* part);

in_replace_t * StaticInReplaceBySwitch(char * part);


typedef struct CHECK_SUBSTR {
	size_t n_count;
}check_substr_t;
void check_substr_initor(check_substr_t* sub);

check_substr_t* checkSubstr(const char* input, const char* sub);


#define SUB_RATE1 0.15
#define SUB_RATE2 0.2
#define SUB_RATE3 0.25
typedef struct TAX_INFO {
	double_t n_total;
	double_t n_tax;
	double_t n_income;
}tax_info_t;
void tax_info_initor(tax_info_t* tax);

tax_info_t* incomoHelper(double work_hours);


typedef struct MENU_INFO {
	int		result_No;
	char*	result_info;
	int		info_len;
}menu_info_t;


menu_info_t* menu_inputControl(char* firstCh);

bool s8_menu();

void tax_service(int option);

bool s10_menu();

void s10_tax_service(int option);

#define ARTICHOKE_PRICE 2.05
#define BEET_PRICE 1.15
#define CARROT_PRICE 1.09
#define DISCOUNT 0.05

typedef struct VAGETABLES_ORDER {
	double_t	artichoke_pounds;
	double_t	beet_pounds;
	double_t	carrot_pounds;
	double_t	total_pounds;
	double_t	discount;
	double_t	vagetables_cost;
	double_t	freight_cost;
	double_t	order_cost;	//订单总额
	double_t	total_cost;	//折后实际总额
}order_t;

order_t* order_initor();

void order_destroy(order_t* order);

double_t getFloatFromBytes(const char* input);

void order_pounds_calc(order_t* order);

void vagetable_cost(order_t* order);

bool s11_menu();

void ChoosePlatform();



#endif // !__TOOLS_H__




