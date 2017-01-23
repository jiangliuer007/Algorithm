
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
    assert(prbt_info);
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
    
    char *_color[] = {"black", "red"};

    rb_inorder_tree_walk_proc(proot->pleft, pnil);
    printf("[%d %s]\t", proot->ival, _color[proot->color]);
    rb_inorder_tree_walk_proc(proot->pright, pnil);


    return 0;
}
int rb_inorder_tree_walk(rbt_info *prbt_info) {
    assert(prbt_info);
    
    rb_inorder_tree_walk_proc(prbt_info->proot, prbt_info->pnil);

    return 0;
}

/*
 * please refer to the pseudocode in page 323.
 */
int rb_transplant(rbt_info *prbt_info, rbt_node *pu, rbt_node *pv) {
    assert(prbt_info && pu && pv);
    
    if (pu->pparent == prbt_info->pnil) {
        prbt_info->proot = pv;
    } else if (pu->pparent->pleft == pu) {
        pu->pparent->pleft = pv;
    } else {
        pu->pparent->pright = pv;
    }

    pv->pparent = pu->pparent;

    return 0;
}

/*
 *  please refer to the pseudocode in page 326.
 */
int rb_delete_fixup(rbt_info *prbt_info, rbt_node *px) {
    assert(prbt_info && px);
    
    while ((px != prbt_info->proot) && px->color == __black) {
        if (px == px->pparent->pleft) {
            rbt_node *pw = px->pparent->pright;
            if (pw->color == __red) {
                pw->color = __black;
                px->pparent->color = __red;
                left_rotate(&(prbt_info->proot), px->pparent, prbt_info->pnil);
                pw = px->pparent->pright;
            }

            if ((pw->pleft->color == __black) && (pw->pright->color == __black)) {
                pw->color = __red;
                px = px->pparent;
            } else {
                if (pw->pright->color == __black) {
                    pw->pleft->color = __black;
                    pw->color = __red;
                    right_rotate(&(prbt_info->proot), pw, prbt_info->pnil);
                    pw = px->pparent->pright;
                }

                pw->color = px->pparent->color;
                px->pparent->color = __black;
                pw->pright->color = __black;
                left_rotate(&(prbt_info->proot), px->pparent, prbt_info->pnil);
                px = prbt_info->proot;
            }
        } else {
            rbt_node *pw = px->pparent->pleft;
            if (pw->color == __red) {
                pw->color = __black;
                px->pparent->color = __red;
                right_rotate(&(prbt_info->proot), px->pparent, prbt_info->pnil);
                pw = px->pparent->pleft;
            }

            if ((pw->pleft->color == __black) && (pw->pright->color == __black)) {
                pw->color = __red;
                px = px->pparent;
            } else {
                if (pw->pright->color == __red) {
                    pw->pright->color = __black;
                    pw->color = __red;
                    left_rotate(&(prbt_info->proot), pw, prbt_info->pnil);
                    pw = px->pparent->pleft;
                }
                
                pw->color = px->pparent->color;
                px->pparent->color = __black;
                pw->pleft->color = __black;
                right_rotate(&(prbt_info->proot), px->pparent, prbt_info->pnil);
                px = prbt_info->proot;
            }

        }
    }

    px->color = __black;

    return 0;
}
/*
 * please refer to the pseudocode in page 324.
 */

int rb_minimum(rbt_node *px, rbt_node *pnil, rbt_node **pptarget) {
    assert(px && pnil && pptarget);

    while (px->pleft != pnil) {
        px = px->pleft;
    }
    *pptarget = px;

    return 0;
}

int rb_delete(rbt_info *prbt_info, rbt_node *pz) {
    assert(prbt_info && prbt_info->pnil && pz);
    
    rbt_node *proot = prbt_info->proot;
    rbt_node *pnil  = prbt_info->pnil;

    rbt_node *py = pz;
    rbt_color y_original_color = py->color;
    rbt_node *px = NULL;
    if (pz->pleft == pnil) {
        px = pz->pright;
        rb_transplant(prbt_info, pz, pz->pright);
    } else if (pz->pright == pnil) {
        px = pz->pleft;
        rb_transplant(prbt_info, pz, pz->pleft);
    } else {
        rb_minimum(pz->pright, pnil, &py);
        y_original_color = py->color;

        px = py->pright;
        if (py->pparent == pz) {
            px->pparent = py;
        } else {
            rb_transplant(prbt_info, py, py->pright);
            py->pright          = pz->pright;
            py->pright->pparent = py;
        }

        rb_transplant(prbt_info, pz, py);
        py->pleft = pz->pleft;
        py->pleft->pparent = py;
        py->color = pz->color;
    }
    
    if (y_original_color == __black) {
        rb_delete_fixup(prbt_info, px);
    }
    
    return 0;
}


/*
 * please refer to the pseudocode in page 290.
 */
int rb_search_proc(rbt_node *proot, rbt_node *pnil, int ival, rbt_node **pptarget) {
    assert(proot && pnil && pptarget);
    if (pnil == proot) {        /* the node is a leaf. */
        return 1;
    }

    if (proot->ival == ival) {
        *pptarget = proot;
    } else if (proot->ival < ival) {
        rb_search_proc(proot->pright, pnil, ival, pptarget);
    } else {
        rb_search_proc(proot->pleft, pnil, ival, pptarget);
    }

    return 0;
}
int rb_search(rbt_info *prbt_info, int ival, rbt_node **pptarget) {
    assert(prbt_info && pptarget);
    
    rb_search_proc(prbt_info->proot, prbt_info->pnil, ival, pptarget);

    return 0;
}
