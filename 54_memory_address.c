#include <stdio.h>

int main(void){
	int x, y;
	int* px;

	x = 42;

	// assigns the address of x to px. The & operator gets the memory address where x is stored. Now px points to x
	px = &x;

	// dereferences the pointer px to get the value it points to (which is x), and assigns that value to y
	y = *px;

	printf("%d %p %d\n", x, px, y);
}
