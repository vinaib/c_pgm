#ifndef __CONTINUOUS_H
#define __CONTINUOUS_H

#include<stdint.h>
#include "rb.h"

void init_c_rb(rb_t *rb, int32_t rbsz, int32_t elesz);

int32_t get_c_write_idx(rb_t *rb);

int32_t get_c_read_idx(rb_t *rb);

int32_t increment_c_write_idx(rb_t *rb);

int32_t increment_c_read_idx(rb_t *rb);

int32_t get_and_increment_c_write_idx(rb_t *rb);

uint32_t get_c_elements(rb_t *rb);

uint32_t get_c_free_elements(rb_t *rb);

int32_t is_c_rb_full(rb_t *rb);

int32_t is_c_rb_empty(rb_t *rb);

int32_t get_c_rb_size(rb_t *rb);
#endif //__CONTINUOUS_H
