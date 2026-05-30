#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int read_line(char buffer[], int max_len) {
    int c, i;
    for (i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        buffer[i] = (char)c;
    }
    if (c == '\n') {
        buffer[i] = (char)c;
        ++i;
    }
    buffer[i] = '\0';
    return i;
}

int find_substring(const char text[], const char pattern[]) {
    int i, j, k;

    if (pattern[0] == '\0')
        return 0;

    for (i = 0; text[i] != '\0'; ++i) {
        for (j = i, k = 0; pattern[k] != '\0' && text[j] == pattern[k]; ++j, ++k)
            ;
        if (pattern[k] == '\0')
            return i;
    }
    return -1;
}

int main(void) {
    char line[MAX_LINE_LENGTH];
    const char *search_term = "the";

    while (read_line(line, MAX_LINE_LENGTH) > 0) {
        if (find_substring(line, search_term) >= 0) {
            printf("%s", line);
        }
    }

    return 0;
}

/*
 * read_line reads characters until newline or EOF, stores a terminating '\0', and returns the length.
 * find_substring is a simple nested-loop substring search (like strstr) that returns the start index or -1.
 * main repeatedly reads lines and prints those containing the search term.
 */
