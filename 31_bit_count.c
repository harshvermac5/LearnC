#include <stdio.h>

int bitcount (unsigned n){
        int b;
        for (b=0; n!= 0; n>>= 1)
                if (n & 01)
                        b++;
        return(b);
}

int main() {
        unsigned num;
        int count;
        
        // Demonstrate assignment operator with bitcount function
        num = 15;  // Assignment: num gets value 15 (binary: 1111)
        count = bitcount(num);  // Assignment: count gets return value from bitcount
        printf("Number: %u, Bit count: %d\n", num, count);
        
        num = 255;  // Assignment: num gets value 255 (binary: 11111111)
        count = bitcount(num);
        printf("Number: %u, Bit count: %d\n", num, count);
        
        num = 7;  // Assignment: num gets value 7 (binary: 111)
        count = bitcount(num);
        printf("Number: %u, Bit count: %d\n", num, count);
        
        return 0;
}

