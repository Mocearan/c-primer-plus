#ifndef __HOTEL_H__
#define __HOTEL_H__

#include "common.h"

#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARS	"*********************************************"

//��ʾѡ���б�
int menu(void);

//����Ԥ������
int getnights(void);

//���ݷ��ʡ���ס����������ò���ʾ���
void showprice(double rate, int nights);

#endif // !__HOTEL_H__

