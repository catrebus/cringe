#include "controls.h"
#include <string.h>

// =============================================================================
// ПРОТОТИПЫ ВНУТРЕННИХ ФУНКЦИЙ
// =============================================================================

// Чтение файла в массив
static void import_file(struct Car* storage, int* return_size, char* message);

// Запись массива в файл 
static void export_file(struct Car* storage, int* return_size, char* message);

// Поиск индекса строки с указанным id
// Возвращает -1, если строка не найдена
static int is_id_exists(int id, struct Car* storage, int size);

// Ввод строки файла
static void insert_car_info(struct Car* tmp);

// Добавление новой строки
static void add_new_line(struct Car* storage, int* return_size, char* message);

// Удаление строки по id
static void delete_line(struct Car* storage, int* return_size, char* message);

// Замена строки по id на введеные в консоль данные
static void replace_line(struct Car* storage, int* return_size, char* message);

// Чистка буфера
static void clear_buf();

// =============================================================================
// ВНЕШНИЕ ФУНКЦИИ
// =============================================================================

//Функция для выполнения действия с внутренним хранилищем в соответствии с полученным как аргумент номером действия
void action(char action_num, struct Car* storage, int* return_size, char* message) {

	switch (action_num) {
		case '0': exit(0);										break;
		case '1': import_file(storage, return_size, message);	break;
		case '2': add_new_line(storage, return_size, message);	break;
		case '3': delete_line(storage, return_size, message);	break;
		case '4': replace_line(storage, return_size, message);	break;
		case '5':												break;
		case '6':												break;
		case '7':												break;
		case '8': export_file(storage, return_size, message);	break;
		case '9':												break;
	}
}

//Функция для вывода вариантов использования программы
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

// =============================================================================
// ВНУТРЕННИЕ ФУНКЦИИ
// =============================================================================

void clear_buf() {
	while (getchar() != '\n');
}

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


int is_id_exists(int id, struct Car* storage, int size) {

	for (int i = 0; i < size; i++) {
		if (storage[i].id == id) {
			return i;
		}
	}
	return -1;
}

void insert_car_info(struct Car* tmp) {
	
	// Ввод даты
	while (1) {

		printf("Введите дату(dd.mm.yyyy): ");
		if (scanf("%d.%d.%d", &tmp->date.day, &tmp->date.month, &tmp->date.year) != 3) {
			clear_buf();
			printf("\033[H\033[J");
			printf("Ошибка, попробуйте еще раз\n");
			continue;
		}
		break;
	}
	printf("\033[H\033[J");

	// Ввод фамилии менеджера
	while (1) {
		printf("Введите фамилию менеджера: ");
		if (scanf("%99s", &tmp->manager) != 1) {
			clear_buf();
			printf("\033[H\033[J");
			printf("Ошибка, попробуйте еще раз\n");
			continue;
		}
		break;
	}
	printf("\033[H\033[J");

	//Ввод марки автомобиля
	while (1) {
		printf("Введите марку автомобиля: ");
		if (scanf("%39s", &tmp->marka) != 1) {
			clear_buf();
			printf("\033[H\033[J");
			printf("Ошибка, попробуйте еще раз\n");
			continue;
		}
		break;
	}
	printf("\033[H\033[J");

	//Ввод цены
	while (1) {
		printf("Введите цену: ");
		if (scanf("%d", &tmp->cost) != 1) {
			clear_buf();
			printf("\033[H\033[J");
			printf("Ошибка, попробуйте еще раз\n");
			continue;
		}
		break;
	}
	printf("\033[H\033[J");
}

void add_new_line(struct Car* storage, int* return_size, char* message) {
	
	struct Car tmp;

	// Ввод id
	while (1) {
		printf("Введите id: ");

		if (scanf("%d", &tmp.id) != 1) {
			clear_buf();
			printf("\033[H\033[J");
			printf("Ошибка, попробуйте еще раз\n");
			continue;
		}

		if (is_id_exists(tmp.id, storage, *return_size) != -1) {
			printf("\033[H\033[J");
			printf("Введенный вами id уже существует, попробуйте еще раз\n");
			continue;
		}
		break;
	}
	printf("\033[H\033[J");

	insert_car_info(&tmp);

	storage[*return_size] = tmp;
	*return_size += 1;
	strcpy(message, "УСПЕХ: Строка успешно добавлена");
}

void delete_line(struct Car* storage, int* return_size, char* message) {
	int line_id = 0;
	int line_idx = 0;

	// Ввод id для удаления
	while (1) {
		printf("Введите id удаляемой строки: ");
		if (scanf("%d", &line_id) != 1) {
			clear_buf();
			printf("\033[H\033[J");
			printf("Ошибка, попробуйте еще раз\n");
			continue;
		}

		line_idx = is_id_exists(line_id, storage, *return_size);
		if (line_idx == -1) {
			printf("\033[H\033[J");
			printf("Введенный вами id не существует, попробуйте еще раз\n");
			continue;
		}
		break;
	}

	// Сдвиг элементов массива до удаляемого
	for (int i = line_idx; i < *return_size-1; i++) {
		storage[i] = storage[i + 1];
	}

	*return_size -= 1;
	strcpy(message, "УСПЕХ: Строка успешно удалена");
}

void replace_line(struct Car* storage, int* return_size, char* message) {
	int line_id = 0;
	int line_idx = 0;

	// Ввод id для изменения
	while (1) {
		printf("Введите id изменяемой строки: ");
		if (scanf("%d", &line_id) != 1) {
			clear_buf();
			printf("\033[H\033[J");
			printf("Ошибка, попробуйте еще раз\n");
			continue;
		}

		line_idx = is_id_exists(line_id, storage, *return_size);
		if (line_idx == -1) {
			printf("\033[H\033[J");
			printf("Введенный вами id не существует, попробуйте еще раз\n");
			continue;
		}
		break;
	}

	struct Car tmp;
	tmp.id = line_id;
	insert_car_info(&tmp);
	storage[line_idx] = tmp;
	strcpy(message, "УСПЕХ: Строка успешно изменена");
}