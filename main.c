#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "controls.h"


int main() {

	setlocale(LC_ALL, "");

	// Вывод вариантов использования Кучерявый
	while (1) {
		print_menu("Menu");
		char inp = getchar();
		
		printf("\033[H\033[J");
		
		action(inp);

	}
}