#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int swap(int *pa, int *pb) {
    assert(pa && pb);

    int itemp   = *pa;
    *pa         = *pb;
    *pb         = itemp;

    return 0;
}

int partition_ex(int *parray, int istart, int iend, int *presult, int *ptarget) {
    assert(parray && presult && ptarget);

    int k = istart;
    for (int i = istart; i < iend; i++) {
        if (parray[i] < parray[iend]) {
            swap(&(parray[i]), &(parray[k]));
            swap(&(ptarget[i]), &(ptarget[k]));
            k++;
        }
    }

    if (parray[k] != parray[iend]) {
        swap(&(parray[k]), &(parray[iend]));
        swap(&(ptarget[k]), &(ptarget[iend]));
    }

    *presult = k;

    return 0;
}

int quick_sort_ex(int *parray, int istart, int iend, int *ptarget) {
    assert(parray && ptarget);  

    if (istart < iend) {
        int ik = 0;
        partition_ex(parray, istart, iend, &ik, ptarget);
        quick_sort_ex(parray, istart, ik - 1, ptarget);
        quick_sort_ex(parray, ik + 1, iend, ptarget);
    }

    return 0;
}

/*
 * please refer to the pseudocode in page 198.
 */
int radix_sort(int *parray, int num_array, int num_digit) {

    //int *ptemp = calloc(num_digit, sizeof(int));
    int *ptemp = calloc(num_array, sizeof(int));
    for (int i = 0; i < num_digit; i++) {
        for (int j = 0; j < num_array; j++) {
            //ptemp[j] = (parray[j] >> (i * 8)) & 0x0FF;
            ptemp[j] = ((int)(parray[j] / pow(10, i))) % 10;
            printf("[%d:%d]\t", parray[j], ptemp[j]);
        }
        printf("\n");

        quick_sort_ex(ptemp, 0, num_array - 1, parray);
    }


    free(ptemp);

    return 0;
}

int main(int argc, char *argv[]) {
    int iarray[] = {329, 457, 657, 839, 436, 720, 355};
    int num_item = sizeof(iarray) / sizeof(iarray[0]);
    int num_digit = 3;

    radix_sort(iarray, num_item, 3);

    // print the sorted array.
    for (int i = 0; i < num_item; i++) {
        printf("%d\t", iarray[i]);
    }
    printf("\n");


    exit(0);
}
