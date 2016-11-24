#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define STACK_SIZE 20

typedef struct info_stack {
    int iarray[STACK_SIZE];
    int itop;
}istack;

int stack_empty(istack *pstack) {
    assert(pstack);

    if (pstack->itop == -1) {
        return 1;
    } else {
        return 0;
    }
}
int stack_full(istack *pstack) {
    assert(pstack);

    if (STACK_SIZE - 1 == pstack->itop) {
        return 1;
    } else {
        return 0;
    }
}

int push(istack *pstack, int ival) {
    assert(pstack);
    assert(!stack_full(pstack));

    pstack->itop += 1;
    pstack->iarray[pstack->itop] = ival;

    return 0;
}

int pop(istack *pstack, int *pival) {
    assert(pstack && pival);
    assert(!stack_empty(pstack));

    *pival = (pstack->iarray)[pstack->itop];
    pstack->itop -= 1;

    return 0;
}

int main (int argc, char *argv[]) {
    int iarray[] = {1, 7, 4, 19, 8, 7};
    int num_items = sizeof(iarray) / sizeof(iarray[0]);
    
    istack stack_info;
    memset(&stack_info, 0, sizeof(stack_info));
    stack_info.itop = -1;

    //
    for (int i = 0; i < num_items; i++) {
        push(&stack_info, iarray[i]);
    }

    int ifull = stack_full(&stack_info);
    printf("stack is full: %d\n", ifull);
    
    while (!stack_empty(&stack_info)) {
        int ival;
        pop(&stack_info, &ival);
        printf("%d\n", ival);
    }

    exit(0);
}
