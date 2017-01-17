
#include "red_black_tree.h"

/*
 * please refer to the pseudocode in page 313.
 *
 * the code for left_rotate assumes that px.right != T.nil and that the root's parent is T.nil.
 */
int left_rotate(rbt_node **pproot, rbt_node *px, rbt_node *pnil) {
    assert(pproot && px && px->pright && (px->pright != pnil));

    rbt_node *py = px->pright;

    px->pright = py->pleft;
    if (py->pleft && (py->pleft != pnil)) {
        py->pleft->pparent = px;
    }

    py->pparent = px->pparent;
    if (pnil == px->pparent) {
        *pproot = py;
    } else if (px->pparent->pleft == px) {
        px->pparent->pleft = py;
    } else {
        px->pparent->pright = py;
    }

    px->pparent = py;
    py->pleft = px;

    return 0;
}

/*
 * the code for right_rotate assumes that the px.pparent != NULL and that the root's parent is NULL.
 */
int right_rotate(rbt_node **pproot, rbt_node *px) {
    assert(pproot && px && px->pparent);

    rbt_node *py = px->pparent;
    py->pleft = px->pright;
    if (px->pright) {
        px->pright->pparent = py;
    }

    px->pparent = py->pparent;
    if (NULL == py->pparent) {
        *pproot = px;
    } else if (py->pparent->pleft == py) {
        py->pparent->pleft = px;
    } else {
        py->pparent->pright = px;
    }

    px->pright = py;
    py->pparent = px;

    return 0;
}

/*
 * please refer to the pseudocode in page 316.
 */
int rb_insert_fixup(rbt_node **pproot, rbt_node *pz) {
    assert(pproot && pz);

    while (pz && pz->pparent && (__red == pz->pparent->color)) {
        if (pz->pparent->pparent->pleft == pz->pparent) {
            rbt_node *py = pz->pparent->pparent->pright;
            if (py->color == __red) {
                py->color                   = __black;
                pz->pparent->color          = __black;
                pz->pparent->pparent->color = __red;

                pz = pz->pparent->pparent;
            } else if (pz->pparent->pright == pz) {
                pz = pz->pparent;
                left_rotate(pproot, pz);
            }

            pz->pparent->color = __black;
            pz->pparent->pparent->color = __red;
            right_rotate(pproot, pz->pparent->pparent);
        } else {

            rbt_node *py = pz->pparent->pparent->pleft;
            if (__red == py->color) {
                pz->pparent->color           = __black;
                py->color                   = __black;
                pz->pparent->pparent->color  = __red;

                pz = pz->pparent->pparent;
            } else if (pz->pparent->pleft == pz) {
                pz = pz->pparent;
                right_rotate(pproot, pz);
            }

            pz->pparent->color = __black;
            pz->pparent->pparent->color = __red;

            left_rotate(pproot, pz->pparent->pparent);

        }
    }

    (*pproot)->color = __black;

    return 0;
}

/*
 * please refer to the pseudocode in page 315.
 */
int rb_insert(rbt_node **pproot, int ival) {
    assert(pproot);

    rbt_node *pnew = calloc(1, sizeof(rbt_node));
    if (NULL == pnew) {
        return 1;
    }
    memset(pnew, 0, sizeof(pnew));
    pnew->ival = ival;

    rbt_node *pcurrent = *pproot;
    rbt_node *plast = pcurrent;
    while (pcurrent) {
        plast = pcurrent;

        if (pcurrent->ival > ival) {
            pcurrent = pcurrent->pleft;
        } else {
            pcurrent = pcurrent->pright;
        }
    }

    pnew->pparent = plast;
    if (NULL == plast) {
        *pproot = pnew;
    } else if (plast->ival > ival) {
        plast->pleft = pnew;
    } else {
        plast->pright = pnew;
    }

    pnew->color = __red;

    rb_insert_fixup(pproot, pnew);

    return 0;
}

/*
 *  please refer to the pseudocode in page 288.
 */

int rb_inorder_tree_walk(rbt_node *proot) {
    if (NULL == proot) {
        return 1;
    }

    rb_inorder_tree_walk(proot->pleft);
    printf("%d\t", proot->ival);
    rb_inorder_tree_walk(proot->pright);


    return 0;
}
