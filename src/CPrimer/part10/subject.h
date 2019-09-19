#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include "tool.h"
#include "subjectHelper.h"

#define MONTHS	12	// months of year
#define YEARS	5	// years

#define ARRAY_SPACE -0.000000066666
void sub1_service(void);
void Subject_1(void);

#define SIZE 5
void copy_arr(double ar1[], double ar[], int n);
void copy_ptr(double *ar1, double* ar, int n);
void copy_ptrs(double *ar1, double* ar_start, double* ar_end);
void print_array_ln(double ar[], int n);
void sub2_service(void);
void Subject_2(void);

INT32 max_(INT32 ar[], size_t n);
size_t max_at(INT32 ar[], size_t n);
void sub3_service(const stream_t* stream);
void subject_3(void);

void sub4_service(const stream_t* stream);
void subject_4(void);

#define ROWS 5
#define COLS 10

#endif // !__SUBJECT_H__
