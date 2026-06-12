#include <stdio.h>

int main(){
  int compute;
  register int iter;

  scanf("%d", &compute);
  printf("compute %d\n", compute);
  for (iter=0; iter<1000; iter++){
    compute = (compute * 22) * 7;
    if (compute > 1000) compute = compute % 1000;
  }
  printf("compute %d\n", compute);
}
