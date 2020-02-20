#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<dlist.h>

int main(void)
{
	int ret = 0;
	int ch;
	DLL_T *dll;
	int loop_iter = 0;

	dll = init_dll();
	if(dll == NULL) {
		printf("ENOMEM\n");
		ret = -1;
		goto exit_func;
	}

    for(;;) {    
        ++loop_iter;    
        printf("1 Insert node as first node\n");    
        printf("2 delete first node\n");    
        printf("3 Insert node as last node\n");                             
        printf("4 delete last node\n");    
        printf("5 Insert node at idx\n");              
        printf("6 delete node at idx\n");    
        printf("7 search data\n");    
        printf("8 traverse forward\n");    
        printf("9 traverse backward\n");    
        printf("0 for exit\n");    
        printf("Enter your choice: ");    
        scanf("%u", &ch);                     
       
        switch(ch) {               
            case 1: insert_node_at_first(dll, loop_iter); break;
            case 2: delete_first_node(dll); break;
            case 3: insert_node_at_last(dll, loop_iter); break;
            case 4: delete_last_node(dll); break;
            case 5: printf("Enter idx: ");
                    scanf("%u", &ch);
                    insert_node_at_idx(dll, ch, loop_iter);
                    break;
            case 6: printf("Enter idx: ");
                    scanf("%u", &ch);
                    delete_node_at_idx(dll, ch);
                    break;
#if 0
            case 7: search_node(dll); break;
#endif
            case 8: traverse_forward_dll(dll); break;
            case 9: traverse_backward_dll(dll); break;
            case 0: goto exit_func;
            default: printf("Enter proper choice ...\n");
        }
    }

	free(dll);

exit_func:
	return ret;

}
