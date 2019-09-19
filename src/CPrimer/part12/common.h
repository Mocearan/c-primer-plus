#ifndef __COMMON_H__
#define __COMMON_H__

//for std .h
/**
* compile : gcc -o pra.exe pra.c -lm
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<math.h> //use -lm in gcc
#include<time.h>

#include <stdbool.h>

#include <iso646.h> //for keyboard. and && or || not !

#include <ctype.h> // for sapce charactor

#include <stdarg.h>// for overload function


#define MAX_BUFFER_SIZE 1024

//fow WIN32
#if (defined(_WIN32) || defined(_WIN32_WCE) || defined(_WIN64))\
//c库一致
#pragma warning(disable:4996)
//函数一致
#include <stdio.h>
#define gets(_buffer) gets_s(_buffer, MAX_BUFFER_SIZE);

#include <Windows.h>
#define SLEEP(second) Sleep(second * 1000);

#endif

//for float number equals 0
#define MIN_VALUE 1e-8  //根据需要调整这个值
#define IS_DOUBLE_ZERO(d) (abs(d) < MIN_VALUE)



#if defined _M_IX86 && _M_IX86_FP < 2 && !defined _M_FP_FAST
typedef long double float_t;
typedef long double double_t;
#else
typedef float  float_t;
typedef double double_t;
#endif

#define LOG(isLog,_Format, ...) isLog?printf(_Format, ##__VA_ARGS__):1


#endif // !__COMMON_H__