#include <stdio.h>

int binary(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;      /* compute middle index */
        if (x < v[mid])
            high = mid - 1;          /* search left half */
        else if (x > v[mid])
            low = mid + 1;           /* search right half */
        else
            return mid;              /* found: return index */
    }
    return -1;                       /* not found */
}

int main(void){
    int arr[] = {2, 4, 7, 11, 15, 18, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targets[] = {7, 5, 21, 1};
    int i;

    for (i = 0; i < (int)(sizeof(targets)/sizeof(targets[0])); ++i) {
        int t = targets[i];
        int idx = binary(t, arr, n);
        if (idx >= 0)
            printf("Value %d found at index %d\n", t, idx);
        else
            printf("Value %d not found\n", t);
    }
    return 0;
}

/*
binary implements a standard binary search on a sorted array v of length n to find value x.
low and high mark the current search interval; mid is its middle index: mid = (low + high)/2.
If x < v[mid], the target must be left of mid, so set high = mid - 1.
If x > v[mid], the target must be right of mid, so set low = mid + 1.
If x == v[mid], return mid (position found).
Loop stops when low > high; then x is not present and function returns -1.
sizeof(targets) — total size in bytes of the entire targets array.
sizeof(targets[0]) — size in bytes of one element (the first element) of targets.
sizeof(targets)/sizeof(targets[0]) — number of elements in the array (total bytes ÷ bytes per element).
(int)(...) — casts the result to int (sizeof returns size_t, an unsigned type).
for (i = 0; i < count; ++i) — standard index loop visiting each element from index 0 to count-1.
It computes the array length automatically, so you don't hard-code a literal length that could become wrong if you change the initializer.
It's evaluated at compile time for statically sized arrays, so there's no runtime overhead.
*/
