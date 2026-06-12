#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40};
    int *px = arr;
    int *p = arr;

    printf("Initial: px = %p, p = %p\n", (void*)px, (void*)p);

		printf("Initial values pointed: *px = %d, *p = %d\n\n", *px, *p);

    int *ret1 = (px += 1);
    
		printf("After px += 1: px = %p, returned ret1 = %p\n", (void*)px, (void*)ret1);
    
		printf("Value at px: *px = %d\n\n", *px);

    int *ret2 = (p++);
    
		printf("After p++ (expression returned ret2): p = %p, returned ret2 = %p\n", (void*)p, (void*)ret2);
    
		printf("Value at p: *p = %d\n\n", *p);

    int val_from_px = *px; 
    
		int val_from_ret2 = *ret2;
    printf("Dereferencing current px gives %d\n", val_from_px);
    
		printf("Dereferencing returned pointer from p++ (ret2) gives %d\n\n", val_from_ret2);

    printf("Advance again with px += 1: px = %p, *px = %d\n", (void*)(px += 1), *px);
    
		printf("Use *p++ in an expression: value = %d, now p = %p\n", *p++, (void*)p);

    return 0;
}
