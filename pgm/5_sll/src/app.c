#include<stdio.h>
#include<stdbool.h>

#include<list.h>

int main(void)
{
	unsigned int ch;
	int loop_iter = 0;

	SLL_T *sll = init_sll(); 
	
	if(sll  == NULL) {
		printf("NOMEM: INIT FAIL\n");
		goto m_exit;
	}

	for(;;) {
		++loop_iter;
		printf("1 Insert node as first node\n");
		printf("2 delete first node\n");
		printf("3 Insret node as last node\n");
		printf("4 delete last node\n");
		printf("5 Insret node at idx\n");
		printf("6 delete node at idx\n");
		printf("7 search data\n");
		printf("8 Print SLL\n");
		printf("0 for exit\n");
		printf("Enter your choice: ");
		scanf("%u", &ch);
		
		switch(ch) {
			case 1: insert_node_at_first(sll, loop_iter); break;
			case 2: delete_first_node(sll); break;
			case 3: insert_node_at_last(sll, loop_iter); break;
			case 4: delete_last_node(sll); break;
			case 5: printf("Enter idx: ");
					scanf("%u", &ch);
					insert_node_at_idx(sll, ch, loop_iter); 
					break;
			case 6: printf("Enter idx: ");
					scanf("%u", &ch);
					delete_node_at_idx(sll, ch); 
					break;
			case 7: search_node(sll); break;
			case 8: print_sll(sll); break;
			case 0: goto m_exit_1;
			default: printf("Enter proper choice ...\n");
		}
	}

m_exit_1:
	if(free_sll(sll) == NULL) {
		printf("SLL FREE\n");
	}

m_exit:
	return 0;
}
