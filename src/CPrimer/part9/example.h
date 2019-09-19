#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include "common.h"
#include "hotel.h"

#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40

void starbar(void);
void lethead1(void);
void cb_starbar(void(*func)(void));

void usehotel(void);

void loccheck(void);
void mikado(int bah);

void swap_test(void);
void swap(int*, int*);

void make_choice(void);
void showtmenu(void);
int getchoice(int, int);

void test();
#endif // !__EXAMPLE_H__

