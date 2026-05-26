#include <stdio.h>

int main()
{
        int a = 12;     // binary: 1100
        int b = 10;     // binary: 1010
        
        printf("a = %d (binary: 1100)\n", a);
        printf("b = %d (binary: 1010)\n\n", b);
        
        printf("Inclusive OR (a | b):\n");
        printf("  1100\n");
        printf("| 1010\n");
        printf("------\n");
        printf("  1110 = %d\n\n", a | b);
        
        printf("Exclusive OR (a ^ b):\n");
        printf("  1100\n");
        printf("^ 1010\n");
        printf("------\n");
        printf("  0110 = %d\n", a ^ b);
        
        return 0;
}

