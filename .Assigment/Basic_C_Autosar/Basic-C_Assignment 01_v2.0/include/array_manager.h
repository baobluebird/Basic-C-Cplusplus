#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H

#include <stdbool.h>

void create_array();
void print_array();
void insert_element(int position, int value);
void delete_element(int position);
void sort_array_ascending();
void sort_array_descending();
bool find_element(int value);

#endif
