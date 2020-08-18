#include<queue.h>
#include<stdio.h>
#include<stdint.h>

#define QSZ 10

typedef enum Prio_qname {
	eHARD_REALTIME_PRIO = 0,
	eSOFT_REALTIME_PRIO = 1,
	eNORMAL				= 2,
	eNUM_PRIORITIES,
}xPrio_qname_t;

QUEUE_t prio_q[eNUM_PRIORITIES];

EERR_t enqueue_to_prioq(QUEUE_t *xq, xPrio_qname_t priority, int32_t e)
{
	switch(priority) {
		case eHARD_REALTIME_PRIO:
			return enqueue(&xq[eHARD_REALTIME_PRIO], e);
		case eSOFT_REALTIME_PRIO:
			return enqueue(&xq[eSOFT_REALTIME_PRIO], e);
		case eNORMAL:
			return enqueue(&xq[eNORMAL], e);
	}
}

EERR_t dequeue_from_prioq(QUEUE_t *xq, int *d)
{
	EERR_t err;

	err = dequeue(&xq[eHARD_REALTIME_PRIO], d);
	if(err == eQUEUE_EMPTY) {
		err = dequeue(&xq[eSOFT_REALTIME_PRIO], d);
		if(err == eQUEUE_EMPTY) {
			err = dequeue(&xq[eNORMAL], d);
		}
	}

	return err;
}

EERR_t print_prioq(QUEUE_t *xq)
{
	EERR_t err;
	int32_t i;

	for(i=0;i<eNUM_PRIORITIES;i++) {
		printf("Priority Q %d\n", i);
		err = print_q(&xq[i]);
	}
}

void populate_prioq(QUEUE_t *xq)
{
	int32_t i;

	for(i=1;i<=3*QSZ;i+=3) {
		enqueue(&xq[eHARD_REALTIME_PRIO], i);
		enqueue(&xq[eSOFT_REALTIME_PRIO], i+1);
		enqueue(&xq[eNORMAL], i+2);
	}
}

int main(void)
{
	int32_t i;
	int32_t d;
	EERR_t err;
	int32_t ch;
	int32_t prio;
	int32_t tid;

#ifdef SINGLE_Q
	for(i=0; i<QSZ; i++) {
		err = enqueue(&prio_q[0], i);
	}

	err = print_q(&prio_q[0]);

	for(i=0;i<QSZ;i++) {
		err = dequeue(&prio_q[0], &d);
		printf("Deleted item %d\n", d);
	}

	err = print_q(&prio_q[0]);
#endif

	while(1) {
		printf("1 - enqueue 2 - dequeue 3 - printall 4 - exit 5 - populate\n");
		scanf("%d", &ch);

		switch(ch) {
			case 1:
				printf("Enter task id, priority(1,2,3): ");
				scanf("%d %d", &tid, &prio);
				err = enqueue_to_prioq(prio_q, prio-1, tid);
				break;
			case 2:
				err= dequeue_from_prioq(prio_q, &d);
				if(err == eQUEUE_NOERR) {
					printf("tid: %d\n", d);
				}
				break;
			case 3:
				err = print_prioq(prio_q);
				break;
			case 4:
				goto EXIT_FUNC;
			case 5:
				populate_prioq(prio_q);
				break;
			default:
				printf("Enter proper choice\n");
		}
	}

EXIT_FUNC:
	return 0;
}
