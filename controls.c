#include "controls.h"
#include <string.h>

void action(char action_num, struct Car* storage, int* return_size, char* message) {

	switch (action_num) {
		case '0':
			exit(0);
			break;
		case '1':
			load_file(storage, return_size, message);
			break;
		case '2':

			break;
		case '3':

			break;
		case '4':

			break;
		case '5':

			break;
		case '6':

			break;
		case '7':

			break;
		case '8':

			break;
		case '9':

			break;

	}

	return;
}

void print_menu(char* message) {
	printf("--------------------------------------------------------------------------------------\n"
		"|%-84s|\n"
		"--------------------------------------------------------------------------------------\n"
		"0. Выход\n"
		"1. Загрузить данные из входного файла в массив структур\n"
		"2. Добавить строчку в массив\n"
		"3. Удалить строчку по ключу\n"
		"4. Заменить строчку\n"
		"5. Сортировка вставкой\n"
		"6. Сортировка выбором\n"
		"7. Сортировка обменом(пузырек)\n"
		"8. Сохранить данные в файл\n"
		"9. Отпечатать файл или массив с разбивкой по страницам и шапкой с номером страницы\n",
		message);
}

void load_file(struct Car* storage, int *return_size, char* message) {
	FILE *f_in = fopen("in.txt", "r");
	*return_size = 0;

	struct Car tmp;

	while (*return_size < MAXN && fscanf(f_in, "%d %d.%d.%d %s %s %d",
		&tmp.id, &tmp.date.day, &tmp.date.month, &tmp.date.year, tmp.manager, tmp.marka, &tmp.cost) == 7) {
		storage[*return_size] = tmp;
		*return_size += 1;
	}
	strcpy(message, "Файл прочитан корректно");
}

