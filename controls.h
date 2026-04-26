#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "cost.h"
#define MAXN 100


/**
  * @brief Функция выполнения действия с внутренним хранилищем, соответствующее номеру
  * @param action_num Номер действия
  * @param storage Указатель на внутреннее хранилище
  * @param return_size Указатель на размер хранилища
  * @param message Указатель на сообщение, выводимое пользователю
  */
void action(char action_num, struct Car* storage, int* return_size, char* message);

/**
* @brief Функция для вывода вариантов использования программы
* @param message Сообщение для пользователя
*/
void print_menu(char*);
