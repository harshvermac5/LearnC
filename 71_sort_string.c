#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAXLEN    1000

static ssize_t get_line(char *buf, size_t maxlen);
static int readlines(char **lineptr, int maxlines);
static void writelines(char **lineptr, int nlines);
static char *alloc_line(size_t n);
static void free_lines(char **lineptr, int nlines);
static void quicksort(char **v, int left, int right);
static int str_cmp(const char *a, const char *b);

int main(void)
{
    char *lineptr[MAX_LINES];
    int nlines;

    nlines = readlines(lineptr, MAX_LINES);
    if (nlines < 0) {
        fprintf(stderr, "input too big to sort or allocation failed\n");
        return EXIT_FAILURE;
    }

    quicksort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    free_lines(lineptr, nlines);

    return EXIT_SUCCESS;
}

/* get_line: read a line into buf, return length (including newline if present) */
static ssize_t get_line(char *buf, size_t maxlen)
{
    if (maxlen == 0) return 0;
    size_t i = 0;
    int c;
    while (i < maxlen - 1 && (c = getchar()) != EOF && c != '\n') {
        buf[i++] = (char)c;
    }
    if (c == '\n') {
        buf[i++] = '\n';
    }
    buf[i] = '\0';
    return (ssize_t)i;
}

/* readlines: read input lines, allocate space, store pointers in lineptr[].
   Returns number of lines read, or -1 on error (too many lines or allocation failure). */
static int readlines(char **lineptr, int maxlines)
{
    char line[MAXLEN];
    int nlines = 0;
    ssize_t len;
    while ((len = get_line(line, sizeof(line))) > 0) {
        if (nlines >= maxlines) {
            return -1;
        }
        /* remove trailing newline if present */
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        char *p = alloc_line((size_t)len + 1); /* +1 for '\0' */
        if (p == NULL) {
            /* allocation failed: clean up previously allocated lines */
            free_lines(lineptr, nlines);
            return -1;
        }
        memcpy(p, line, (size_t)len + 1);
        lineptr[nlines++] = p;
    }
    return nlines;
}

/* writelines: print the stored lines */
static void writelines(char **lineptr, int nlines)
{
    for (int i = 0; i < nlines; ++i) {
        puts(lineptr[i]); /* prints string and newline */
    }
}

/* alloc_line: wrapper around malloc */
static char *alloc_line(size_t n)
{
    return (char *)malloc(n);
}

/* free_lines: free all allocated lines */
static void free_lines(char **lineptr, int nlines)
{
    for (int i = 0; i < nlines; ++i) {
        free(lineptr[i]);
        lineptr[i] = NULL;
    }
}

/* quicksort: sorts array of strings in-place using strcmp ordering */
static void quicksort(char **v, int left, int right)
{
    if (left >= right) return;
    int i = left, j = right;
		// uses middle element as pivot
    char *pivot = v[(left + right) / 2];
    while (i <= j) {
        while (str_cmp(v[i], pivot) < 0) i++;
        while (str_cmp(v[j], pivot) > 0) j--;
        if (i <= j) {
            char *tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++; j--;
        }
    }
    if (left < j) quicksort(v, left, j);
    if (i < right) quicksort(v, i, right);
}

/* str_cmp: wrapper to compare two strings (keeps calls concise) */
static int str_cmp(const char *a, const char *b)
{
    return strcmp(a, b);
}

