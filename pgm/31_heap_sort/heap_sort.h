#ifndef __HEAP_SORT_H_
#define __HEAP_SORT_H_

#include<stdint.h>

void create_heap(int32_t h[], int32_t n);

void insert_element_into_heap(int32_t h[], int32_t n);

int32_t delete_element_from_heap(int32_t h[], int32_t n);

#endif /* __HEAP_SORT_H_ */
