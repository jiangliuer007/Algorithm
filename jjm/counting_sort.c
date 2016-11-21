#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * please refer to the pseudocode in page 195.
 *
 * note: parray and presult should not point to the same memory, or the funciton work unexpectedly.
 */
int counting_sort(int *parray, int len_array, int imax, int *presult) {
    
    int *ptemp = calloc((imax + 1), sizeof(int));
    memset(ptemp, 0, sizeof(int) * (imax + 1));

    for (int i = 0; i < len_array; i++) {
        ptemp[parray[i]] = ptemp[parray[i]] + 1;
    }

    for (int i = 1; i <= imax; i++) {
        ptemp[i] = ptemp[i] + ptemp[i - 1];
    }

    for (int i = len_array - 1; i >= 0; i--) {
        presult[ptemp[parray[i]] - 1] = parray[i];
        ptemp[parray[i]] = ptemp[parray[i]] - 1;
    }

    free(ptemp);
    

    return 0;
}

int main(int argc, char *argv[]) {
    int imax = 5;
    int iarray[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int inum_items = sizeof(iarray) / sizeof(iarray[0]);

    int iresult[1024] = {0};
    counting_sort(iarray, inum_items, imax, iresult);

    for (int i = 0; i < inum_items; i++) {
        printf("%d\t", iresult[i]);
    }
    printf("\n");

    exit(0);
}
