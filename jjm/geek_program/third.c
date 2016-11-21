#include <stdio.h>
#include <malloc.h> 
#include <string.h>

#define true 1
#define false 0

char* create(char B[], int lengthB, int n) {
    char *c = (char*)malloc(lengthB * n);
    int index = 0;
    int i,j;
    for(j = 0; j < lengthB; j++)
        for(int i = 0; i < n; i++)
            c[index++] = B[j];
    return c;
}

int isTrue(char A[], int lengthA, char B[], int lengthB) {
    int indexA = 0;
    int indexB = 0;
    while(indexA < (lengthA - 1) && (indexB < lengthB - 1)){
        if(A[indexA] == B[indexB]){
            indexB++;
        }
        indexA++;
    }
    if(indexB == (lengthB - 1))
        return true;
    return false;
}


int getNumber(char A[], int lengthA, char B[], int lengthB){
    //todo
    int iresult = 0;
    int i = 0;
    for (i = lengthA/ lengthB; i >= 0; i--) {
        char *ptempb = create(B, lengthB, i);
        if (isTrue(A, lengthA, ptempb, lengthB * i)) {
            iresult = i;
            free(ptempb);

            break;
        }

        //debug
        printf("dddddddddddddd\n");
        
        free(ptempb);
    }

    //todo

    return iresult;
}

int main(){
    char * a = "ABACAABBABBCAABCCC";
    char * b = "ABC";
    int lengthA = strlen(a);
    int lengthB = strlen(b);
    printf("n=%d", getNumber(a, lengthA, b, lengthB));
}
