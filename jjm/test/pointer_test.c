#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int ival = 14;
    int *pi = &ival;
    int *ptemp = pi;
    ptemp = NULL;
    if (pi) {
        printf("%d\n", *pi);
    }

    exit(0);
}
