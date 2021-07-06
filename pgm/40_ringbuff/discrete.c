#include "discrete.h"
#include<stdio.h>

void init_d_rb(rb_t *rb, int32_t sz)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 rb->iread = rb->iwrite = 0;
 rb->isize = sz;
 rb->full = 0;
}

int32_t get_d_write_idx(rb_t *rb)
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

int32_t get_d_read_idx(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 if(is_d_rb_empty(rb))
 {
  return ERBEMPTY;
 }

 return rb->iread;
}

int32_t increment_d_write_idx(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif

 if(rb->full)
 {
  return ERBFULL;
 }

 rb->iwrite = (rb->iwrite + 1)%rb->isize;

 rb->full = (rb->iwrite == rb->iread);

 return ERBSUCCESS;
}

int32_t increment_d_read_idx(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif

 if(is_d_rb_empty(rb))
 {
  return ERBEMPTY;
 }

 rb->full = 0;

 rb->iread = (rb->iread + 1) % rb->isize;

 return ERBSUCCESS;
}

int32_t get_and_increment_d_write_idx(rb_t *rb)
{
 int32_t idx = 0;

#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 
 if(rb->full)
 {
  return ERBFULL;
 }
 
 idx = rb->iwrite;

 rb->iwrite = (rb->iwrite + 1)%rb->isize;

 rb->full = (rb->iwrite == rb->iread);

 return idx;
}

int32_t get_d_elements(rb_t *rb)
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

int32_t get_d_free_elements(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 return rb->isize - get_d_elements(rb);
}

int32_t is_d_rb_full(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 return rb->full;
}

int32_t is_d_rb_empty(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 return (!rb->full &&
         (rb->iread == rb->iwrite));
}

int32_t get_d_rb_size(rb_t *rb)
{
#ifdef DEBUG
 printf("%s\r\n", __FUNCTION__);
#endif
 return rb->isize;
}
