
#include "binary_search_tree.h"

/*
 *
 * note: refer to the pseudocode in page 288.
 * */
int inorder_tree_walk(bstnode *phead) {
    assert(phead);

    if (phead->pleft) {
        inorder_tree_walk(phead->pleft);
    }

    printf("%d\t", phead->ival);

    if (phead->pright) {
        inorder_tree_walk(phead->pright);
    }

    return 0;
}

/*
 *
 * note: refer to the pseudocode in page 290.
 * */
int tree_search(bstnode *phead, int ival, bstnode **pptarget) {
    assert(phead && pptarget);

    *pptarget = NULL;
    if (ival == phead->ival) {
        *pptarget = phead;
    } else if (phead->ival > ival) {
        if (phead->pleft) {
            tree_search(phead->pleft, ival, pptarget);
        }
    } else if (phead->ival < ival) {
        if (phead->pright) {
            tree_search(phead->pright, ival, pptarget);
        }
    }

    return 0;
}

/*
 *
 * note: refer to the pseudocode in page 291.
 * */
int tree_minimum(bstnode *phead, bstnode **ppminimum) {
    assert(phead && ppminimum);

    if (NULL == phead->pleft) {
        *ppminimum = phead;
    } else {
        tree_minimum(phead->pleft, ppminimum);
    }

    return 0;
}

/*
 *
 * note: refer to the pseudocode in page 291.
 * */
int tree_maximum(bstnode *phead, bstnode **ppmaximum) {
    assert(phead && ppmaximum);

    if (NULL == phead->pright) {
        *ppmaximum = phead;
    } else {
        tree_maximum(phead->pright, ppmaximum);
    }

}

/*
 *
 * note: refer to the pseudocode in page 292.
 * */
int tree_successor(bstnode *pnode, bstnode **ppsuccessor_on_pnode) {
    assert(pnode && ppsuccessor_on_pnode);

    if (pnode->pright) {
        tree_minimum(pnode->pright, ppsuccessor_on_pnode);
        return 0;
    } else {
        //
        bstnode *ptemp = pnode;

        while (ptemp && ptemp->pparent) {
            if (ptemp->pparent->pleft == ptemp) {
                /* ptemp->pparent is the successor of pnode. */
                break;
            } else {
                ptemp = ptemp->pparent;
            }
        }

        *ppsuccessor_on_pnode = ptemp->pparent;
    }

    return 0;
}

/*
 *
 * note: refer to the pseudocode in page 294.
 * */
int tree_insert(bstnode **pphead, int ival) {
    assert(pphead);

    bstnode *pnew = calloc(1, sizeof(*pnew));
    memset(pnew, 0, sizeof(*pnew));
    pnew->ival = ival;

    bstnode *pcurrent = *pphead;
    bstnode *plast = NULL;
    while (pcurrent) {
        plast = pcurrent;
        if (pcurrent->ival > ival) {
            pcurrent = pcurrent->pleft;
        } else {
            pcurrent = pcurrent->pright;
        }

    }

    if (NULL == plast) {
        /* the tree is empty. */
        *pphead = pnew;
    } else {
        pnew->pparent = plast;

        if (plast->ival > ival) {
            plast->pleft = pnew;
        } else {
            plast->pright = pnew;
        }
    }

    return 0;
}

/*
 *
 * note: refer to the pseudocode in page 298.
 * */
int tree_delete(bstnode **pphead, int ival) {
    return 0;
}
