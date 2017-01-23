#include <stdlib.h>
#include <stdio.h>

#include "red_black_tree.h"

int main(int argc, char *argv[]) {
    printf("this is a test on red_black_tree ^_^\n");

    //int iarray[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
    //int iarray[] = {1, 3, 5, 7, 9, 11, 13};
    //int iarray[] = {1, 3, 5};
    //int iarray[] = {1, 3, 5, 7};
    //int iarray[] = {1, 3, 5, 7, 9};
    //int iarray[] = {1, 3, 5, 7, 9, 11};
    //int iarray[] = {1, 3, 5, 7, 9, 11, 13};
    //int iarray[] = {11, 9, 7, 5, 3, 1};

    int iarray[1024] = {0};
    size_t num = 
        //1;
        //2;
        3;
        //4;
        //5;
        //6;
        //7;
        //8;
        //9;
        //10;
        //11;
        //12;
        //13;
        //14;
        //15;
    for (size_t i = 0; i < num; i++) {
        iarray[i] = 29 - i * 2;
    }

    rbt_info rbi;
    rb_init(&rbi);

    //for (int i = 0, inum = sizeof(iarray) / sizeof(iarray[0]); i < inum; i++) {
    for (int i = 0; i < num; i++) {
        rb_insert(&rbi, iarray[i]);
    }

    /*
    rb_inorder_tree_walk(&rbi);
    printf("\n");
    exit(0);
    */

    int idel = 27;
    rbt_node *pdel = NULL;
    rb_search(&rbi, idel, &pdel);
    if (pdel) {
        rb_delete(&rbi, pdel);
        rb_inorder_tree_walk(&rbi);
        printf("\n");
    }

    exit(0);
}
