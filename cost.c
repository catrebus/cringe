#include <stdio.h>
#include <string.h>
#include "cost.h"

void print_car(struct Car arr[], int syze) {
	for (int i = 0; i < syze; i++) {
		printf("%d.%d.%d %s %s %d", arr[i].date.day, arr[i].date.month, arr[i].date.year, arr[i].manager, arr[i].marka, arr[i].cost);
	}
}

int camper(struct Car a[], struct Car b[]) {
	return strcmp(a, b);
}

void sorted_viborom(struct Car arr[], int syze) {
	int min = 0;
	for (int i = 0; i < syze; i++) {
		min = i;
		for (int j = i; j < syze; j--) {
			if (camper(j, min) > 0) {
				min = j;
			}
		}
		struct Car tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}

void bubble_sorted(struct Car arr[], int syze) {
	for (int i = 0; i < syze; i++) {
		for (int j = 1; j < syze; j++) {
			if (camper(j, j+1) > 0) {
				arr[j], arr[j + 1] = arr[j + 1], arr[j];
			}
		}
	}
}

