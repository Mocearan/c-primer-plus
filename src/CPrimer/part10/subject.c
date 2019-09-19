#include "subject.h"

void sub1_service(void) {
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
			subtot += *(*(rain + year) + month);
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
	printf("Monthly average:\n\n");
	printf(" Jan  Feb  MAr  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

	for (month = 0; month < MONTHS; ++month) {
		for (year = 0, subtot = 0; year < YEARS; ++year)
			subtot += *(*(rain + year) + month);
		printf("%4.1f ", subtot / YEARS);
	}
	printf("\n");
	return;
}
void subject_1(void) {
	const char* tips = "[1]:\n";

	subjectBash(tips, sub1_service);
	return;
}


void copy_arr(double ar1[], double ar[], int n) {
	for (size_t in = 0; in < n; ++in)
		ar1[in] = ar[in];
}
void copy_ptr(double* ar1, double* ar, int n) {
	for (size_t in = 0; in < n; ++in)
		*(ar1++) = *(ar++);
}
void copy_ptrs(double*ar1, double* ar_start, double* ar_end) {
	while (ar_start < ar_end)
		*(ar1++) = *(ar_start++);
}
void print_array(double ar[], int n) {
	printf("{");
	for (size_t in = 0; in < n; ++in) {
		if (ar[in] == ARRAY_SPACE)
			continue;
		if (in + 1 == n or ar[in + 1] == ARRAY_SPACE)
			printf(" %g", ar[in]);
		else
			printf(" %g,", ar[in]);
	}
	printf(" }");
}
void print_array_ln(double ar[], int n) {
	print_array(ar, n);
	printf("\n");
}

void init_arr(double_t arr[], size_t n) {
	for (size_t i = 0; i < n; ++i)
		arr[i] = ARRAY_SPACE;
}
double_t arr_sum(double_t arr[], size_t n) {
	double_t sum = 0;
	for (size_t i = 0; i < n; ++i)
		if(arr[i] != ARRAY_SPACE)
			sum += arr[i];
	return sum;
}
double_t arr_mean(double_t arr[], size_t n) {
	size_t len = 0;
	for (size_t i = 0; i < n; ++i)
		if (arr[i] != ARRAY_SPACE)
			++len;
	return arr_sum(arr, n) / len;
}
double_t arr_max(double_t arr[], size_t n) {
	double_t max = arr[0];
	for (size_t i = 1; i < n; ++i)
		if (arr[i] != ARRAY_SPACE)
			arr[i] > max ? max = arr[i] : 1;
	return max;
}

void init_2_arr(double_t arr2d[][COLS], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; ++i)
		init_arr(arr2d[i], cols);
}
void copy_2_arr(double_t dest[][COLS], double_t arr2d[][COLS], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; ++i)
		copy_arr(dest[i], arr2d[i], cols);
}
void print_2_arr(double_t arr2d[][COLS], size_t rows, size_t cols) {
	printf("{\n\t");
	for (size_t i = 0; i < rows; ++i) {
		print_array(arr2d[i], cols);
		if (i + 1 == rows)
			printf("\n");
		else
			printf(",\n\t");
	}
	printf("}");
}
void print_2_arr_ln(double_t(*arr2d)[], size_t rows, size_t cols) {
	print_2_arr(arr2d, rows, cols);
	printf("\n");
}
size_t get2dFloatArray(const char* inBuf, double_t outArr[][COLS]) {
	char* pSrc = inBuf;
	size_t i = 0;
	for (; *pSrc and *pSrc != EOF; i++) {
		getFloatArray(pSrc, outArr[i]);
		while (*(pSrc++) != '\n');
	}
	return i;
}
void add_Float_array(double_t target[], double_t a1[], double_t a2[], size_t len) {
	for (size_t i = 0; i < len; i++) {
		if (a1[i] == ARRAY_SPACE and a2[i] == ARRAY_SPACE)
			continue;
		target[i] = a1[i] + a2[i];
	}
}
void add_2d_Float_array(double_t target[][COLS], double_t a1[][COLS], double_t a2[][COLS], size_t rows) {
	for (size_t i = 0; i < rows; i++)
		add_Float_array(target[i], a1[i], a2[i], COLS);
}
double_t arr_2d_sum(double_t arr[][COLS], size_t rows) {
	double_t sum = 0;
	for (size_t i = 0; i < rows; ++i)
		sum += arr_sum(arr[i], COLS);
	return sum;
}
double_t arr_2d_mean(double_t arr[][COLS], size_t rows) {
	double_t sum = 0;
	for (size_t i = 0; i < rows; ++i)
		sum += arr_mean(arr[i], COLS);
	return sum / rows;
}
double_t arr_2d_max(double_t arr[][COLS], size_t rows) {
	double_t max = arr_max(arr[0], COLS);;
	double_t index;
	for (size_t i = 1; i < rows; ++i)
		(index = arr_max(arr[i], COLS)) > max ? max = index : 1;
	return max;
}

void scalar_multiplication_vector(double_t arr[], size_t n, double_t coefficient) {
	for (size_t i = 0; i < n; ++i) {
		if (arr[i] == ARRAY_SPACE)
			continue;
		arr[i] *= coefficient;
	}
}

void scalar_multiplication_matrix(double arr[][COLS], size_t rows, double_t coefficient) {
	for (size_t i = 0; i < rows; ++i)
		scalar_multiplication_vector(arr[i], COLS, coefficient);
}

void sub2_service() {
	double source[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[SIZE];
	double target2[SIZE];
	double target3[SIZE];

	print_array_ln(source, sizeof source / sizeof source[0]);
	copy_arr(target1, source, SIZE);
	print_array_ln(target1, SIZE);
	copy_ptr(target2, source, SIZE);
	print_array_ln(target2, SIZE);
	copy_ptrs(target3, source, source + SIZE);
	print_array_ln(target3, SIZE);
}

void subject_2(void) {
	const char* tips = "[2]:\n";

	//subjectBash(tips, sub2_service, "interface");
	subjectBash(tips, sub2_service);
	return;
}

INT32 max_(INT32 ar[], size_t n) {
	INT32 max = ar[0];
	for (size_t i = 1; i < n; ++i)
		(ar[i] > max) ? max = ar[i] : 1;
	return max;
}

size_t max_at(INT32 ar[], size_t n) {
	INT32 max = ar[0];
	size_t index = 0;
	for (size_t i = 1; i < n; ++i)
		(ar[i] > max) ? index = i : 1;
	return index;
}

INT32 diff_max_n_min(INT32 ar[], size_t n) {
	INT32 max = ar[0], min = ar[0];
	size_t index = 0;
	for (size_t i = 1; i < n; ++i)
		(ar[i] > max) ? max = ar[i] : 
			(ar[i] < min)? min = ar[i]:1;
	return max - min;
}

void sub3_service(const stream_t* stream) {
	INT32 arr[32];
	size_t arr_len = getIntArray(stream->stream, arr);  

	printf("The max of your input: [ %d ]\n", max_(arr, arr_len));
}

void subject_3(void) {
	const char* tips = "[ 3 ] Please input a series of integer to init a int arrat:(space/tab to quit)\n";

	subjectBash(tips, sub3_service, BASH_INTERFACE, BASH_LINE);
	return;
}


void sub4_service(const stream_t* stream) {
	INT32 arr[32];
	size_t arr_len = getIntArray(stream->stream, arr);

	printf("The index of max value in your input: [ %d ]\n", max_at(arr, arr_len));
}

void subject_4(void) {
	const char* tips = "[ 4 ] Please input a series of integer to init a int arrat:(space/tab to quit)\n";

	subjectBash(tips, sub4_service, BASH_INTERFACE, BASH_LINE);
	return;
}

void sub5_service(const stream_t* stream) {
	INT32 arr[32];
	size_t arr_len = getIntArray(stream->stream, arr);

	printf("The diff of max and min value in your input: [ %d ]\n", diff_max_n_min(arr, arr_len));
}

void subject_5(void) {
	const char* tips = "[ 5 ] Please input a series of integer to init a int arrat:(space/tab to quit)\n";

	subjectBash(tips, sub5_service, BASH_INTERFACE, BASH_LINE);
	return;
}

void invertFloatArray(double_t ar[], size_t len) {
	double_t temp;
	for (size_t i = 0; i < len - i - 1; ++i) {
		temp = ar[i];
		ar[i] = ar[len - i - 1];
		ar[len - i - 1] = temp;
	}
}

void sub6_service(const stream_t* stream) {
	INT32 arr[32];
	size_t arr_len = getFloatArray(stream->stream, arr);
	invertFloatArray(arr, arr_len);
	printf("The inverted float arrary :\n");
	print_array_ln(arr, arr_len);
}

void subject_6(void) {
	const char* tips = "[ 6 ] Please input a series of float to init a int arrat:(space/tab to quit)\n";

	subjectBash(tips, sub6_service, BASH_INTERFACE, BASH_LINE);
	return;
}



void sub7_service(const stream_t* stream) {
	double_t arr[COLS];
	double_t arrq[ROWS][COLS];
	init_2_arr(arrq, ROWS, COLS);
	size_t arr_len = getFloatArray(stream->stream, arr);
	copy_arr(arrq[0], arr, arr_len);
	printf("The copy arr :\n");
	print_2_arr_ln(arrq, ROWS, COLS);
}

void subject_7(void) {
	const char* tips = "[ 7 ] Please input a series( < 10 ) of double to init a float arrat:(space/tab to quit)\n";

	subjectBash(tips, sub7_service, BASH_INTERFACE, BASH_LINE);
	return;
}


void sub8_service(const stream_t* stream) {
	double_t arr[COLS];
	double_t ar_copy[3];
	init_arr(arr, COLS);
	getFloatArray(stream->stream, arr);
	copy_arr(ar_copy, arr+2, 3);
	printf("The copy arr :\n");
	print_array_ln(ar_copy, 3);
}

void subject_8(void) {
	const char* tips = "[ 8 ] Please input a series( > 3 ) of double to init a float arrat:(space/tab to quit)\n";

	subjectBash(tips, sub8_service, BASH_INTERFACE, BASH_LINE);
	return;
}

void sub9_service(const stream_t* stream) {
	double_t arr[ROWS][COLS];
	init_2_arr(arr, ROWS, COLS);
	char* pSrc = stream->stream;
	double_t ar_copy[ROWS][COLS];
	init_2_arr(ar_copy, ROWS, COLS);

	size_t rows = get2dFloatArray(pSrc, arr);
	copy_2_arr(ar_copy, arr, rows, COLS);
	printf("The copy arr :\n");
	print_2_arr_ln(ar_copy, rows, COLS);
}

void subject_9(void) {
	const char* tips = "[ 9 ] Please input 2d double array, enter to switchover the same dimension's new line:(CTRL+Z to end,space/tab to quit)\n";

	subjectBash(tips, sub9_service, BASH_INTERFACE, BASH_TEXT);
	return;
}

void sub10_service(const stream_t* stream) {
	double_t arr1[ROWS][COLS];
	init_2_arr(arr1, ROWS, COLS);
	char* pSrc = stream->stream;
	size_t arr1_rows = get2dFloatArray(pSrc, arr1);

	double_t arr2[ROWS][COLS];
	init_2_arr(arr2, ROWS, COLS);
	char ch;
	char temp[128] = { 0 };
	size_t i = 0;
	printf("Please input 2nd 2d double array:(CTRL+Z to end)\n");
	while ((ch = getchar()) != EOF)
		temp[i++] = ch;
	size_t arr2_rows = get2dFloatArray(temp, arr2);

	double_t added[ROWS][COLS];
	init_2_arr(added, ROWS, COLS);
	add_2d_Float_array(added, arr1, arr2, ROWS);
	
	printf("The added array:\n");
	arr1_rows > arr2_rows ? print_2_arr_ln(added, arr1_rows, COLS) : print_2_arr_ln(added, arr2_rows, COLS);
}

void subject_10(void) {
	const char* tips = "[ 10 ] Array addtion, Please input 1st 2d double array:(CTRL+Z to end,space/tab to quit)\n";

	subjectBash(tips, sub10_service, BASH_INTERFACE, BASH_TEXT);
	return;
}

void sub11_service(const stream_t* stream) {
	double_t arr1[ROWS][COLS];
	init_2_arr(arr1, ROWS, COLS);
	char* pSrc = stream->stream;
	size_t rows = get2dFloatArray(pSrc, arr1);

	scalar_multiplication_matrix(arr1, rows, 2);

	printf("The Scalar multiplication of matrices:\n");
	print_2_arr_ln(arr1, rows, COLS);
}

void subject_11(void) {
	const char* tips = "[ 11 ] Scalar multiplication of matrices, Please input 2d double array:(CTRL+Z to end,space/tab to quit)\n";

	subjectBash(tips, sub11_service, BASH_INTERFACE, BASH_TEXT);
	return;
}

void subject_12(void) {
	const char* tips = "[ 11 ]:\n";

	subjectBash(tips, sub1_service);
	return;
}

char get_first1(void) {
	char ch;
	while (isspace(ch = getchar()))
		continue;
	while (getchar() != '\n')
		continue;

	return ch;
}
char get_choice1() {
	int ch;

	const char* tips = "**********************************************************\n*\t1. vector mean\t\t\t2. matrix mean\n*\t3. max of mereix\t\t4. See metrix\n*\tq. quit\n***********************************\n";
	printf("%s", tips);
	ch = get_first1();

	while ((ch < '1' or ch > '4') and ch not_eq 'q') {
		printf("Please respond with 1, 2, 3, 4 and q:");
		ch = get_first1();
	}

	return ch;
}
void sub13_service(const stream_t* stream) {
	double_t arr1[ROWS][COLS];
	init_2_arr(arr1, ROWS, COLS);
	char* pSrc = stream->stream;
	size_t rows = get2dFloatArray(pSrc, arr1);

	int choice;
	while ((choice = get_choice1()) != 'q') {
		switch (choice)
		{
		case '1':
			for (size_t i = 0; i < rows; ++i)
				printf("vector[%d] mean : %lf\n", i, arr_mean(arr1[i], COLS));
			break;
		case '2':
			printf("matrix mean : %lf\n", arr_2d_mean(arr1, rows));
			break;
		case '3':
			printf("max of matrix : %lf\n", arr_2d_max(arr1, rows));
			break;
		case '4':
			print_2_arr_ln(arr1, rows, COLS);
			break;
		default:
			printf("Program error!\n");
			break;
		}
	}
}
void subject_13(void) {
	const char* tips = "[ 11 ] Please input 2d double array:(CTRL+Z to end,space/tab to quit)\n";

	subjectBash(tips, sub13_service, BASH_INTERFACE, BASH_TEXT);
	return;
}