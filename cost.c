#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "cost.h"

void clear() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void clear_buf() {
	while (getchar() != '\n');
}

void print_title(void) {
	printf("---------------------------------------------------------------\n");
	for (int i = 1; i < 30; i++) {
		printf("|                                                             |\n");
	}
	printf("|                        ALINA AND CO.                        |\n");
	printf("|                      PROCAT AVTOMOBILEY                     |\n");
	for (int i = 1; i < 30; i++) {
		printf("|                                                             |\n");
	}
	printf("---------------------------------------------------------------\f\n");
}

void print_car(struct Car* storage, int* size, char* message) {
	print_title();
	int z = 0;
	int list_max = 10;
	for (int i = 0; i < *size / 10; i++) {
		
		printf("---------------------------------------------------------------\n");
		printf("|                                                             |\n");
		printf("|                      PROCAT AVTOMOBILEY                     |\n");
		printf("|                                                             |\n");
		printf("---------------------------------------------------------------\n");
		for (int j = 0; j < 24; j++) {
			printf("|                                                             |\n");
		}
		for (z; z < list_max; z++) {
			char line[MAXN] = "";
			sprintf(line, "%d %d.%d.%d %s %s %d", storage[z].id, storage[z].date.day, storage[z].date.month, storage[z].date.year, storage[z].manager, storage[z].marka, storage[z].cost);
			printf("|    %-55s  |\n", line);
		}
		if (list_max + 10 >= *size) {
			list_max = *size;
		}
		else {
			list_max += 10;
		}
		
		for (int j = 0; j < 23; j++) {
			printf("|                                                             |\n");
		}
		printf("|                              %d                              |\n", i+2);
		printf("---------------------------------------------------------------\f\n");

	}
	clear_buf();
	getchar();
	clear();
}

int camper(struct Car a, struct Car b) {
	return strcmp(a.manager, b.manager);
}

void selection_sort(struct Car* storage, int* size, char* message) {
	int min = 0;
	for (int i = 0; i < *size; i++) {
		min = i;
		for (int j = i; j < *size; j++) {
			if (camper(storage[j], storage[min]) > 0) {
				min = j;
			}
		}
		struct Car tmp = storage[i];
		storage[i] = storage[min];
		storage[min] = tmp;
	}
	strcpy(message, "УСПЕХ: Отсортировано выбором");
}

void bubble_sort(struct Car* storage, int* size, char* message) {
	for (int i = 0; i < *size; i++) {
		for (int j = 1; j < *size; j++) {
			if (camper(storage[j], storage[j+1]) > 0) {
				struct Car tmp = storage[j];
				storage[j] = storage[j+1];
				storage[j+1] = tmp;
			}
		}
	}
	strcpy(message, "УСПЕХ: Отсортировано пузырьком");
}

void insertion_sort(struct Car* storage, int* size, char* message) {
	for (int i = 1; i < *size; i++) {
		int insert_index = i;
		struct Car current_value = storage[i];
		for (int j = i - 1; j > -1; j--) {
			if (camper(storage[j], current_value) < 0) {
				storage[j + 1] = storage[j];
				insert_index = j;
			}
			else {
				break;
			}
		}
		storage[insert_index] = current_value;
	}
	strcpy(message, "УСПЕХ: Отсортировано вставкой");
}



