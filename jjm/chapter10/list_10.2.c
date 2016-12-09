#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct list_node {
    int ival;
    struct list_node *pnext;
    struct list_node *pprevious;
} lnode, *plnode;

int list_search(lnode *pl, int k, lnode **ppk) {
    assert(pl && (ppk));

    lnode *ptemp = pl;
    for (; ptemp; ptemp = ptemp->pnext) {
        if (ptemp->ival == k) {
            break;
        }
    }
    *ppk = ptemp;

    return 0;
}

int list_insert(lnode **ppl, int k) {
    assert(ppl);

    lnode *ptemp = calloc(1, sizeof(*ptemp));
    ptemp->ival = k;
    ptemp->pnext = *ppl;
    ptemp->pprevious = NULL;

    if (*ppl) {
        (*ppl)->pprevious = ptemp;
    }

    *ppl = ptemp;

    return 0;
}

int list_delete(lnode **ppl, int k) {
    assert(ppl);

    lnode *pdel = NULL;
    list_search(*ppl, k, &pdel);
    if (pdel) {     // delete the node from the list specified by pl.

        // pseudocode 
        //      pdel->pprevious->pnext = pdel->pnext;
        //      pdel->pnext->pprevious = pdel->pprevious;
        // pseudocode 00 01 10 11

        if ((NULL == pdel->pprevious) && (NULL == pdel->pnext)) {
            // there is only one node in the list
            *ppl = NULL;
        }
        if (NULL == pdel->pnext) {
            // the node to be deleted is at the end of the list.
            pdel->pprevious->pnext = pdel->pnext;
        }
        if (NULL == pdel->pprevious) {
            // the node to be deleted is at the head of the list.
            pdel->pnext->pprevious = pdel->pprevious;
            *ppl = pdel->pnext;
        }
        if ((pdel->pprevious) && (pdel->pnext)) {
            // the node to be deleted is neither at the head nor at the end of the list.
            pdel->pprevious->pnext = pdel->pnext;
            pdel->pnext->pprevious = pdel->pprevious;
        }

        free(pdel);
    }

    return 0;
}

int list_print_values(lnode *pl) {
    assert(pl);

    for (lnode *ptemp = pl; ptemp; ptemp = ptemp->pnext) {
        printf("%d\t", ptemp->ival);
    }
    printf("\n");

    return 0;
}

int main(int argc, char *argv[]) { 
    int iarray[] = {25, 9, 16, 4, 1};
    int inum_items = sizeof(iarray) / sizeof(iarray[0]);

    lnode *pl = NULL;

    //for (int i = 0 + 1; i < inum_items; i++) {
    for (int i = 0; i < inum_items; i++) {
        list_insert(&pl, iarray[i]);
    }
    //list_print_values(pl);

    int idel;
    
    /*
    idel = 4;
    list_delete(&pl, idel);
    
    idel = 9;
    list_delete(&pl, idel);
    
    idel = 16;
    list_delete(&pl, idel);
    */

    
    idel = 1;
    list_delete(&pl, idel);
    

    /*
    idel = 25;
    list_delete(&pl, idel);
    */

    list_print_values(pl);

    exit(0);
}
