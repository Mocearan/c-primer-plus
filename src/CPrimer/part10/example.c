#include "example.h"

void rain(void) {
	const float rain[YEARS][MONTHS] = {
		{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
		{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
		{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
		{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.3}
	};
	int year, month;
	float subtot, total;

	printf(" YEAR	RAINFALT (inches)\n");
	for (year = 0, total = 0; year < YEARS; ++year) {
		for (month = 0, subtot = 0; month < MONTHS; ++month)
			subtot += rain[year][month];
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
	printf("Monthly average:\n\n");
	printf(" Jan  Feb  MAr  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

	for (month = 0; month < MONTHS; ++month) {
		for (year = 0, subtot = 0; year < YEARS; ++year)
			subtot += rain[year][month];
		printf("%4.1f ", subtot / YEARS);
	}
	printf("\n");
	return;
}

void pnt_add(void) {
	short dates[SIZE];
	short* pti;
	short index;
	double bills[SIZE];
	double* ptf;
	pti = dates;	// 把数组地址赋给指针
	ptf = bills;
	printf("%23s %15s\n", "short", "double");
	for (index = 0; index < SIZE; index++)
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
	return;
}

void day_mon3(void) {
	int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int index;

	for (index = 0; index < MONTHS; ++index)
		printf("Month %2d has %d days.\n", index + 1, *(days + index));//days[index]
	return;
}

INT32 sum(int ar[], int n) {
	size_t i;
	INT32 total = 0;
	for (i = 0; i < n; ++i)
		total += ar[i];
	return total;
}

INT32 sum_to(int* start, int* end) {
	INT32 total = 0;
	while (start < end) {
		total += *start++;
	}
	return total;
}

void sum_driver(void) {
	INT32 in[SIZE] = { [1] = 1,2,3 };
	INT64 answer;

	//answer = sum(in, sizeof in / sizeof in[0]);
	answer = sum_to(in, in + SIZE);
	printf("total: %ld\n", answer);
	return;
}

void order(void) {
	int data[2] = { 100, 200 };
	int moredata[2] = { 300, 400 };
	int* p1, *p2, *p3;

	p1 = p2 = data;
	p3 = moredata;
	printf(" *p = %d,   *p2 = %d,    *p3 = %d\n", *p1, *p2, *p3);
	printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
	printf("  *p1 = %d,   *p2 = %d,   *p3 = %d\n", *p1, *p2, *p3);

	return;
}

void ptr_ops(void) {
	int urn[5] = { 100, 200, 300, 400, 500 };
	int *ptr1, *ptr2, *ptr3;

	ptr1 = urn;
	ptr2 = &urn[2];

	printf("pointer value, dereferenced pointer, pointer address:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

	ptr3 = ptr1 + 4;
	printf("\naddingan int to a pointer:\n");
	printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));
	ptr1++;

	printf("\nvalues after ptr1++:\n");
	printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
	ptr2--;
	printf("\nvalues after ptr2--:\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
	--ptr1;
	++ptr2;
	printf("\nPonters reset to original values:\n");
	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

	printf("\nsubtracting one pointer from another:\n");
	printf("ptr2= %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);

	printf("\nsubtracting an int from a pointer:\n");
	printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);

	return;
}

void add_each(double_t ar[], int n, double_t val) {
	size_t i;
	for (i = 0; i < n; ++i)
		ar[i] += val;
}

INT32 sum_guard(const INT32 arr[], size_t n) {
	size_t i;
	INT32 total = 0;

	for (i = 0; i < n; ++i)
		total += arr[i];
	return total;
}

void show_array(const double_t arr[], size_t n) {
	size_t i;
	for (i = 0; i < n; i++)
		printf("%8.3f ", arr[i]);
	putchar('\n');
}

void mult_array(double_t arr[], size_t n, double_t mult) {
	size_t i;
	for (i = 0; i < n; i++)
		arr[i] *= mult;
}

void arf(void) {
	double_t dip[SIZE2] = { 20.0f, 17.66f, 8.2f, 15.3f, 22.22f };

	printf("The original dip array:\n");
	show_array(dip, SIZE2);
	mult_array(dip, SIZE2, 2.5);
	printf("The dip array after calling mult_array():\n");
	show_array(dip, SIZE2);

	return;
}

void zippo(void) {
	INT32 zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7} };

	printf("\tzippo = %p,\tzippo + 1 = %p\n", zippo, zippo + 1);
	printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);
	printf("\t*zippo = %p,\t*zippo + 1 = %p\n", *zippo, *zippo + 1);
	printf("zippo[0][0] = %d\n", zippo[0][0]);
	printf("\t*zippo[0] = %d\n", *zippo[0]);
	printf("\t\t**zippo = %d\n", **zippo);
	printf("\t\t\tzippo[2][1] = %d\n", zippo[2][1]);
	printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1));
	return;
}

void zippo2(void) {
	INT32 zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7} };
	int(*pz)[2];
	pz = zippo;

	printf("\tpz = %p,\tpz + 1 = %p\n", pz, pz + 1);
	printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
	printf("\t*pz = %p,\t*pz + 1 = %p\n", *pz, *pz + 1);
	printf("pz[0][0] = %d\n", pz[0][0]);
	printf("\t*pz[0] = %d\n", *pz[0]);
	printf("\t\t**pz = %d\n", **pz);
	printf("\t\t\pz[2][1] = %d\n", pz[2][1]);
	printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
	return;
}

void sum_rows(INT32 arr[][COLS], size_t rows) {
	size_t r;
	size_t c;
	INT32 tot;

	for (r = 0; r < rows; r++) {
		tot = 0;
		for (c = 0; c < COLS; c++)
			tot += arr[r][c];
		printf("row %d: sum = %d\n", r, tot);
	}
}

void sum_cols(INT32 arr[][COLS], size_t rows) {
	size_t r;
	size_t c;
	INT32 tot;

	for (c = 0; c < COLS; c++) {
		tot = 0;
		for (r = 0; r < rows; r++)
			tot += arr[r][c];
		printf("cols %d: sum = %d\n", c, tot);
	}
}

INT32 sum2d(INT32(*arr)[COLS], size_t rows) {
	size_t r;
	size_t c;
	INT32 tot=0;

	for (r = 0; r < rows; r++)
		for (c = 0; c < COLS; c++)
			tot += arr[r][c];

	return tot;
}

void array2d(void) {
	int junk[ROWS][COLS] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Sum of all elements = %d\n", sum2d(junk, ROWS));
	return 0;
}

#if defined __linux__
// vs not support VLA
int sum2d_to(int rows, int cols, int ar[rows][cols]) {
	int r;
	int c;
	int tot = 0;

	for (r = 0; r < rows; ++r)
		for (c = 0; c < cols; ++c)
			tot += ar[r][c];
	return tot;
}

void vararr2d(void) {
	int i, j;
	int rs = 3;
	int cs = 10;
	int junk[ROWS][COLS] = {
		{2,4,6,8},
		{3,5,7,9},
		{12,10,8,6}
	};

	int varr[rs][cs];	//VLA

	int morejunk[ROWS - 1][COLS + 2] = {
		{20,30,40,50,60,70},
		{5,6,7,8,9,10}
	};

	for (i = 0; i < rs; i++)
		for (j = 0; j < cs; j++)
			varr[i][j] = i * j + j;

	printf("3x5 array\n");
	printf("Sum of all elements = %d\n", sum2d_to(ROWS, COLS, junk));

	printf("2x6 array\n");
	printf("Sum of all elements = %d\n", sum2d_to(ROWS - 1, COLS + 2, morejunk));

	printf("3x10 VLA\n");
	printf("Sum of all elements = %d\n", sum2d_to(rs, cs, varr));
}

#endif

int sum2d1(const int arr[][COLS], int rows) {
	int r;
	int c;
	int tot = 0;

	for (r = 0; r < rows; ++r)
		for (c = 0; c < COLS; ++c)
			tot += arr[r][c];

	return tot;
}

int sum1(const int arr[], int n) {
	int i;
	int total = 0;

	for (i = 0; i < n; ++i)
		total += arr[i];

	return total;
}
void flc(void) {
	int total1, total2, total3;
	int * pt1;
	int(*pt2)[COLS];

	pt1 = (int[2]) { 10, 20 };
	pt2 = (int[][COLS]) { {1, 2, 3, -9}, { 4,5,6, - 8 } };

	total1 = sum1(pt1, 2);
	total2 = sum2d1(pt2, 2);
	total3 = sum1((int[]) { 4, 4, 4, 5, 5, 5 }, 6);
	printf("total1 = %d\n", total1);
	printf("total2 = %d\n", total2);
	printf("total3 = %d\n", total3);

	return;

}

void re_1(void) {
	int ref[] = { 8,4,0,2 };
	int* ptr;
	int index;

	for (index = 0, ptr = ref; index < 4; ++index, ++ptr)
		printf("%d %d\n", ref[index], *ptr);

	printf("%p %p \n", ref, ref +1);
	return 0;
}

void re_41(void) {
	int* ptr;
	int torf[2][2] = { 12, 14, 16 };
	ptr = torf[0];

	printf("%d %d\n", *ptr, *(ptr + 2));
}
void re_42(void) {
	int* ptr;
	int torf[2][2] = { {12}, {14, 16} };
	ptr = torf[0];

	printf("%d %d\n", *ptr, *(ptr + 2));
}

void re_51(void) {
	int(*ptr)[2];
	int torf[2][2] = { 12, 14, 16 };
	ptr = torf;

	printf("%d %d\n", **ptr, **(ptr + 1));
}

void re_52(void) {
	int(*ptr)[2];
	int torf[2][2] = { {12}, {14, 16} };
	ptr = torf;

	printf("%d %d\n", **ptr, **(ptr + 1));
}

void re_7(void) {
	int digits[10];
	float rates[6];
	int mat[3][5];
	int* pas[20];
	char(*pstr)[20];
}

void re_10(void) {
	float rootbeer[10], things[10][5], *pf, value = 2.2;
	int i = 3;
	rootbeer[2] = value;
	scanf("%f", &rootbeer);
	things[4][4] = rootbeer[3];
	//pf = value;
	pf = rootbeer;
}


void re_11(void) {
	int a[800][600];
}

void show(const double a[], int n) {


}

void show2(const double ar2[][3], int n) {

}
void re_13(void) {
	show((int[]) { 8, 3, 9, 2 }, 4);
	show2((int[][3]) { {8, 3, 9}, { 5,4,1 } }, 6);
}



// unit test
void test() {

	//rain();
	//pnt_add();
	//day_mon3();
	//sum_driver();
	//order();
	//ptr_ops();
	//arf();
	//zippo();
	//zippo2();
	//array2d();

#if defined __linux__
	vararr2d();
#endif
	//flc();

	//re_1();
	//re_41();
	//re_42();
	re_51();
	re_52();

	re_10(	);

	re_13();

	//printf("test.\n");
	return;
}