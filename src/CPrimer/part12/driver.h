#ifndef __PART12_DRIVER_H__
#define __PART12_DRIVER_H__

#include "example.h"

/* rand0 */
extern unsigned int rand0(void);
void r_driver0(void);

/* srand1 */
extern void srand1(unsigned int x);
void r_driver1(void);

/* shake the elbows */
void manydice(void);

/* guess number */
void guess_driver(void);

void test();

#endif // !__PART12_DRIVER_H__