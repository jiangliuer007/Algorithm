#include <stdlib.h>
#include <stdio.h>
#include "binary_search_tree.h"

int main(int argc, char *argv[]) {
    bstnode *phead = NULL;
    int iarray[] = {15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};  // refer to page 290
    size_t len_iarray = sizeof(iarray) / sizeof(iarray[0]);

    // 
    for (size_t i = 0; i < len_iarray; i++) {
        tree_insert(&phead, iarray[i]);
    }

    //
    inorder_tree_walk(phead);
    printf("\n");

    //
    bstnode *pfound = NULL;
    tree_search(phead, 3, &pfound);
    if (pfound) {
        printf("%d\n", pfound->ival);
    }

    tree_search(phead, 19, &pfound);
    if (pfound) {
        printf("%d\n", pfound->ival);
    } else {
        printf("the node with value:19 is not found\n");
    }

    //
    bstnode *pmaximum = 0;
    tree_maximum(phead, &pmaximum);

    bstnode *pminimum = 0;
    tree_minimum(phead, &pminimum);
    printf("maximum = %d, minimum = %d\n", pmaximum->ival, pminimum->ival);

    //
    bstnode *psuccessor = NULL;
    bstnode *ptemp = NULL;
    int ival;

    ival = 13;
    tree_search(phead, ival, &ptemp);
    tree_successor(ptemp, &psuccessor);
    if (psuccessor) {
        printf("the successor of %d is %d\n", ival, psuccessor->ival);
    } else {
        printf("the successor of %d could not be found.\n", ival);
    }

    ival = 15;
    tree_search(phead, ival, &ptemp);
    tree_successor(ptemp, &psuccessor);
    if (psuccessor) {
        printf("the successor of %d is %d\n", ival, psuccessor->ival);
    } else {
        printf("the successor of %d could not be found.\n", ival);
    }

    ival = 20;
    tree_search(phead, ival, &ptemp);
    tree_successor(ptemp, &psuccessor);
    if (psuccessor) {
        printf("the successor of %d is %d\n", ival, psuccessor->ival);
    } else {
        printf("the successor of %d could not be found.\n", ival);
    }

    bstnode *pdel = NULL;

    // the node with no children.
    //ival = 2;
    //ival = 4;
    //ival = 9;
    //ival = 17;
    //ival = 20;

    // the node with only one child.
    //ival = 13;
    //ival = 7;
    
    // the node with both children.
    //ival = 3;
    //ival = 6;
    //ival = 15;
    ival = 18;
    tree_search(phead, ival, &pdel);
    if (pdel) {
        tree_delete(&phead, pdel);
        inorder_tree_walk(phead);
        printf("\n");
    }

    exit(0);
}
