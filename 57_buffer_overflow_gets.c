#include <stdio.h>

int main(void){
	char s[15];
	gets(s);
	printf("s: %s\n", s);
}

// mordern compiler restrict the gets() function due to is dangerous nature, fgets() is preferred
