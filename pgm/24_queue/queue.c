#include<queue.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

eQerr_t llenqueue(xQueue_t *xpq, int32_t idata)
{
	NODE_t *xnew;

	xnew = alloc_node();
	/* no mem, no heap, treat this condition as Q full */
	if(xnew == NULL)
		return EQFULL;

	xnew->idata = idata;
		
	if(xpq->xrear == NULL) {
		xpq->xfront = xpq->xrear = xnew;
		++xpq->isize;
	}
	else {
		xpq->xrear->xnext = xnew;
		xpq->xrear = xnew;
		++xpq->isize;
	}

	return ESUCCESS;
}

eQerr_t lldequeue(xQueue_t *xpq, int32_t *pidata)
{
	NODE_t *xtmp;

	if(xpq->xfront == NULL) {
		return EQEMPTY;
	}
	else {
		xtmp = xpq->xfront;
		*pidata = xtmp->idata;
		xpq->xfront = xpq->xfront->xnext;
		free(xtmp);
		--xpq->isize;
	}

	return ESUCCESS;
}
