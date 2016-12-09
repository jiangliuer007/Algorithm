#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct Node {
    float fval;
    struct Node *pnext;
} lNode, *PNode;

// ---------------------------------------------------------------------------
int list_print_values(PNode *parray, int num_array) {
    for (int i = 0; i < num_array; i++) {
        if (parray[i]) {
            lNode *pcurrent = parray[i];
            while (pcurrent) {
                printf("%f\n", pcurrent->fval);

                pcurrent = pcurrent->pnext;
            }
        }
    }
    printf("\n");

    return 0;
}
// ---------------------------------------------------------------------------
int copy_value(PNode *parray, int num_array, float *ptarget) {
    for (int i = 0; i < num_array; i++) {
        if (parray[i]) {
            lNode *pcurrent = parray[i];
            while (pcurrent) {
                //                printf("%f\n", pcurrent->fval);

                *ptarget = pcurrent->fval;

                ptarget++;
                pcurrent = pcurrent->pnext;
            }
        }
    }

    return 0;
}
// ---------------------------------------------------------------------------
int add_and_resort_list(lNode **pphead, lNode *pNewNode) {
    lNode *pcurrent = *pphead;
    if (pcurrent->fval > pNewNode->fval) {   /* currently, there is only one element in the list. */
        pNewNode->pnext = pcurrent;
        *pphead = pNewNode;

        return 0;
    }

    while (pcurrent) {

        if ((pcurrent->fval < pNewNode->fval) && (pcurrent->pnext->fval > pNewNode->fval)) {
            lNode *ptemp = pcurrent->pnext;
            pcurrent->pnext = pNewNode;  
            pNewNode->pnext = ptemp;
            break;
        }

        pcurrent = pcurrent->pnext;
    }

}

int sort_list(lNode **pphead) {
    lNode *pcurrent = *pphead;
    if (!pcurrent) {
        return 0;
    }

    lNode *pprevious = pcurrent;
    pcurrent = pcurrent->pnext;
    while (pcurrent) {
        if (pcurrent->fval < pprevious->fval) {
            lNode *pnext_temp = pcurrent->pnext;

            add_and_resort_list(pphead, pcurrent);

            pprevious->pnext = pnext_temp;
            pcurrent = pnext_temp;

            continue;
        }

        pprevious = pcurrent;
        pcurrent = pcurrent->pnext;
    }

    return 0;
}
// ---------------------------------------------------------------------------
int add_to_list(lNode **pphead, float fval) {
    lNode *pcurrent = *pphead;
    if (!pcurrent) {
        lNode *ptemp = calloc(1, sizeof(lNode));
        ptemp->fval = fval;
        ptemp->pnext = NULL;

        *pphead = ptemp;

        return 0;
    }

    while (pcurrent) {
        if (pcurrent->fval == fval) {
            break;
        }
        if (pcurrent->pnext == NULL) {
            break;
        }

        pcurrent = pcurrent->pnext;
    }
    if (pcurrent->fval != fval) {
        lNode *ptemp = calloc(1, sizeof(lNode));
        ptemp->fval = fval;
        ptemp->pnext = NULL;

        pcurrent->pnext = ptemp;
    }

    return 0;
}
// ---------------------------------------------------------------------------
int bucket_sort(float *parray, int num_elements) {
    PNode *pbucket = calloc(num_elements, sizeof(PNode));
    memset(pbucket, 0, sizeof(PNode) * num_elements);

    for (int i = 0; i < num_elements; i++) {
        int iindex = num_elements * parray[i];
        add_to_list(&(pbucket[iindex]), parray[i]);
    }

    // del
    //list_print_values(pbucket, num_elements);
    //return 0;
    // del


    for (int i = 0; i < num_elements; i++) {
        sort_list(&(pbucket[i]));
    }

    // del
    //printf("after sort_list():\n");
    //list_print_values(pbucket, num_elements);
    //return 0;
    // del



    // copy the list to the original array.
    for (int i = 0; i < num_elements; i++) {
        copy_value(pbucket, num_elements, parray);
    }

    free(pbucket);

    return 0;
}

int main(int argc, char *argv[]) {
    float farray[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int num_elements = sizeof(farray) / sizeof(farray[0]);

    bucket_sort(farray, num_elements);

    // print the sorted array.
    for (int i = 0; i < num_elements; i++) {
        printf("%f\t", farray[i]);
    }
    printf("\n");

    exit(0);
}
