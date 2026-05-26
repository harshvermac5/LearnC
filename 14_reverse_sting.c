#include <stdio.h>

void reverseString(char str[]) {
    // Find the length of the string
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    
    // Reverse by swapping characters from both ends
    int left = 0;
    int right = length - 1;
    
    while (left < right) {
        // Swap
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        
        left++;
        right--;
    }
}

int main(){
    char x[6];
    x[0] = 'H';
    x[1] = 'e';
    x[2] = 'l';
    x[3] = 'l';
    x[4] = 'o';
    x[5] = '\0';
    printf("%s\n",x);

    x[2] = 'L';
    printf("%s\n",x);

    //x[3] = '\0';
    //printf("%s\n",x);
    
    // Reverse the string
    reverseString(x);
    printf("%s\n",x);
    
    return 0;
}

