#include <stdio.h>

/*
strcpy_without_ptr
- Copies a C string from t to s using array indexing.
- Uses an integer index i to iterate through characters.
- Assigns s[i] = t[i] and stops when the null terminator '\0' has been copied.
- Caller must ensure s has enough space to hold t (including terminating '\0').
*/
void strcpy_without_ptr(char s[], char t[]) {
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/*
strcpy_with_ptr
- Copies a C string from t to s using explicit pointer arithmetic.
- Dereferences pointers to assign characters: *s = *t.
- After each assignment, increments both s and t pointers.
- Stops when the null terminator '\0' has been copied.
- Caller must ensure s points to a buffer large enough to hold t.
*/
void strcpy_with_ptr(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/*
strcpy_with_ptr_v2
- A compact pointer-based copy using post-increment in the assignment.
- The expression (*s++ = *t++) assigns *t to *s, then increments both pointers.
- The loop body is empty; the loop continues until the assigned character is '\0'.
- This idiom is common and concise; equivalent to strcpy in behavior.
*/
void strcpy_with_ptr_v2(char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ; /* empty body */
}

/*
strcpy_with_ptr_v3
- An incorrect variant in the original; corrected here to use assignment in the loop condition.
- Uses the idiom while ((*s++ = *t++) != '\0') which copies and advances pointers.
- If you intended to compare instead of assign, that would not copy; the assignment form is required.
- This function is identical in behavior to strcpy_with_ptr_v2.
*/
void strcpy_with_ptr_v3(char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ; /* empty body */
}

/* Example main to demonstrate usage */
int main(void) {
    char src[] = "Hello, world!";
    char dst1[50], dst2[50], dst3[50], dst4[50];

    strcpy_without_ptr(dst1, src);
    strcpy_with_ptr(dst2, src);
    strcpy_with_ptr_v2(dst3, src);
    strcpy_with_ptr_v3(dst4, src);

    printf("%s\n%s\n%s\n%s\n", dst1, dst2, dst3, dst4);
    return 0;
}

