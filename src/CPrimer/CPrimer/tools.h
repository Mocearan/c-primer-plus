#ifndef __TOOLS_H__
#define __TOOLS_H__

#include "common.h"

/*
	tools
*/

int print(char ch);
void getTwoFloat(const char* stdinBuffer, double* outFir, double* outSec);
double mySquare(double inDouble);

void getIntArray(const char* stdinBuffer, int* outArr, int* len);

double harmonic_series(unsigned items);
double alternating_harmonic_series(unsigned items);


void construct_binary_arr(unsigned* arr, int* len);



#endif // !__TOOLS_H__
