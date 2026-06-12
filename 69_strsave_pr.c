#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strsave_cust(const char *s) {
    if (s == NULL) {
        return NULL;
    }

    size_t len = strlen(s) + 1;
    char *p = malloc(len);
    if (p == NULL) {
        return NULL;
    }

    memcpy(p, s, len);
    return p;
}

int main(void) {
    const char *orig = "Hello, world!";
    char *copy = strsave_cust(orig);

    if (copy == NULL) {
        fprintf(stderr, "Allocation failed\n");
        return EXIT_FAILURE;
    }

    printf("original: %s\n", orig);
    printf("copy:     %s\n", copy);

    copy[7] = 'W';
    
		printf("modified copy: %s\n", copy);
    printf("original still: %s\n", orig);

    free(copy);
    return EXIT_SUCCESS;
}

