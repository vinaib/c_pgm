#include<stdio.h>

#include<stdint.h>
#include <continuous.h>
#include <discrete.h>
#include <rb.h>

#include<pthread.h>

#include<unistd.h>

rb_t spk_q;
rb_t mic_q;

int32_t exit_th = 0;

uint8_t spk_buff[8800];

uint8_t mic_buff[8800];

#if defined(DISCRETE_RB) && !defined(CONTINUOUS_RB)
init_rb_t 			init_rb 	= init_d_rb; 
is_rb_full_t 			is_rb_full	= is_d_rb_full;
is_rb_empty_t 			is_rb_empty 	= is_d_rb_full;
get_rb_size_t 			get_rb_size 	= get_d_rb_size;
get_read_idx_t 			get_read_idx 	= get_d_read_idx;
get_write_idx_t 		get_write_idx 	= get_d_write_idx;
get_elements_t 			get_elements	= get_d_elements;
get_free_elements_t 		get_free_elements 	= get_d_free_elements;
increment_read_idx_t 		increment_read_idx 	= increment_d_read_idx;
increment_write_idx_t 		increment_write_idx 	= increment_d_write_idx;
get_and_increment_write_idx_t 	get_and_increment_write_idx 	= get_and_increment_d_write_idx;

#elif !defined(DISCRETE_RB) && defined(CONTINUOUS_RB)
init_rb_t 			init_rb 	= init_c_rb; 
is_rb_full_t 			is_rb_full 	= is_c_rb_full;
is_rb_empty_t 			is_rb_empty 	= is_c_rb_full;
get_rb_size_t 			get_rb_size 	= get_c_rb_size;
get_read_idx_t 			get_read_idx 	= get_c_read_idx;
get_write_idx_t 		get_write_idx 	= get_c_write_idx;
get_elements_t 			get_elements 	= get_c_elements;
get_free_elements_t 		get_free_elements 	= get_c_free_elements;
increment_read_idx_t 		increment_read_idx 	= increment_c_read_idx;
increment_write_idx_t 		increment_write_idx 	= increment_c_write_idx;
get_and_increment_write_idx_t 	get_and_increment_write_idx = get_and_increment_c_write_idx;

#elif !defined(DISCRETE_RB) && !defined(CONTINUOUS_RB)
#error "Define any one RB mechanism"
#endif

/* 
 * Function: usb_rx_func
 */
void *usb_rx_func(void *ptr)
{
 int32_t idx;

 int32_t iter = 0;

 static int32_t pr_usb_rx = 0;

 #ifdef DEBUG
 printf("%s\n", (char*)ptr);
 #endif

 while(!exit_th)
 {
  usleep(1000);

  idx = get_and_increment_write_idx(&spk_q);
  
  if(ERBFULL == idx)
  {
    printf("SPKQ FULL\n");
    continue;    
  } 

  idx = idx * ELEMENT_SZ;

  for(iter = 0; iter < 288; iter++)
  {
   spk_buff[idx + iter] = 1;
  }

  if(5000 < ++pr_usb_rx)
  {
   printf("USBRX RUNNING %d %d %d %d\r\n",
    get_elements(&spk_q),
    get_free_elements(&spk_q),
    spk_q.iread,
    spk_q.iwrite);

   pr_usb_rx = 0;
  } 
 } // while(!exit_th)

 return NULL;
}

/* 
 * Function: usb_tx_func
 */
void *usb_tx_func(void *ptr)
{
 int32_t idx;

 int32_t iter;

 static int32_t pr_usb_tx = 0;

 #ifdef DEBUG
 printf("%s\n", (char*)ptr);
 #endif

 while(!exit_th)
 {
   usleep(985);

   if(THRESHOLD > get_elements(&mic_q))
   {
    continue;
   }

   idx = get_read_idx(&mic_q);
 
   if(ERBEMPTY == idx)
   {
    printf("MICQ EMPTY\r\n");
    continue;
   }

   for(iter = 0; iter<288; iter++)
   {
    mic_buff[idx + iter] = 0;
   }  
  
   idx = increment_read_idx(&mic_q);
   
   if(ERBEMPTY == idx)
   {
    printf("MICQ EMPTY 2\r\n");
    continue;
   }
   
   if(5000 < ++pr_usb_tx)
   {
     pr_usb_tx = 0;
     printf("USBTX RUNNING %d %d %d %d\r\n",
      get_elements(&mic_q),
      get_free_elements(&mic_q),
      mic_q.iread,
      mic_q.iwrite);
   }
 }

 return NULL;
}

/* 
 * Function: cdc_rx_func
 */
void *cdc_rx_func(void *ptr)
{
 int32_t idx;

 int32_t iter;

 static int32_t pr_cdc_rx = 0;

 #ifdef DEBUG
 printf("%s\n", (char*)ptr);
 #endif

 while(!exit_th)
 {

  usleep(990);

  idx = get_and_increment_write_idx(&mic_q);

  if(ERBFULL == idx)
  {
   printf("MICQ FULL %d %d\r\n", 
	get_elements(&mic_q), 
        get_free_elements(&mic_q));

   continue;
  }
  
  idx = idx * ELEMENT_SZ;

  for(iter = 0; iter < 288; iter++)
  {
   mic_buff[idx + iter] =  1;
  }

  if(5000 < ++pr_cdc_rx)
  {
   pr_cdc_rx = 0;
   printf("CDCRX RUNNING %d %d %d %d\r\n",
    get_elements(&mic_q),
    get_free_elements(&mic_q),
    mic_q.iread,
    mic_q.iwrite);
  }
 }

 return NULL;
}

/* 
 * Function: cdc_tx_func
 */
void *cdc_tx_func(void *ptr)
{
 int32_t idx;

 int32_t iter;

 static int32_t pr_cdc_tx = 0;

 #ifdef DEBUG
 printf("%s\n", (char*)ptr);
 #endif

 while(!exit_th)
 {

  usleep(990);

  if(THRESHOLD > get_elements(&spk_q))
  {
    continue;
  }

  idx = get_read_idx(&spk_q);
  if(ERBEMPTY == idx)
  {
   printf("SPKQ EMPTY\r\n");
   continue;
  }
  
  idx = idx * ELEMENT_SZ;

  for(iter = 0;iter < 288; iter++)
  {
   spk_buff[idx + iter] = 0;
  }   

  idx = increment_read_idx(&spk_q);
  if(ERBEMPTY == idx)
  {
   printf("SPKQ EMPTY 2\r\n");
   continue;
  }
  
  if(5000 < ++pr_cdc_tx)
  {
   printf("CDCTX RUNNING %d %d %d %d\r\n",
    get_elements(&spk_q),
    get_free_elements(&spk_q),
    spk_q.iread,
    spk_q.iwrite);
   pr_cdc_tx = 0;
  } 
 }

 return NULL;
}

/* 
 * Function: main
 */
int main(int argc, char *argv[])
{
 printf("Ringbuff Implementation\n");

 pthread_t usb_rx, usb_tx, cdc_rx, cdc_tx;
 char *msg1 = "USB RX THREAD";
 char *msg2 = "USB TX THREAD";
 char *msg3 = "CDC RX THREAD";
 char *msg4 = "CDC TX THREAD";

 int32_t usb_rx_id;
 int32_t usb_tx_id;
 int32_t cdc_rx_id;
 int32_t cdc_tx_id;

 init_rb(&spk_q, ELEMENTS);

 init_rb(&mic_q, ELEMENTS);

 usb_rx_id = pthread_create(
	&usb_rx,
	NULL,
	usb_rx_func,
	(void *)msg1);

 cdc_rx_id = pthread_create(
	&cdc_rx,
	NULL,
	cdc_rx_func,
	(void *)msg3);

 usb_tx_id = pthread_create(
	&usb_tx,
	NULL,
	usb_tx_func,
	(void *)msg2);

 cdc_tx_id = pthread_create(
	&cdc_tx,
	NULL,
	cdc_tx_func,
	(void *)msg4);

 getchar();

 exit_th = 1;

 pthread_join(usb_rx, NULL);
 pthread_join(usb_tx, NULL);
 pthread_join(cdc_rx, NULL);
 pthread_join(cdc_tx, NULL);


 printf("USB RX THREAD Exits(%d)\n", usb_rx_id);
 printf("USB TX THREAD Exits(%d)\n", usb_tx_id);
 printf("CDC RX THREAD Exits(%d)\n", cdc_rx_id);
 printf("CDC TX THREAD Exits(%d)\n", cdc_tx_id);
 return 0;
}
