#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include "tool.h"
#include "subjectHelper.h"

void sub1_service(const stream_t* stream);
void Subject_1(void);

void sub2_bytes_done(char ch, size_t* count);
void sub2_service(const stream_t* input);
void Subject_2(void);

void sub3_service(const stream_t* input);
void Subject_3(void);

void sub4_service(const stream_t* input);
void Subject_4(void);


void sub5_service(const stream_t* input);
void Subject_5(void);

char get_first1(void);
void sub6_service(const stream_t* input);
void Subject_6(void);


void Subject_7(void);

void chose_bash_done(stream_t* input);
void sub8_service(stream_t* input);
void Subject_8(void);


#endif // !__SUBJECT_H__
