#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include "tool.h"
#include "subjectHelper.h"

void sub1_service(const stream_t* path);
void Subject_1(void);

#define SPACE 32
#define CTRL 64
#define COL 10	//每行打印十对
void sub2_bytes_done(char ch, size_t* count);
void sub2_service(const stream_t* input);
void Subject_2(void);

void checking_ch(char ch, size_t* lo, size_t* up);
void sub3_service(const stream_t* input);
void Subject_3(void);

void sub4_checking_ch(char ch, size_t* chars, bool* inword, size_t* words);
void sub4_service(const stream_t* input);
void Subject_4(void);

typedef struct GUESS_T {
	int		upper;
	int		lower;
	int		guess;
}guess_t;
void guess_initor(guess_t* guess);
guess_t* create_guess();
void guess_destroy(guess_t* guess);
void sub5_checking_ch(char ch, guess_t* guess);
void sub5_service(const stream_t* input);
void Subject_5(void);

char get_first1(void);
void sub6_service(const stream_t* input);
void Subject_6(void);


void Subject_7(void);

char get_choice1(stream_t* input, bool* fg);
double_t get_float(void);
void chose_bash_done(stream_t* input);
void sub8_service(stream_t* input);
void Subject_8(void);


#endif // !__SUBJECT_H__
