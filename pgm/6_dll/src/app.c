#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<dlist.h>

int main(void)
{
	int ret = 0;
	int ch;
	DLL_T *dll;
	long loop_iter = 0;

	dll = init_dll();
	if(dll == NULL) {
		printf("ENOMEM\n");
		ret = -1;
		goto exit_func;
	}

    for(;;) {    
        ++loop_iter;    
		printf("1:INF\t\t2:INL\t\t3:INIDX\t\t");
		printf("4:DNF\t\t5:DNL\t\t6:DNIDX\t\t");
		printf("7:SRCH\t\t8:PRNF\t\t9:PRNB\t\t");
		printf("10:PREFL\t\t0:EXT\n");
		printf("CHOICE: ");
        scanf("%u", &ch);                     
       
        switch(ch) {               
            case 1: insert_node_at_first(dll, (void *)loop_iter); break;
            case 2: insert_node_at_last(dll, (void *)loop_iter); break;
            case 3: printf("Enter idx: ");
                    scanf("%u", &ch);
                    insert_node_at_idx(dll, ch, (void *)loop_iter);
                    break;
            case 4: delete_first_node(dll); break;
            case 5: delete_last_node(dll); break;
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
