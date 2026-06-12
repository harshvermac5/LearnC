#include <stdio.h>

void printd(int n){
  char s[10];
  int i;

  if (n<0){
    putchar('-');
    n = -n;
  }

  i = 0;
  do {
    s[i++] = n % 10 + '0';
  }
  while ((n /= 10) > 0);
  while (--i >= 0)
    putchar(s[i]);
}

int main(){
  printd(12345);
  putchar('\n');
  printd(-9876);
  putchar('\n');
  printd(0);
  putchar('\n');
  
  return 0;
}

