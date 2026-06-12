#include <stdio.h>
#include <stddef.h>

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (n <= 0)
        return NULL;
    if (allocp + n <= allocbuf + ALLOCSIZE) {
        allocp += n;
        return allocp - n;
    } else {
        return NULL;
    }
}

void free_mem(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

/* Example usage */
int main(void) {
    char *p1 = alloc(100);
    if (p1 == NULL) {
        printf("alloc failed\n");
        return 1;
    }
    char *p2 = alloc(200);
    if (p2 == NULL) {
        printf("alloc failed\n");
        return 1;
    }

    /* use memory */
    p1[0] = 'A';
    p2[0] = 'B';
    printf("%c %c\n", p1[0], p2[0]);

    free_mem(p2); /* must free in LIFO order */
    free_mem(p1);

    return 0;
}
