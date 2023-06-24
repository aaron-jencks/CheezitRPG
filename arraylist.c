#include <stdlib.h>

#include "arraylist.h"
#include "error.h"

arraylist_t create_arraylist(size_t capacity) {
  arraylist_t result;
  result.count = 0;
  result.capacity = capacity;
  result.comparator = NULL;
  result.arr = (variant_t*)malloc(sizeof(variant_t) * capacity);
  handle_memory_error(result.arr);
  return result;
}

void destroy_arraylist(arraylist_t arr) {
  free(arr.arr);
}

void destroy_arraylist_ptr(arraylist_t arr) {
  while(arr.count) free(arraylist_pop(&arr).ptr);
  free(arr.arr);
}

size_t arraylist_append(arraylist_t* arr, variant_t item) {
  if(arr->count == arr->capacity) {
    arr->capacity <<= 1;
    arr->arr = (variant_t*)realloc(arr->arr, sizeof(variant_t) * arr->capacity);
    handle_memory_error(arr->arr);
  }
  arr->arr[arr->count] = item;
  return arr->count++;
}

size_t arraylist_append_p(arraylist_t* arr, void* ptr) {
  variant_t v;
  v.ptr = ptr;
  return arraylist_append(arr, v);
}

size_t arraylist_append_u8(arraylist_t* arr, uint8_t u) {
  variant_t v;
  v.u8 = u;
  return arraylist_append(arr, v);
}

size_t arraylist_append_i(arraylist_t* arr, int i) {
  variant_t v;
  v.i = i;
  return arraylist_append(arr, v);
}

variant_t arraylist_pop(arraylist_t* arr) {
  if(!arr->count) return (variant_t){0};
  return arr->arr[--arr->count];
}

variant_t arraylist_pop_front(arraylist_t* arr) {
  if(!arr->count) return (variant_t){0};
  variant_t result = arr->arr[0];
  for(size_t i = 0; i < arr->count; i++) {
    arr->arr[i-1] = arr->arr[i];
  }
  arr->count--;
  return result;
}

variant_t arraylist_remove(arraylist_t* arr, size_t index) {
  if(index >= arr->count) return (variant_t){0};
  variant_t result = arr->arr[index];
  for(size_t i = index + 1; i < arr->count; i++) {
    arr->arr[i - 1] = arr->arr[i];
  }
  arr->count--;
  return result;
}

bool arraylist_contains(arraylist_t arr, variant_t v) {
  if(!arr.comparator) handle_error(1, 
    "To use arraylist_contains, please define arr.comparator\n");
  for(size_t i = 0; i < arr.count; i++) {
    if(!arr.comparator(v, arr.arr[i])) return true;
  }
  return false;
}

size_t arraylist_find(arraylist_t arr, variant_t v) {
  if(!arr.comparator) handle_error(1, 
    "To use arraylist_contains, please define arr.comparator\n");
  for(size_t i = 0; i < arr.count; i++) {
    if(!arr.comparator(v, arr.arr[i])) return i;
  }
  return arr.count;
}

void arraylist_clear_ptr(arraylist_t* arr) {
  for(size_t i = 0; i < arr->count; i++) {
    free(arr->arr[i].ptr);
  }
  arraylist_clear(arr);
}

