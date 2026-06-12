#include <stdio.h>

int main(void){
	char ca[10], *cp;
	int ia[10], *ip;

	// Set cp to point to ca[1] (second element)
	cp = ca + 1;

	// Set ip to point to ia[1] (second element)
	ip = ia + 1;

	printf("ca %p cp %p\n", ca, cp);
	printf("ia %p ip %p\n", ia, ip);
}

/*
The array name ca itself is a pointer to the first element (ca[0]). So:

    ca points to ca[0] (the first character)
    ca + 1 points to ca[1] (the second character)
    ca + 2 points to ca[2] (the third character)
    And so on...
*/

