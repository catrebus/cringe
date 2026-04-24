#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "controls.h"


int main() {

	setlocale(LC_ALL, "");

	char message[MAXN] = "Menu";
	struct Car *storage = malloc(MAXN * sizeof(struct Car));
	int storage_size = 0;

	// Вывод вариантов использования Кучерявый
	while (1) {
		print_menu(message);
		char inp = getchar();
		
		printf("\033[H\033[J");
		action(inp, storage, &storage_size, message);
	}
}