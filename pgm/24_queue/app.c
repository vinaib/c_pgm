#include<queue.h>
#include<stdint.h>
#include<stdio.h>

/* globals */
xQueue_t xq;

static void demo_linear_queue()
{
	int32_t idata;
	int32_t iret;
	eQerr_t err;

	/* Lesson learnt: 
	 * if sz input parameter is uint32_t then passing -1
	 * to sz will be promoted to 0xFFFFFFFF value, which
	 * is very huge, then chances are to see malloc failure
	 * and also see OOM, which may kill the process.
	 */
	err = init_queue(&xq, queueNSIZE);
	if(err < 0)
		check_qerr(err);

	err = init_queue(NULL, queueSIZE);
	if(err < 0)
		check_qerr(err);

	err = init_queue(&xq, queueSIZE);
	if(err < 0)
		check_qerr(err);

	for(uint32_t i = 1; i<=queueSIZE; i++) {
		err = enqueue(&xq, i);
		if(err < 0)
			check_qerr(err);
		else
			printf("%d inserted at pos %d(rear) %d(front)\n", i, xq.irear, xq.ifront);
	}

	for(uint32_t i = 1; i<=queueSIZE; i++) {
		err = dequeue(&xq, &idata);
		if(err < 0)
			check_qerr(err);
		else
			printf("%d deleted from pos %d(front) %d(rear)\n", idata, xq.ifront, xq.irear);
	}

	err = enqueue(&xq, (queueSIZE+1));
	if(err < 0)
		check_qerr(err);
	else
		printf("%d inserted at pos %d(rear) %d(front)\n", (queueSIZE+1), xq.irear, xq.ifront);

	err = dequeue(&xq, &idata);
	if(err < 0)
		check_qerr(err);
	else
		printf("%d deleted from pos %d(front) %d(rear)\n", idata, xq.ifront, xq.irear);

	deinit_queue(&xq);

	return;
}

static void demo_circular_queue()
{
	int32_t idata;
	int32_t iret;
	eQerr_t err;

	/* Circular queue demo */
	err = init_cqueue(&xq, queueSIZE);
	if(err < 0)
		check_qerr(err);
	
	for(uint32_t i = 1; i<queueSIZE; i++) {
		err = cenqueue(&xq, i);
		if(err < 0)
			check_qerr(err);
		else
			printf("%d inserted at pos %d(rear) %d(front)\n", i, xq.irear, xq.ifront);
	}

	for(uint32_t i = 1; i<queueSIZE; i++) {
		err = cdequeue(&xq, &idata);
		if(err < 0)
			check_qerr(err);
		else
			printf("%d deleted from pos %d(front) %d(rear)\n", idata, xq.ifront, xq.irear);
	}

	err = cenqueue(&xq, (queueSIZE+1));
	if(err < 0)
		check_qerr(err);
	else
		printf("%d inserted at pos %d(rear) %d(front)\n", (queueSIZE+1), xq.irear, xq.ifront);

	err = cdequeue(&xq, &idata);
	if(err < 0)
		check_qerr(err);
	else
		printf("%d deleted from pos %d(front) %d(rear)\n", idata, xq.ifront, xq.irear);

	deinit_queue(&xq);

	return;
}

void demo_linkedlist_queue(void)
{
	eQerr_t err;
	int32_t idata;

	init_llqueue(&xq);
	
	for(uint32_t i = 1; i < queueLLSIZE; i++) {
		err = llenqueue(&xq, i);
		if(err < 0)
			check_qerr(err);
		else
			printf("Insert %d size %d\n", i, xq.isize);
	}

	for(uint32_t i = 1; i < queueLLSIZE; i++) {
		err = lldequeue(&xq, &idata);
		if(err < 0)
			check_qerr(err);
		else
			printf("Delete %d size %d\n", idata, xq.isize);
	}
		
	deinit_queue(&xq);
}

int main(void)
{
	demo_linear_queue();

	demo_circular_queue();

	demo_linkedlist_queue();
}
