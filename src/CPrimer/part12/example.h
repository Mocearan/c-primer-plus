#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include "tool.h"

/* rand0 */
static unsigned long int next = 1;//seed
unsigned int rand0(void);

/* srand1 */
void srand1(unsigned int seed);

/* shake the elbows */
int rollem(int sides);
extern int roll_count;
int roll_n_dice(int dice, int sides);

/* guess number */
void Game(int result);
void guess_number(void);

#endif