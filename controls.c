#include "controls.h"

void action(char num) {

	if (num == '0') {
		exit(0);
	}

	if (num == '1') {
		
	}

	if (num == '2') {

	}

	if (num == 3) {

	}

	if (num == 4) {

	}

	if (num == 5) {

	}

	if (num == 6) {

	}

	if (num == 7) {

	}

	if (num == 8) {

	}

	if (num == 9) {

	}

	return;
}

void print_menu(char* output) {
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
		output);
}

void load_file(struct Car* storage, int *return_size) {
	FILE *f_in = fopen("in.txt", "r");
	int *return_size = 0;

	struct Car tmp;

	while (*return_size < MAXN && fscanf(f_in, "%d %d.%d.%d %s %s %d",
		tmp.id, tmp.date.day, tmp.date.month, tmp.date.year, tmp.manager, tmp.marka, tmp.cost) == 7) {
		storage[*return_size] = tmp;
		*return_size += 1;
	}

}