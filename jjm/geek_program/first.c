#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNumber(int A[], int lengthA){
    
    int len_ptemp = 1001;
    int *ptemp = calloc(len_ptemp, sizeof(int));
    memset(ptemp, 0, len_ptemp * sizeof(int));
    
    for (int i = 0; i < lengthA; i++) {
        ptemp[A[i]]++; 
    }

    int result = 0;
    for (int i = 0; i < len_ptemp; i++) {
        if (1 == ptemp[i]) {
            result = i;
            break;
        }
    }

    free(ptemp);

    return result;
}

int main(){
    //int a[] = {1,1,3,3,5};
    printf("%d", getNumber(a,5));
}

