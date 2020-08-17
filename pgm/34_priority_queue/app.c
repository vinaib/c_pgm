#include<queue.h>
#include<stdio.h>
#include<stdint.h>

#define QSZ 10
QUEUE_t prio_q[1];

int main(void)
{
	int32_t i;
	int32_t d;
	EERR_t err;

	for(i=0; i<QSZ; i++) {
		err = enqueue(&prio_q[0], i);
	}

	err = print_q(&prio_q[0]);

	for(i=0;i<QSZ;i++) {
		err = dequeue(&prio_q[0], &d);
		printf("Deleted item %d\n", d);
	}

	err = print_q(&prio_q[0]);

	return 0;
}
