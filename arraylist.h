#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "types.h"

typedef struct {
  variant_t* arr;
  size_t capacity;
  size_t count;
  comparator_t comparator;
} arraylist_t;

arraylist_t create_arraylist(size_t capacity);

void destroy_arraylist(arraylist_t arr);
void destroy_arraylist_ptr(arraylist_t arr);

size_t arraylist_append(arraylist_t* arr, variant_t item);
size_t arraylist_append_p(arraylist_t* arr, void* ptr);
size_t arraylist_append_u8(arraylist_t* arr, uint8_t u);
size_t arraylist_append_i(arraylist_t* arr, int i);

#define arraylist_append_st(arr, item) (arraylist_append(arr, st_to_v(item)))

variant_t arraylist_pop(arraylist_t* arr);
variant_t arraylist_pop_front(arraylist_t* arr);

variant_t arraylist_remove(arraylist_t* arr, size_t index);

bool arraylist_contains(arraylist_t arr, variant_t v);
size_t arraylist_find(arraylist_t arr, variant_t v);

#define arraylist_clear(arr) ((arr)->count = 0)
void arraylist_clear_ptr(arraylist_t* arr);

#endif
