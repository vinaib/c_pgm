#include<stdio.h>
#include<stdbool.h>

#include<list.h>

int main(void)
{
	unsigned int ch;
	int loop_iter = 0;

	SLL_T *sll = init_sll(); 
	
	if(sll  == NULL) {
		printf("INITFL\n");
		goto m_exit;
	}

	for(;;) {
		++loop_iter;
		printf("1:INF\t\t2:INL\t\t3:INIDX\t\t");
		printf("4:DNF\t\t5:DNL\t\t6:DNIDX\t\t");
		printf("7:PRN\t\t8:RVR\t\t9:SRCH\t\t");
		printf("10:PREFL\t\t0:EXT\n");
		printf("CHOICE: ");
		scanf("%u", &ch);
		
		switch(ch) {
			case 1: insert_node_at_first(sll, loop_iter); break;
			case 2: insert_node_at_last(sll, loop_iter); break;
			case 3: printf("IDX: ");
					scanf("%u", &ch);
					insert_node_at_idx(sll, ch, loop_iter); 
					break;
			case 4: delete_first_node(sll); break;
			case 5: delete_last_node(sll); break;
			case 6: printf("IDX: ");
					scanf("%u", &ch);
					delete_node_at_idx(sll, ch); 
					break;
			case 7: print_sll(sll); break;
			case 8: reverse_list(sll); break;
			case 9: search_node(sll); break;
			case 10: list_prefill(sll, &loop_iter); break;
			case 0: goto m_exit_1;
			default: printf("CHOICE\n");
		}
	}

m_exit_1:
	free_sll(sll);

m_exit:
	return 0;
}
