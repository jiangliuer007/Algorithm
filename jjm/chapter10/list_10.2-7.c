#include <stdlib.h>
#include <stdio.h>
#include "singly_linked_list.h"

int main(int argc, char *argv[]) {
    int iarray[] = {1, 4, 9, 5, 3};
    size_t len_iarray = sizeof(iarray) / sizeof(iarray[0]);
    
    slnode *phead = NULL;
    for (int i = 0; i < len_iarray; i++) {
        sl_list_insert(&phead, iarray[i]);
    }
    
    //sl_list_delete(&phead, 9);
    //sl_list_delete(&phead, 3);
    //sl_list_delete(&phead, 1);

    sl_list_print(phead);

    sl_list_reverse(&phead);
    sl_list_print(phead);
    

    exit(0);
}
