#include "pe12-2a.h"

static int last_mode;
static double distance;
static double fuel;

void set_mode(int mode)
{
	if (mode not_eq 0 and mode not_eq 1)
		printf("Invalid mode specified. Mode %s used.\n",
			last_mode == 0 ? "0 (metreic)" : "1 (US)");
	else
		last_mode = mode;
}

void get_info(void)
{
	printf("Enter distnce traveled in %s: ",
		last_mode == 0 ? "Kilometers" : "miles");
	scanf("%lf", &distance);
	printf("Enter fuel consumed in %s: ",
		last_mode == 0 ? "liters" : "gallons");
	scanf("%lf", &fuel);
}

void show_info(void)
{
	printf("Fuel comsumption is ");
	if (last_mode == 0)
		printf("%.2f liters per 100km.\n", fuel / distance * 100);
	else
		printf("%.1f miles per gallon.\n", distance / fuel);
}
