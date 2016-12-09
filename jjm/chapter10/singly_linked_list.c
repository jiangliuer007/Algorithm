#include "singly_linked_list.h"

int sl_list_insert(slnode **pphead, int ival) {
    assert(pphead);

    slnode *pnew = calloc(1, sizeof(pnew));
    pnew->ival = ival;
    pnew->pnext = *pphead;
    
    *pphead = pnew;

    return 0;
}

int sl_list_delete(slnode **pphead, int ival) {
    assert(pphead);

    slnode *pdel = NULL, *pprevious = NULL;
    for (slnode *pcurrent = *pphead; pcurrent; pcurrent = pcurrent->pnext) {
        if (ival == pcurrent->ival) {
            pdel = pcurrent;
            break;
        }

        pprevious = pcurrent;
    }

    if (NULL == pprevious) {
        *pphead = pdel->pnext;
    } else {
        pprevious->pnext = pdel->pnext;
    }
    free(pdel);

    return 0;
}

int sl_list_release(slnode *phead) {
    return 0;
}

int sl_list_print(slnode *phead) {
    for (slnode *pcurrent = phead; pcurrent; pcurrent = pcurrent->pnext) {
        printf("%d\t", pcurrent->ival);
    }
    printf("\n");

    return 0;
}

int sl_list_reverse(slnode **pphead) {
    assert(pphead);

    if (NULL == (*pphead)) {
        return 0;
    }
    slnode *pcurrent = *pphead;
    slnode *pprevious = NULL;
    while (pcurrent) {
        slnode *ptemp_0 = pcurrent->pnext;

        pcurrent->pnext = pprevious;

        // ----
        pprevious       = pcurrent;
        pcurrent        = ptemp_0;
    }
    *pphead = pprevious;

    return 0;
}


