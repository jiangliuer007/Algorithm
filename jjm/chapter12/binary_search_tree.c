
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
    *ppsuccessor_on_pnode = NULL;

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
int transplant(bstnode **pphead, bstnode *pu, bstnode *pv) {
    assert(pphead && pu);

    if (NULL == pu->pparent) {
        *pphead = pv;
    } else if (pu == pu->pparent->pleft) {
        pu->pparent->pleft = pv;
    } else {
        pu->pparent->pright = pv;
    }

    if (pv) {
        pv->pparent = pu->pparent;
    }

    return 0;
}
int tree_delete(bstnode **pphead, bstnode *pdel) {
    assert(pphead && pdel);

    if (NULL == pdel->pleft) {
        transplant(pphead, pdel, pdel->pright);
    } else if (NULL == pdel->pright) {
        transplant(pphead, pdel, pdel->pleft);
    } else {
        bstnode *py = NULL;             // py is the successor of pdel.
        tree_minimum(pdel->pright, &py);
        if (py != pdel->pright) {
            transplant(pphead, py, py->pright);

            py->pright = pdel->pright;
            pdel->pright->pparent = py;
        }
        transplant(pphead, pdel, py);
        py->pleft = pdel->pleft;
        pdel->pleft->pparent = py;
    }
    free(pdel);

    return 0;
}

#if 0
int tree_delete(bstnode **pphead, int ival) {
    assert(pphead);

    bstnode *pdel = NULL;
    tree_search(*pphead, ival, &pdel);
    if (!pdel) {
        return 0;
    }

    if ((NULL == pdel->pleft) && (NULL == pdel->pright)) {      /* the node to be deleted has no children. */
        if (NULL == pdel->pparent) {
            *pphead = NULL;
        } else if (pdel->pparent->pleft == pdel) {
            pdel->pparent->pleft = NULL;
        } else {
            pdel->pparent->pright = NULL;
        }
    } 

    if ((NULL ==pdel->pleft) && (pdel->pright)) {               /* the node to be deleted only has right child. */
        if (NULL == pdel->pparent) {
            pdel->pright->pparent = NULL;
            *pphead = pdel->pright;
        } else if (pdel->pparent->pleft == pdel) {
            pdel->pparent->pleft = pdel->pright;
            pdel->pright->pparent = pdel->pparent;
        } else {
            pdel->pparent->pright = pdel->pright;
            pdel->pright->pparent = pdel->pparent;
        }
    }

    if ((pdel->pleft) && (NULL == pdel->pright)) {              /* the node to be deleted only has left child. */
        if (NULL == pdel->pparent) {
            pdel->pleft->pparent = NULL;
            *pphead = pdel->pleft;
        } else if (pdel->pparent->pleft == pdel) {
            pdel->pparent->pleft = pdel->pleft;
            pdel->pleft->pparent = pdel->pparent;
        } else {
            pdel->pparent->pright = pdel->pleft;
            pdel->pleft->pparent = pdel->pparent;
        }
    }

    if ((pdel->pleft) && (pdel->pright)) {                      /* the node to be deleted has left child and right child. */
        bstnode *psuccessor_on_pdel;
        tree_successor(pdel, &psuccessor_on_pdel);
        if (psuccessor_on_pdel->pparent->pright == psuccessor_on_pdel) {
            psuccessor_on_pdel->pparent->pright = psuccessor_on_pdel->pright;
            if (psuccessor_on_pdel->pright) {
                psuccessor_on_pdel->pright->pparent = psuccessor_on_pdel->pparent;
            }
        } else {
            psuccessor_on_pdel->pparent->pleft = psuccessor_on_pdel->pright;
            if (psuccessor_on_pdel->pright) {
                psuccessor_on_pdel->pright->pparent = psuccessor_on_pdel->pparent;
            }
        }
        psuccessor_on_pdel->pleft = pdel->pleft;
        if (pdel->pleft) {
            pdel->pleft->pparent = psuccessor_on_pdel;
        }

        psuccessor_on_pdel->pright = pdel->pright;
        if (pdel->pright) {
            pdel->pright->pparent = psuccessor_on_pdel;
        }

        psuccessor_on_pdel->pparent = pdel->pparent;
        if (NULL == pdel->pparent) {
            psuccessor_on_pdel->pparent = NULL;
            *pphead = psuccessor_on_pdel;
        } else if (pdel->pparent->pleft == pdel) {
            pdel->pparent->pleft = psuccessor_on_pdel;
        } else {
            pdel->pparent->pright = psuccessor_on_pdel;
        }
    }
    free(pdel);

    return 0;
}
#endif
