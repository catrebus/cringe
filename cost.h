#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXN 200
#include <stdlib.h>

//Алимова

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

//Вывод содержимого хранилища в виде листов в консоль
void print_car(struct Car* storage, int* size, char* message);
//Сравнение структур Car
int camper(struct Car a, struct Car b);
//Сортировка выбором
void selection_sort(struct Car* storage, int* size, char* message);
//Сортировка пузырьком
void bubble_sort(struct Car* storage, int* size, char* message);
//Сортировка вставкой
void insertion_sort(struct Car* storage, int* size, char* message);
