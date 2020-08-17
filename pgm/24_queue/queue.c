#include<queue.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/************************************************************
* Array Implemenetation: Linear Queue
* Initial condition: front = rear = -1
* insert: increment rear and insert
* delete: increment front and delete
* Queue full: rear == (size - 1)
* Queue Empty: front == rear
************************************************************/
eQerr_t init_queue(xQueue_t *xpq, int32_t isz)
{
	if(isz <= 0)
		return ENONEGSZ;

	if(xpq == NULL)
		return ENONULLQPTR;

	xpq->isize = isz;
	xpq->ifront = xpq->irear = -1;

	xpq->piq = (int32_t *)malloc(isz * sizeof(int32_t));
	if(xpq->piq == NULL)
		return ENOMEMFORQ;

	memset(xpq->piq, 0, (isz * sizeof(int32_t)));

	return ESUCCESS;
}

void deinit_queue(xQueue_t *xpq)
{
	if(xpq == NULL)
		return;

	if(xpq->piq != NULL)
		free(xpq->piq);

	xpq->piq = NULL;
	xpq->xfront = xpq->xrear = NULL;

	xpq->isize = 0;
}

void check_qerr(eQerr_t err)
{
	switch(err) {
		case ENONEGSZ: 
			printf("ENONEGSZ\n");
			break;
		case ENONULLQPTR:
			printf("ENONULLQPTR\n");
			break;
		case ENOMEMFORQ:
			printf("ENOMEMFORQ\n");
			break;
		case EQFULL:
			printf("EQFULL\n");
			break;
		case EQEMPTY:
			printf("EQEMPTY\n");
			break;
		case ESUCCESS:
			printf("ESUCCESS\n");
			break;
	}
}

eQerr_t enqueue(xQueue_t *xpq, int32_t idata)
{
	eQerr_t err = ESUCCESS;

	if(xpq->irear == (xpq->isize - 1))
		return EQFULL;

	xpq->irear++;
	xpq->piq[xpq->irear] = idata;
	
	return err;
}


eQerr_t dequeue(xQueue_t *xpq, int32_t *pidata)
{
	eQerr_t err = ESUCCESS;
	
	if(xpq->irear == xpq->ifront)
		return EQEMPTY;

	xpq->ifront++;

	*pidata = xpq->piq[xpq->ifront];

	xpq->piq[xpq->ifront] = 0;

	return err;
}

/************************************************************
* Array Implementation: Circular queue
* initial condition: front = rear = 0
* insert: increment rear and insert, Do not insert item 
*         where f is pointing to.
*		  rear = (rear +1)%size
* delete: increment front and delete.
*			front = (front+1) % size
* queue full: (rear+1)%qsize == front
* queue empty: (rear == front)
************************************************************/
eQerr_t init_cqueue(xQueue_t *xpq, int32_t isz)
{
	if(isz <= 0)
		return ENONEGSZ;

	if(xpq == NULL)
		return ENONULLQPTR;

	xpq->isize = isz;

	/* initial condition differs between circular queue and linear queue */
	xpq->ifront = xpq->irear = 0;

	xpq->piq = (int32_t *)malloc(isz * sizeof(int32_t));
	if(xpq->piq == NULL)
		return ENOMEMFORQ;

	memset(xpq->piq, 0, (isz * sizeof(int32_t)));

	return ESUCCESS;
}

/* O(1) */
eQerr_t cenqueue(xQueue_t *xpq, int32_t idata)
{
	eQerr_t err = ESUCCESS;

	/* check for queue full condition */
	if((xpq->irear+1)%xpq->isize == xpq->ifront)
		return EQFULL;

	xpq->irear = (xpq->irear+1)%xpq->isize;

	xpq->piq[xpq->irear] = idata;

	return err;
}

/* O(1) */
eQerr_t cdequeue(xQueue_t *xpq, int32_t *pidata)
{
	eQerr_t err = ESUCCESS;

	/* check for queue empty condition */
	if(xpq->irear == xpq->ifront)
		return EQEMPTY;

	xpq->ifront = (xpq->ifront+1)%xpq->isize;

	*pidata = xpq->piq[xpq->ifront];

	xpq->piq[xpq->ifront] = 0;
	
	return err;
}

/************************************************************
* Linked List Implemenetation: Linear queue
* initial condition: xfront = xrear = NULL
* insert rear
* delete front
* queue full: if heap is full queue full
* queue empty: xfront = NULL
************************************************************/
eQerr_t init_llqueue(xQueue_t *xpq)
{
	if(xpq == NULL)
		return ENONULLQPTR;

	xpq->isize = 0;
	xpq->xfront = NULL;
	xpq->xrear = NULL;
}

NODE_t *alloc_node(void)
{
	NODE_t *xpnew;

	xpnew = (NODE_t*)malloc(sizeof(NODE_t));
	if(xpnew == NULL)
		return NULL;

	memset((uint8_t *)xpnew, 0, sizeof(NODE_t));

	return xpnew;
}

/* Insert O(1) */
eQerr_t llenqueue(xQueue_t *xpq, int32_t idata)
{
	NODE_t *xnew;

	xnew = alloc_node();
	/* no mem, no heap, treat this condition as Q full */
	if(xnew == NULL)
		return EQFULL;

	xnew->idata = idata;

	/* if new is first element */
	if(xpq->xrear == NULL) {
		xpq->xfront = xpq->xrear = xnew;
		++xpq->isize;
	}
	/* insert rear */
	else {
		xpq->xrear->xnext = xnew;
		xpq->xrear = xnew;
		++xpq->isize;
	}

	return ESUCCESS;
}

/* Delete O(1) */
eQerr_t lldequeue(xQueue_t *xpq, int32_t *pidata)
{
	NODE_t *xtmp;

	if(xpq->xfront == NULL) {
		return EQEMPTY;
	}
	/* delete from front */
	else {
		xtmp = xpq->xfront;
		*pidata = xtmp->idata;
		xpq->xfront = xpq->xfront->xnext;
		free(xtmp);
		--xpq->isize;
	}

	return ESUCCESS;
}
