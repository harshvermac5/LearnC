#include <stdio.h>

#define MAXLINE 1000

char line[MAXLINE];
char save[MAXLINE];
int max;

int get_line(void);
void copy(void);

int get_line(void) {
  int c, i;
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy(void) {
  int i = 0;
  while ((save[i] = line[i]) != '\0')
    ++i;
}

int main() {
  int len;

  max = 0;
  while ((len = get_line()) > 0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0)
    printf("%s", save);

  return 0;
}

