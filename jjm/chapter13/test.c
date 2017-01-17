#include <stdlib.h>
#include <stdio.h>

#include "red_black_tree.h"

int main(int argc, char *argv[]) {
    printf("this is a test on red_black_tree ^_^\n");

    int iarray[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    rbt_node *proot = NULL;
    for (int i = 0, inum = sizeof(iarray) / sizeof(iarray[0]); i < inum; i++) {
        rb_insert(&proot, iarray[i]);
    }

//    rb_inorder_tree_walk(proot);
    printf("\n");

    exit(0);
}
