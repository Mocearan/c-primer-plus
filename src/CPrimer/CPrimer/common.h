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



#define MAX_BUFFER_SIZE 1024

//fow WIN32
#if (defined(_WIN32) || defined(_WIN32_WCE) || defined(_WIN64))\
//c库一致
#pragma warning(disable:4996)
//函数一致
#include <stdio.h>
#define gets(_buffer) gets_s(_buffer, MAX_BUFFER_SIZE);
#endif


//for float number equals 0
#define MIN_VALUE 1e-8  //根据需要调整这个值
#define IS_DOUBLE_ZERO(d) (abs(d) < MIN_VALUE)


#endif // !__COMMON_H__