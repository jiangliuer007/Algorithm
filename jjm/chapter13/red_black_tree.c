
#include "red_black_tree.h"

int rb_init(rbt_info *prbt_info) {
    assert(prbt_info);

    memset(prbt_info, 0, sizeof(*prbt_info));

    prbt_info->pnil = calloc(1, sizeof(rbt_node));
    prbt_info->pnil->color = __black;

    return 0;
}

/*
 * please refer to the pseudocode in page 313.
 *
 * the code for left_rotate assumes that px.right != T.nil and that the root's parent is T.nil.
 */
int left_rotate(rbt_node **pproot, rbt_node *px, rbt_node *pnil) {
    assert(pproot && px && pnil && px->pright && (px->pright != pnil));

    rbt_node *py = px->pright;

    px->pright = py->pleft;
    if (py->pleft && (py->pleft != pnil)) {
        py->pleft->pparent = px;
    }

    py->pparent = px->pparent;
    assert(px->pparent);
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
 *  please refer to the exercise 13.2-1.
 *
 * the code for right_rotate assumes that the py.pleft != T.nil and that the root's parent is T.nil.
 */
int right_rotate(rbt_node **pproot, rbt_node *py, rbt_node *pnil) {
    assert(pproot && py && pnil && py->pleft && (py->pleft != pnil));

    rbt_node *px = py->pleft;
    py->pleft = px->pright;
    if (px->pright && px->pright != pnil) {
        px->pright->pparent = py;
    }

    px->pparent = py->pparent;
    assert(py->pparent);
    if (py->pparent == pnil) {
        *pproot = px;
    } else if (py->pparent->pleft == py) {
        py->pparent->pleft = px;
    } else {
        py->pparent->pright = px;
    }

    py->pparent = px;
    px->pright = py;

    return 0;
}

/*
 * please refer to the pseudocode in page 316.
 */
int rb_insert_fixup(rbt_node **pproot, rbt_node *pz, rbt_node *pnil) {
    assert(pproot && pz);

    while (pz && pz->pparent && (__red == pz->pparent->color) && pz->pparent->pparent && pz->pparent->pparent != pnil) {
        if (pz->pparent->pparent->pleft == pz->pparent) {
            rbt_node *py = pz->pparent->pparent->pright;
            if (py->color == __red) {
                py->color                   = __black;
                pz->pparent->color          = __black;
                pz->pparent->pparent->color = __red;

                pz = pz->pparent->pparent;
            } else {
                if (pz->pparent->pright == pz) {
                    pz = pz->pparent;
                    left_rotate(pproot, pz, pnil);
                }

                pz->pparent->color = __black;
                pz->pparent->pparent->color = __red;
                right_rotate(pproot, pz->pparent->pparent, pnil);
            }
        } else {

            rbt_node *py = pz->pparent->pparent->pleft;
            if (__red == py->color) {
                pz->pparent->color           = __black;
                py->color                   = __black;
                pz->pparent->pparent->color  = __red;

                pz = pz->pparent->pparent;
            } else {
                if (pz->pparent->pleft == pz) {
                    pz = pz->pparent;
                    right_rotate(pproot, pz, pnil);
                }

                pz->pparent->color = __black;
                pz->pparent->pparent->color = __red;

                left_rotate(pproot, pz->pparent->pparent, pnil);
            }
        }
    }

    (*pproot)->color = __black;

    return 0;
}

/*
 * please refer to the pseudocode in page 315.
 */
int rb_insert(rbt_info *prbt_info, int ival) {
    assert(prbt_info && pnil);
    rbt_node **pproot = &(prbt_info->proot);
    rbt_node *pnil = prbt_info->pnil;

    rbt_node *pnew = calloc(1, sizeof(rbt_node));
    if (NULL == pnew) {
        return 1;
    }
    memset(pnew, 0, sizeof(pnew));
    pnew->ival = ival;

    rbt_node *plast = pnil;
    rbt_node *pcurrent = *pproot;
    while (pcurrent && (pcurrent != pnil)) {
        plast = pcurrent;

        if (pcurrent->ival > ival) {
            pcurrent = pcurrent->pleft;
        } else {
            pcurrent = pcurrent->pright;
        }
    }

    pnew->pparent = plast;
    assert(plast);
    if (pnil == plast) {
        *pproot = pnew;
    } else if (plast->ival > ival) {
        plast->pleft = pnew;
    } else {
        plast->pright = pnew;
    }

    pnew->pleft     = pnil;
    pnew->pright    = pnil;
    pnew->color     = __red;

    rb_insert_fixup(pproot, pnew, pnil);

    return 0;
}

/*
 *  please refer to the pseudocode in page 288.
 */
int rb_inorder_tree_walk_proc(rbt_node *proot, rbt_node *pnil) {
    assert(proot && pnil);

    if (pnil == proot) {
        return 1;
    }

    rb_inorder_tree_walk(proot->pleft, pnil);
    printf("%d\t", proot->ival);
    rb_inorder_tree_walk(proot->pright, pnil);


    return 0;
}
int rb_inorder_tree_walk(rbt_info *prbt_info) {
    assert(prbt_info);
    
    rb_inorder_tree_walk_proc(prbt_info->proot, prbt_info->pnil);

    return 0;
}
