#include <stdio.h>

unsigned getbits(unsigned x, unsigned p, unsigned n)
{
        return ((x >> (p+1-n)) & ~(~0 << n));
}

int main()
{
        unsigned x = 0b11010110;  // 214 in decimal
        unsigned p = 6;            // Position 6
        unsigned n = 3;            // Extract 3 bits
        
        unsigned result = getbits(x, p, n);
        
        printf("x = %u (binary: %08b)\n", x, x);
        printf("Position p = %u (counting from right, 0-indexed)\n", p);
        printf("Number of bits n = %u\n", n);
        printf("\ngetbits(x, p, n) = %u (binary: %03b)\n\n", result, result);
        
        // More examples
        printf("=== More Examples ===\n");
        
        printf("getbits(0b11010110, 6, 3) = %u (bits at positions 6,5,4)\n", 
               getbits(0b11010110, 6, 3));
        printf("getbits(0b11010110, 4, 2) = %u (bits at positions 4,3)\n", 
               getbits(0b11010110, 4, 2));
        printf("getbits(0b11010110, 2, 4) = %u (bits at positions 2,1,0)\n", 
               getbits(0b11010110, 2, 1));
        printf("getbits(255, 7, 4) = %u (extract 4 bits from position 7)\n", 
               getbits(255, 7, 4));
        
        return 0;
}

