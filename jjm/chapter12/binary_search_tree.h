#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct binary_search_tree_node {
    int ival;
    //struct bstnode *pparent;
    //struct bstnode *pleft;
    //struct bstnode *pright;
    struct binary_search_tree_node *pparent;
    struct binary_search_tree_node *pleft;
    struct binary_search_tree_node *pright;
}bstnode, *pbstnode;

int inorder_tree_walk(bstnode *phead);
int tree_search(bstnode *phead, int ival, bstnode **pptarget);
int tree_minimum(bstnode *phead, bstnode **ppminimum);
int tree_maximum(bstnode *phead, bstnode **ppmaximum);
int tree_successor(bstnode *pnode, bstnode **ppsuccessor_on_pnode);
int tree_insert(bstnode **pphead, int ival);
//int tree_delete(bstnode **pphead, int ival);
int tree_delete(bstnode **pphead, bstnode *pdel);
