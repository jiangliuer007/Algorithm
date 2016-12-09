#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int swap(int *pa, int *pb) {
    assert(pa && pb);

    int temp    = *pa;
    *pa         = *pb;
    *pb         = temp;

    return 0;
}

/*
 * refer to pseudocode in page 154.
 */
int max_heapify(int len_heap, int *p_heap, int i) {
    int ileft   = 2 * i + 1;
    int iright  = 2 * i + 2;
    //int iparent = i / 2 - 1;

    // find the maximum between p_heap[i], p_heap[ileft], p_heap[iright].
    int ilargest = -1;
    if ((ileft < len_heap) && (p_heap[ileft] > p_heap[i])) {
        ilargest = ileft;
    } else {
        ilargest = i;
    }
    if ((iright < len_heap) && (p_heap[iright] > p_heap[ilargest])) {
        ilargest = iright;
    }
    // find the maximum between p_heap[i], p_heap[ileft], p_heap[iright] end.

    if (ilargest != i) {
        swap(&(p_heap[i]), &(p_heap[ilargest])); 
        max_heapify(len_heap, p_heap, ilargest);
    }

    return 0;
}

/*
 *  refer to pseudocode in page 157.
 */
int build_max_heap(int *p_heap, int len_heap) {
    for (int i = len_heap / 2 - 1; i >= 0; i--) {
        max_heapify(len_heap, p_heap, i);
    }

    return 0;
}

/*
 * refer to pseudocode in page 160.
 */
int heap_sort(int *p_heap, int len_heap) {
    build_max_heap(p_heap, len_heap);
    for (int i = len_heap - 1; i >= 1; i--) {
        swap(&(p_heap[0]), &(p_heap[i]));

        max_heapify(i, p_heap, 0);
    }
}

int main(int argc, char *argv[]) {
    int iarray[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int inum_item = sizeof(iarray) / sizeof(iarray[0]);

    heap_sort(iarray, inum_item);

    // print the sorted items.
    for (int i = 0; i < inum_item; i++) {
        printf("%d\t", iarray[i]);
    }
    printf("\n");

    exit(0);
}
