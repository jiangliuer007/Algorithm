#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

/*
 * please refer to the pseudocode in page 34.
 */

int merge_array(int *pArrayA, int numA, int *pArrayB, int numB, int *pOutput, int numOutput)
{
    assert(pArrayA && pArrayB && pOutput);

    for (int ia = 0, ib =0, k = 0; (ia < numA) || (ib < numB);) {
        if (ia < numA) {
            if (ib < numB) {
                if (pArrayA[ia] < pArrayB[ib]) {
                    pOutput[k] = pArrayA[ia];
                    k++;
                    ia++;
                } else {
                    pOutput[k] = pArrayB[ib];
                    k++;
                    ib++;
                }
            } else {
                pOutput[k] = pArrayA[ia];
                k++;
                ia++;
            }
        } else {
            pOutput[k] = pArrayB[ib];
            k++;
            ib++;
        }
    } 

    return 0;
}

int split_array(int *pInput, int numInput)
{
    if (numInput >= 2) {
        int imiddle = numInput / 2; 
        split_array(pInput, imiddle);
        split_array(pInput + imiddle, numInput - imiddle);

        int *ptemp = malloc(numInput * sizeof(int));
        merge_array(pInput, imiddle, pInput + imiddle, numInput - imiddle, ptemp, numInput);
        memcpy(pInput, ptemp, (sizeof(int) * numInput));
        free(ptemp);
    } 
}

/*
 *  sort the input array using merging_sort method.
 *      
 *  @param[in]  pInput:
 *  @param[in]  numInput:
 *  @param[out] pOutput:
 *  @param[in]  nOutput:
 *                          
 *  @return
 *      - 0 success
 *      - 1 failure
 *                              */
int merge_sort(int *pInput, int numInput, int *pOutput, int nOutput)
{
    split_array(pInput, numInput);
    memcpy(pOutput, pInput, (sizeof(int) * numInput));

    return 0;
}

int main(int argc, char *argv[]) {

    int iArray[] = {9, 1, 4, 7, 5};
    size_t numItem = sizeof(iArray) / sizeof(iArray[0]);

    const int Len = 1024;
    int ibuff[Len]; 
    merge_sort(iArray, numItem, ibuff, Len);

    // print the sorted array.
    for (int i = 0; i < numItem; i++) {
        printf("%d\t", ibuff[i]);
    }
    printf("\n");

    exit(0);
}
