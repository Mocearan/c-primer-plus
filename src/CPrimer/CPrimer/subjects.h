#ifndef __SUBJECTS_H__
#define __SUBJECTS_H__

#include"common.h"

#include<stdbool.h>
#include"tools.h"

/*
	Processing input instruction.
	return : [struct] result info
*/
enum result_No { BREAK = -1, CONTINUE = 0, NOTHING = 1 };

typedef struct RESULT_INFO {
	int		result_No;
	char*	result_info;
	int		info_len;
}result_info;

/*
	param: 
		[tempBuffer] : char**, out, input buffer data. 
*/

/*
	get a stream from input stream.
*/
result_info* inputControlRestore(char** tempBuffer, char* firstCh);
/*
	get a charactor from input stream.
*/
result_info* inputControlFlush( char* firstCh);


//feature extraction

/*
	param:
		[rearBuf]: char ** in/out, Input stream data except the first character
		[firstCh]: char* in, first charactor in input buffer
*/
void restoreInput(char** rearBuf, char* firstCh);



//subjects
void Subject_1(void);
void Subject_2(void);
void Subject_3(void);
void Subject_4(void);
void Subject_5(void);
void Subject_6(void);
void Subject_7(void);
void Subject_8(void);
void Subject_9(void);
void Subject_10(void);
void Subject_11(void);
void Subject_12(void);
void Subject_13(void);
void Subject_14(void);
void Subject_15(void);
void Subject_16(void);
void Subject_17(void);
void Subject_18(void);


#endif // !__SUBJECTS_H__
