#ifndef __DISCRETE_H
#define __DISCRETE_H

#include<stdint.h>
#include "rb.h"

void init_d_rb(rb_t *rb, int32_t sz);

int32_t get_d_write_idx(rb_t *rb);

int32_t get_d_read_idx(rb_t *rb);

int32_t increment_d_write_idx(rb_t *rb);

int32_t increment_d_read_idx(rb_t *rb);

int32_t get_and_increment_d_write_idx(rb_t *rb);

int32_t get_d_elements(rb_t *rb);

int32_t get_d_free_elements(rb_t *rb);

int32_t is_d_rb_full(rb_t *rb);

int32_t is_d_rb_empty(rb_t *rb);

int32_t get_d_rb_size(rb_t *rb);

#endif //__DISCRETE_H
