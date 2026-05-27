#include <stdio.h>

int my_strlen(char s[]) {
  int count = 0;
  while (s[count] != '\0') {
    count++;
  }
  return count;
}

int reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = my_strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

int main() {
  char str[] = "Hello";
  
  printf("Original string: %s\n", str);
  reverse(str);
  printf("Reversed string: %s\n", str);
  
  return 0;
}

