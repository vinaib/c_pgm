#include"continuous.h"
#include<stdio.h>

void init_c_rb(rb_t *rb, int32_t sz)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 rb->iread = rb->iwrite = 0;
 rb->isize = sz;
 rb->full = 0;
}

int32_t get_c_write_idx(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 if(rb->full)
 {
  return ERBFULL;
 }

 return rb->iwrite;
}

int32_t get_c_read_idx(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 if(is_c_rb_empty(rb))
 {
  return ERBEMPTY;
 }

 return rb->iread;
}

int32_t increment_c_write_idx(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
}

int32_t increment_c_read_idx(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
}

int32_t get_and_increment_c_write_idx(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
}

int32_t get_c_elements(rb_t *rb)
{
 int32_t ele = rb->isize;

#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 if(!rb->full) 
 {
  if(rb->iread == rb->iwrite) 
  {
   ele = 0;
  }
  else if(rb->iwrite > rb->iread)
  {
   ele = rb->iwrite - rb->iread;
  }
  else
  {
   ele = (rb->iread + rb->isize) - rb->iwrite;
  }
 }
 
 return ele;
}

int32_t get_c_free_elements(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 return rb->isize - get_c_elements(rb);
}

int32_t is_c_rb_full(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 return rb->full;
}

int32_t is_c_rb_empty(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 return (!rb->full &&
         (rb->iread == rb->iwrite));
}

int32_t get_c_rb_size(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 return rb->isize;
}
