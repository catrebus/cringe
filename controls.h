#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "cost.h"
#define MAXN 100

void action(char, struct Car*, int*, char*);
void print_menu(char*);
void import_file(struct Car*, int*, char*);
void export_file(struct Car*, int*, char*);
void add_new_line(struct Car*, int*, char*);
void delete_line(struct Car*, int*, char*);