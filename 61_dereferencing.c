#include <stdio.h>

int main() {
		// Step 1: Declare an integer variable
    int point = 9;     
		// Step 2: Declare a pointer variable
    int *ptr;          
		// Step 3: Assign the address of 'point' to 'ptr'
    ptr = &point;      
		// Step 4: Dereference 'ptr' to change the value of 'point'
    *ptr = 8;          

		// Output: The value of point is: 8
    printf("The value of point is: %d\n", point); 
    return 0;
}

