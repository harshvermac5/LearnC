#include <stdio.h>

void swap(int *px, int *py){
    int temp;
    
    temp = *px;
    *px = *py;
    *py = temp;
}

int main(){
    int a = 5;
    int b = 10;
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    
    swap(&a, &b);  // Pass addresses of a and b
    
    printf("After swap: a = %d, b = %d\n", a, b);
    
    return 0;
}

