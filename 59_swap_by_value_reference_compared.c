#include <stdio.h>

// Pass-by-value (doesn't work)
swap_byvalue(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Pass-by-reference (works)
swap_byreference(int *px, int *py){
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main(){
    int a = 5, b = 10;
    
    swap_byvalue(a, b);
    printf("After byvalue swap: a = %d, b = %d\n", a, b);  // Still 5, 10
    
    swap_byreference(&a, &b);
    printf("After byreference swap: a = %d, b = %d\n", a, b);  // Now 10, 5
    
    return 0;
}

