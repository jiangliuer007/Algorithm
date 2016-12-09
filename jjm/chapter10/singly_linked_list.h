#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct singly_linked_list_node {
    int ival;
    struct singly_linked_list_node *pnext;
} slnode, *pslnode;

int sl_list_insert(slnode **pphead, int ival);
int sl_list_delete(slnode **pphead, int ival); 
int sl_list_release(slnode *phead);
int sl_list_print(slnode *phead);
int sl_list_reverse(slnode **pphead);
