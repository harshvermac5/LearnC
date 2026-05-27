#include <stdio.h>

void shell(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}

int main(void) {
    int v[] = { 23, 12, 1, 8, 34, 54, 2, 3 };
    int n = sizeof(v) / sizeof(v[0]);
    int i;

    printf("Before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d%c", v[i], (i+1==n) ? '\n' : ' ');

    shell(v, n);

    printf("After sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d%c", v[i], (i+1==n) ? '\n' : ' ');

    return 0;
}

/*
Gap Sequence: Shell sort begins by sorting elements at specific intervals, known as gaps. The algorithm progressively reduces the gap until it reaches 1, at which point a standard insertion sort is performed.


1. Initialize the Gap: Start with a large gap and reduce it over time.
2. Sort Subarrays: For each gap, sort the elements that are spaced apart by the gap using insertion sort.
3. Repeat: Continue reducing the gap and sorting until the gap is 1, ensuring the entire list is sorted.
*/
