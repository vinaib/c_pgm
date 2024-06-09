#ifndef __QUEUE_H
#define __QUEUE_H

#include<stdint.h>
#include<stdbool.h>

#define queueSIZE 6
#define queueNSIZE -1
#define queueLLSIZE 20
#define queueERRBASE 0x80000


typedef enum queueError {
	ENONEGSZ 	= -(queueERRBASE | 0x1),
	ENONULLQPTR = -(queueERRBASE | 0x2),
	ENOMEMFORQ 	= -(queueERRBASE | 0x3),
	EQFULL		= -(queueERRBASE | 0x4),
	EQEMPTY		= -(queueERRBASE | 0x5),
	ESUCCESS	= 0,
}eQerr_t;

typedef struct node NODE_t;

struct node {
	int32_t idata;
	NODE_t *xnext;
};

typedef struct queue {
	int32_t isize;
	int32_t ifront;
	int32_t irear;
	int32_t *piq;
	/* ds for linked list implementation */
	NODE_t *xfront;
	NODE_t *xrear;
	/* second logic for front/rear, with out
	 * wasting a slot
	*/
	bool full;
}xQueue_t;

/************************************************************
* Array Implemenetation: Linear Queue
************************************************************/
/* 
 * Function: eQerr_t init_queue(xQueue_t *xpq, int32_t isz);
 * input: pointer to q
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
 eQerr_t init_queue(xQueue_t *xpq, int32_t isz);

/* 
 * Function: 
 *  eQerr_t enqueue(xQueue_t *xpq, int32_t idata);
 * input:
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
 eQerr_t enqueue(xQueue_t *xpq, int32_t idata);

/* 
 * Function: 
 *  eQerr_t dequeue(xQueue_t *xpq, int32_t idata);
 * input:
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
eQerr_t dequeue(xQueue_t *xpq, int32_t *pidata);

/* 
 * Function: 
 *  void check_qerr(eQerr_t err)
 * input:
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
void check_qerr(eQerr_t err);

/* 
 * Function: 
 * void deinit_queue(xQueue_t *xpq)
 *
 * input:
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
void deinit_queue(xQueue_t *xpq);

/************************************************************
* Array Implementation: Circular queue
************************************************************/
/* 
 * Function: eQerr_t init_cqueue(xQueue_t *xpq, int32_t isz);
 * input: pointer to q
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
 eQerr_t init_cqueue(xQueue_t *xpq, int32_t isz);

/* 
 * Function: 
 *  eQerr_t cenqueue(xQueue_t *xpq, int32_t idata);
 * input:
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
 eQerr_t cenqueue(xQueue_t *xpq, int32_t idata);
 eQerr_t cenqueue2(xQueue_t *xpq, int32_t idata);
 eQerr_t cenqueue3(xQueue_t *xpq, int32_t idata);

/* 
 * Function: 
 *  eQerr_t cdequeue(xQueue_t *xpq, int32_t idata);
 * input:
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
eQerr_t cdequeue(xQueue_t *xpq, int32_t *pidata);
eQerr_t cdequeue2(xQueue_t *xpq, int32_t *pidata);

eQerr_t cqueue_reset(xQueue_t *xpq);

/************************************************************
* Linked List Implemenetation: Linear queue
************************************************************/
/* 
 * Function: NODE_t* alloc_node(void)
 * input: 
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
 NODE_t *alloc_node(void);

/* 
 * Function: eQerr_t init_llqueue(xQueue_t *xpq)
 * input: pointer to q
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
 eQerr_t init_llqueue(xQueue_t *xpq);

/* 
 * Function: 
 *  eQerr_t llenqueue(xQueue_t *xpq, int32_t idata);
 * input:
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
 eQerr_t llenqueue(xQueue_t *xpq, int32_t idata);

/* 
 * Function: 
 *  eQerr_t lldequeue(xQueue_t *xpq, int32_t idata);
 * input:
 *
 * Output:
 *
 * ret:
 *
 * Description:
 */
eQerr_t lldequeue(xQueue_t *xpq, int32_t *pidata);
 
#endif /* __QUEUE_H */
