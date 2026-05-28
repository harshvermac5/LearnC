#include <stdio.h>

#define N 3
#define M 3

int main() {
    int i, j;
    int v[N][M] = {
        {1, 2, 3},
        {4, -5, 6},
        {7, 8, 9}
    };
    
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if (v[i][j] < 0)
                goto found;
    
    printf("No negative number found\n");
    return 0;

found:
    printf("Found negative number: %d at position [%d][%d]\n", v[i][j], i, j);
    return 0;
}

