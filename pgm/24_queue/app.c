#include<queue.h>
#include<stdint.h>
#include<stdio.h>
#include<assert.h>

/* globals */
xQueue_t xq;

static void demo_linear_queue()
{
	int32_t idata;
	int32_t iret;
	eQerr_t err;

	assert(1);

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

	for(uint32_t i = 1; i<=queueSIZE+1; i++) {
		err = enqueue(&xq, i);
		if(err < 0)
			check_qerr(err);
		else
			printf("%d inserted at pos %d(rear) %d(front)\n", i, xq.irear, xq.ifront);
	}

	for(uint32_t i = 1; i<=queueSIZE+1; i++) {
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
	
	for(uint32_t i = 1; i<queueSIZE+2; i++) {
		err = cenqueue(&xq, i);
		if(err < 0)
			check_qerr(err);
		else
			printf("%d inserted at pos %d(rear) %d(front)\n", i, xq.irear, xq.ifront);
	}

	for(uint32_t i = 1; i<queueSIZE+2; i++) {
		err = cdequeue(&xq, &idata);
		if(err < 0)
			check_qerr(err);
		else
			printf("%d deleted from pos %d(front) %d(rear)\n", idata, xq.ifront, xq.irear);
	}

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


static void demo_circular_queue2(void)
{
	int32_t idata;
	int32_t iret;
	eQerr_t err;

	/* Circular queue demo */
	err = init_cqueue(&xq, queueSIZE);
	if(err < 0)
		check_qerr(err);
	
	for(uint32_t i = 1; i<queueSIZE+4; i++) 
	{
		err = cdequeue2(&xq, &idata);
		if(err < 0)
			check_qerr(err);
		if(i==4) err = cenqueue2(&xq, i);
	}

	for(uint32_t i = 1; i<queueSIZE*2; i++) 
	{
		err = cenqueue2(&xq, i);
		if(err < 0)
			check_qerr(err);
	}

	for(uint32_t i = 1; i<queueSIZE+4; i++) 
	{
		err = cdequeue2(&xq, &idata);
		if(err < 0)
			check_qerr(err);
	}

	deinit_queue(&xq);

	return;

}

int main(void)
{
#if 0
	printf("Demo linear queue\r\n");
	demo_linear_queue();

	printf("Demo circular queue\r\n");
	demo_circular_queue();

	printf("Demo linked list queue\r\n");
	demo_linkedlist_queue();
#endif
	printf("Demo circular queue2\r\n");
	demo_circular_queue2();
}
