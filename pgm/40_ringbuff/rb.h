#ifndef __RB_H
#define __RB_H

#define ELEMENTS 10

#define ELEMENT_SZ 880

#define RB_SIZE (8800)

#define THRESHOLD 5

#undef DEBUG

#undef DISCRETE_RB

#define CONTINUOUS_RB

#define DEBUG_THREAD

typedef struct rb {
 uint32_t iread;
 uint32_t iwrite;
 uint32_t irbsize;
 uint32_t ielesize;
 uint32_t full;
}rb_t;

typedef enum rb_error {
 ERBSUCCESS 	= 0,
 ERBFULL	= -1,
 ERBEMPTY	= -2,
 ERBOVERFLOW	= ERBFULL,
 ERBUNDERFLOW	= ERBEMPTY,
}rb_error_t;

typedef void (*init_rb_t) (rb_t *rb, int32_t rbsz, int32_t elesz);
typedef int32_t (*get_write_idx_t) (rb_t *rb);
typedef int32_t (*get_read_idx_t) (rb_t *rb);
typedef int32_t (*increment_write_idx_t) (rb_t *rb);
typedef int32_t (*increment_read_idx_t) (rb_t *rb);
typedef int32_t (*get_and_increment_write_idx_t) (rb_t *rb);
typedef uint32_t (*get_elements_t) (rb_t *rb);
typedef uint32_t (*get_free_elements_t) (rb_t *rb);
typedef int32_t (*is_rb_full_t) (rb_t *rb);
typedef int32_t (*is_rb_empty_t) (rb_t *rb);
typedef int32_t (*get_rb_size_t) (rb_t *rb);

#endif // __RB_H
