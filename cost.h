#pragma once
#include <stdio.h>
#include <string.h>
#define MAXN 100

struct Date {
	int day;
	int month;
	int year;
};
struct Car {
	int id;
	struct Date date;
	char manager[100];
	char marka[40];
	int cost;
};

void print_car(struct Car arr[], int syze);
int camper(struct Car a[], struct Car b[]);
void sorted_viborom(struct Car arr[], int syze);
void bubble_sorted(struct Car arr[], int syze);