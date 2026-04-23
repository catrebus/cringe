#pragma once
#include <stdio.h>
#include <string.h>

struct Date {
	int day;
	int month;
	int year;
};
struct Car {
	struct Date date;
	char manager[100];
	char marka[40];
	int cost;
};
