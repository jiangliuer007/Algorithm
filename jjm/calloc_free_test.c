#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  
    char *ptemp = calloc(1024, 1);
    strcpy(ptemp, "this is a test.");

    printf("%s\n", ptemp);

    free(ptemp);

    printf("%s\n", ptemp);

    exit(0);
}
