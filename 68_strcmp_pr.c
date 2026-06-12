#include <stdio.h>

int strcmp_cust(const char *s, const char *t) {
    for (; *s == *t; ++s, ++t) {
        if (*s == '\0')
            return 0;
    }
    return (int)((unsigned char)*s - (unsigned char)*t);
}

int main(void) {
    const char *a = "apple";
    const char *b = "apricot";
    const char *c = "apple";

    int r1 = strcmp_cust(a, b);
    printf("strcmp_cust(\"%s\", \"%s\") = %d\n", a, b);

    int r2 = strcmp_cust(a, c);
    printf("strcmp_cust(\"%s\", \"%s\") = %d\n", a, c);

    int r3 = strcmp_cust(b, a);
    printf("strcmp_cust(\"%s\", \"%s\") = %d\n", b, a);

    if (r2 == 0)
        puts("a and c are equal");
    return 0;
}

