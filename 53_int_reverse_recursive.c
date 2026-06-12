#include <stdio.h>

void printd(int n){
  int i;
  
  if (n < 0){
    putchar('-');
    n = -n;
  }
  if ((i = n/10) != 0)
    printd(i);
  putchar(n % 10 + '0');
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

