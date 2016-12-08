#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

//#define MAX_LEN 1024
#define MAX_LEN 12

typedef struct queue_info {
    int iarray[MAX_LEN];
    int istart;
    int iend;
    int inum_items;
}qi;

int queue_is_empty(qi *pqueue) {
    assert(pqueue);

    if (!(pqueue->inum_items)) {
        return 1;
    } else {
        return 0;
    }
}

/* optional */
int queue_is_full(qi *pqueue) {
    assert(pqueue);

    if (MAX_LEN == pqueue->inum_items) {
        return 1;
    } else {
        return 0;
    }
}

int enqueue(qi *pqueue, int ival) {
    assert(pqueue);
    assert(!queue_is_full(pqueue));

    pqueue->inum_items += 1;

    pqueue->iend += 1;
    if (MAX_LEN == pqueue->iend) {
        pqueue->iend = 0;
    }
    pqueue->iarray[pqueue->iend] = ival;

    return 0;

}

int dequeue(qi *pqueue, int *pival) {
    assert(pqueue && pival);
    assert(!queue_is_empty(pqueue));

    pqueue->inum_items -= 1;

    *pival = pqueue->iarray[pqueue->istart];
    pqueue->istart += 1;

    return 0;

}

int main(int argc, char *argv[]) {

    int iarray[] = {15, 6, 9, 8, 4};
    int inum_items = sizeof(iarray) / sizeof(iarray[0]);

    qi queue_info;
    memset(&queue_info, 0, sizeof(queue_info));
    queue_info.iend = -1;

    for (int k = 0; k < 4; k++) {
        // enqueue
        for (int i = 0; i< inum_items; i++) {
            enqueue(&queue_info, iarray[i]);
        }

        // dequeue
        while (!queue_is_empty(&queue_info)) {
            int ival;
            dequeue(&queue_info, &ival);
            printf("%d\t", ival);
        }
        printf("\n");
    }

    // dubug
    printf("sssssssssssssss\n");
    for (int i = 0; i < MAX_LEN; i++) {
        printf("%d\t", queue_info.iarray[i]);
    }
    printf("\n");
    // debug

    exit(0);
}
