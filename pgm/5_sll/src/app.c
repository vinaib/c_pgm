#include<stdio.h>
#include<stdbool.h>

#include<list.h>

int main(void)
{
	int ch;
	int loop_iter = 0;
	
	bool ret = init_sll();
	if(ret == false) 
		printf("init_sll failed\n");

	if(!get_sll()) {
		printf("SLL is empty\n");
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
		scanf("%d", &ch);
		
		switch(ch) {
			case 1: insert_node_at_first(loop_iter); break;
			case 2: delete_first_node(); break;
			case 3: insert_node_at_last(loop_iter); break;
			case 4: delete_last_node(); break;
			case 5: insert_node_at_idx(loop_iter); break;
			case 6: delete_node_at_idx(); break;
			case 7: search_node(); break;
			case 8: print_sll(); break;
			case 0: goto m_exit_1;
			default: printf("Enter proper choice ...\n");
		}
	}
m_exit_1:
	free_sll();

	if(!get_sll()) {
		printf("SLL freed\n");
	}

m_exit:
	return 0;
}
