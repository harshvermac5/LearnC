#include <stdio.h>

int atoi(char s[]) {
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + s[i] - '0';
  return n;
}

int main() {
  char str[] = "12345";
  printf("String: %s\n", str);
  printf("Integer: %d\n", atoi(str));
  return 0;
}

/*
For input "523":

    i=0: s[0]='5' → n = 0*10 + ('5'-'0') = 5
    i=1: s[1]='2' → n = 5*10 + ('2'-'0') = 52
    i=2: s[2]='3' → n = 52*10 + ('3'-'0') = 523
    Loop ends (next character isn't a digit)
    Return 523
*/
