#ifndef __COMMON_H__
#define __COMMON_H__

#define MAX_BUFFER_SIZE 1024

#include <stdarg.h>

//fow WIN32
#if (defined(_WIN32) || defined(_WIN32_WCE) || defined(_WIN64))
#pragma warning(disable:4996)
//c¿âÒ»ÖÂ

#include <stdio.h>
#define gets(_buffer) gets_s(_buffer, MAX_BUFFER_SIZE);
#endif

#if defined _M_IX86 && _M_IX86_FP < 2 && !defined _M_FP_FAST
typedef long double float_t;
typedef long double double_t;
#else
typedef float  float_t;
typedef double double_t;
#endif

#endif // !__COMMON_H__

