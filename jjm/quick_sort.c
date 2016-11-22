#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//#define version_0_0

int swap(int *pa, int *pb) {
    assert(pa && pb);

    int itemp   = *pa;
    *pa         = *pb;
    *pb         = itemp;

    return 0;
}

#ifdef version_0_0

//int fun(int *parray, int istart, int iend, int *presult) {
int fun(int *parray, int istart, int iend) {
    //assert(parray && presult);
    assert(parray);

    int k = istart;
    if (iend - istart >= 1) {
        for (int i = istart; i < iend; i++) {
            if (parray[i] < parray[iend]) {
                swap(&(parray[i]), &(parray[k]));
                k++;
            }
        }

        swap(&(parray[k]), &(parray[iend]));

        //        *presult = k;

        fun(parray, istart, k - 1);
        fun(parray, k + 1, iend);
    }

    return 0;
}


//int quick_sort(int *parray, int num_array) {
int quick_sort(int *parray, int istart, int iend) {
    //printf("quick_sort() version 0.0 is called ^_^\n");
    assert(parray);  

    fun(parray, istart, iend);

    return 0;
}
#else

/*
 * refer to pseudocode in page 171.
 */
int partition(int *parray, int istart, int iend, int *presult) {
    assert(parray && presult);

    int k = istart;
    for (int i = istart; i < iend; i++) {
        if (parray[i] < parray[iend]) {
            swap(&(parray[i]), &(parray[k]));
            k++;
        }
    }
    if (parray[k] != parray[iend]) {
        swap(&(parray[k]), &(parray[iend]));
    }

    *presult = k;

    return 0;
}

/*
 * refer to pseudocode in page 171.
 */
int quick_sort(int *parray, int istart, int iend) {
    //printf("quick_sort() version 0.1 is called ^_^\n");
    assert(parray);  

    if (istart < iend) {
        int ik = 0;
        partition(parray, istart, iend, &ik);
        quick_sort(parray, istart, ik - 1);
        quick_sort(parray, ik + 1, iend);
    }

    return 0;
}

#endif

int main(int argc, char *argv[]) {
    int iarray[] = {1, 9, 4, 7, 5, 19, 3};
    int num_items = sizeof(iarray) / sizeof(iarray[0]);
    quick_sort(iarray, 0, num_items - 1);

    // print the sorted array.
    for (int i = 0; i < num_items; i++) {
        printf("%d\t", iarray[i]);
    }
    printf("\n");

    exit(0);
}
