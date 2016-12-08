
typedef binary_search_tree_node {
    int ival;
    struct bstnode *pparent;
    struct bstnode *pleft;
    struct bstnode *pright;
}bstnode, *pbstnode;

int inorder_tree_walk(bstnode *phead);
int tree_search(bstnode *phead, int ival, bstnode **pptarget);
int tree_minimum(bstnode *phead, int *pminimum);
int tree_maximum(bstnode *phead, int *pmaximum);
int tree_successor(bstnode *phead, bstnode **ptarget);
int tree_insert(bstnode **pphead, int ival);
int tree_delete(bstnode **pphead, int ival);
