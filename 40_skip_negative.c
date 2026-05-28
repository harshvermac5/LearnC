#include <stdio.h>

#define N 10

int skip_negative(char arr[]) {
    int i;
    for (i = 0; i < N; i++) {
        if (arr[i] < 0)
            continue;
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    char arr[N] = {5, -3, 8, -1, 2, -9, 0, 4, -7, 6};
    
    printf("Array elements (excluding negative values): ");
    skip_negative(arr);
    
    return 0;
}

