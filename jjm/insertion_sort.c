#include <stdlib.h>
#include <stdio.h>

/*
 * version 0.0
int insertion_sort(int *pArray, int num) {
    for (int i = 0 + 1; i < num; i++) { // igonore the first element.
        int itemp = pArray[i];

        int j = i;
        while (j >= 0) {
            if ((pArray[j] < pArray[i]) && (pArray[j + 1 ] > pArray[i])) {
                for (int k = i; k > j + 1; k--) {
                    pArray[k] = pArray[k - 1];
                }
                pArray[j + 1] = itemp;

                break;
            }

            j--;
        }

    }

    return 0;
}
*/

/*
 * version 0.1
 */
int insertion_sort(int *pArray, int num) {
    for (int i = 0 + 1; i < num; i++) { // igonore the first element.
        int itemp = pArray[i];

        int j = i - 1;
        for (; (j >= 0) && (pArray[j] > itemp); j--) {
            pArray[j + 1] = pArray[j];
        }
        pArray[j + 1] = itemp;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int iArray[] = {1, 3, 7, 5, 2, 4, 11, 9};
    size_t numItem = sizeof(iArray) / sizeof(iArray[0]);

    insertion_sort(iArray, numItem);
    
    // print the sorted array.
    for (int i = 0; i < numItem; i++) {
        printf("%d\t", iArray[i]);
    }
    printf("\n");
    
    exit(0);
}
