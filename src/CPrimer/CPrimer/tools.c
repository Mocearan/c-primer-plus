
#include "tools.h"

int print(char ch)
{
	int ret = 0;
	if (ret = printf("%c", ch))
		;

	return ret;
}

void getTwoFloat(const char* stdinBuffer, double* outFir, double* outSec)
{
	char InFir[32] = { 0 };
	char InSec[32] = { 0 };
	int i = 0;
	for (; stdinBuffer[i] != ' '&&stdinBuffer[i] != '\0'; InFir[i] = stdinBuffer[i], ++i)
		;
	for (int j = 0; stdinBuffer[i + 1] != '\0'; InSec[j] = stdinBuffer[i + 1], ++i, ++j)
		;
	*outFir = atof(InFir);
	*outSec = atof(InSec);
}

double mySquare(double inDouble)
{ 

	return inDouble * inDouble;
}


void getIntArray(const char* stdinBuffer, int* outArr, int* len) {
	char intStr[16] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	for (; stdinBuffer[i] != '\0'; ++i) {
		if (stdinBuffer[i] != ' ')
			intStr[k++] = stdinBuffer[i];
		else {
			outArr[j++] =atoi(intStr); 
			memset(intStr, 0x00, sizeof(intStr));
			k = 0;
		}
	}

	if (intStr[0] != 0) {
		outArr[j] = atoi(intStr); //Handle the last int
		*len = ++j;
	}
	else {
		*len = j;
	}
}

double harmonic_series(unsigned items)
{
	double sum = 0.0L;
	for (int i = 1; i <= items; ++i)
		sum += 1.0 / i;
	return sum;
}

double alternating_harmonic_series(unsigned items)
{
	double sum = 0.0L;
	for (int i = 1; i <= items; ++i) {
		if (i % 2)
			sum += 1.0 / i;
		else
			sum -= 1.0 / i;
	}
	return sum;
}


void construct_binary_arr(unsigned* arr, int * len)
{
	for (int i = 0; i < len; ++i) {
		arr[i] = 1;
		for (int j = 0; j < i; ++j) {
			arr[i] *= 2;
		}
	}

}
