#include "controls.h"
#include <string.h>


// Выбор действия
void action(char action_num, struct Car* storage, int* return_size, char* message) {

	switch (action_num) {
		case '0':
			exit(0);
			break;
		case '1':
			import_file(storage, return_size, message);
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
			export_file(storage, return_size, message);
			break;
		case '9':
			
			break;

	}

	return;
}

//Вывод меню в консоль
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
		"9. Отпечатать файл или массив с разбивкой по страницам и шапкой с номером страницы\n>>>",
		message);
}

// Чтение файла в массив (1)
void import_file(struct Car* storage, int *return_size, char* message) {

	*return_size = 0;
	struct Car tmp;

	FILE* f_in = fopen("in.txt", "r");

	// Проверка на корректность открытия файла
	if (f_in == NULL) {
		strcpy(message, "ОШИБКА: Файл не найден");
		return;
	}

	while (*return_size < MAXN && fscanf(f_in, "%d %d.%d.%d %s %s %d",
		&tmp.id, &tmp.date.day, &tmp.date.month, &tmp.date.year, tmp.manager, tmp.marka, &tmp.cost) == 7) {
		storage[*return_size] = tmp;
		*return_size += 1;
	}
	fclose(f_in);

	strcpy(message, "УСПЕХ: Файл успешно импортирован");
}

// Запись массива в файл (8)
void export_file(struct Car* storage, int* return_size, char* message) {
	
	// Проверка на наличие данных в системе
	if (*return_size < 1) {
		strcpy(message, "ОШИБКА: Внутреннее хранилище пусто, в файл ничего не записано");
		return;
	}

	FILE *f_out = fopen("out.txt", "w");

	for (int i = 0; i < *return_size; i++) {
		fprintf(f_out, "%d %d.%d.%d %s %s %d\n", storage[i].id, storage[i].date.day, storage[i].date.month, storage[i].date.year, storage[i].manager, storage[i].marka, storage[i].cost);
	}
	fclose(f_out);

	strcpy(message, "УСПЕХ: Данные успешно экспортированы");

}