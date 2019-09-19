#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include "tool.h"
#include "subjectHelper.h"

#define ARRAY_SPACE -0.000000066666

#define SIZE1  40u
#define SIZE2  80u

void sub1_service(void);
void Subject_1(void);

void sub2_service(void);
void Subject_2(void);

void sub3_service(const stream_t* stream);
void subject_3(void);

void sub4_service(const stream_t* stream);
void subject_4(void);

#endif // !__SUBJECT_H__