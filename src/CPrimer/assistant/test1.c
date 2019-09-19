#include <stdio.h>
#include"test.h"

void hello(void) {
	printf("helo world\n");
	return;
}

void hello_all(const char* str) {
	printf("[ hello ] %s\n", str);
}

void vara(int count, ...) {
	va_list va;
	va_start(va, count);
	for (size_t i = 0; i < count; ++i)
		printf("%d ", va_arg(va, int));
	va_end(va);
}

void vara2(const char* p, ...) {
	va_list va;
	va_start(va, p);
	for (size_t i = 0; i < 4; ++i)
		printf("%d ", va_arg(va, int));
	va_end(va);
}

void overload(const char* p, ...) {
	printf("%s\n", p);
	va_list va;
	va_start(va, p);
	typedef void(*FUNC)();
	FUNC func = va_arg(va, FUNC);
	(*func)();
	return;
}

void overload2(const char* p, ...) {
	va_list va;
	va_start(va, p);
	typedef void(*FUNC)();
	FUNC func = va_arg(va, FUNC);
	(*func)(p);
	return;
}

void calling(void) {
	//vara(4, 1, 2, 3, 4);
	//vara2("tips", 1, 2, 3, 4);
	//overload("tips", hello);
	overload2("tips", hello_all);
}

#define ARRAY_SPACE -0.000000066666
void add_Float_array(double_t target[], double_t a1[], double_t a2[], size_t len) {
	for (size_t i = 0; i < len; i++) {
		if (a1[i] == ARRAY_SPACE && a2[i] == ARRAY_SPACE)
			continue;
		target[i] = a1[i] + a2[i];
	}
}

void add_array_driver(void) {
	double_t tag[10];
	double_t ar[10] = { 10 };
	double_t a2[10] = { 1 };
	add_Float_array(tag, ar, a2, 10);
	for (size_t i = 0; i < 10; ++i)
		printf("%g	", tag[i]);
}

void test1() {
	add_array_driver();

	return;
}