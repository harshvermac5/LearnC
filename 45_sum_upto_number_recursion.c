#include <stdio.h>

/* 
 * Function: calculate_sum_to_number
 * Purpose: Recursively calculates the sum of all integers from 1 to n
 * Example: calculate_sum_to_number(5) returns 1+2+3+4+5 = 15
 * Parameter: number - the upper limit for the sum
 * Returns: the sum of integers from 1 to number
 */
int calculate_sum_to_number(int number) {
    int number_minus_one;
    int sum_of_smaller_numbers;
    int total_result;

    printf("Processing number: %d\n", number);
    
    /* Base case: when we reach 1, stop recursing and return 1 */
    if (number <= 1) {
        return 1;
    }

    /* Recursive case: subtract 1 and call the function again */
    number_minus_one = number - 1;
    printf("Going down to: %d\n", number_minus_one);

    /* Call the function recursively with the smaller number */
    sum_of_smaller_numbers = calculate_sum_to_number(number_minus_one);
    printf("Got sum of smaller numbers: %d\n", sum_of_smaller_numbers);

    /* Add the current number to the sum of all smaller numbers */
    total_result = number + sum_of_smaller_numbers;
    printf("Total for this step: %d + %d = %d\n", number, sum_of_smaller_numbers, total_result);

    return total_result;
}

int main() {
    int final_sum = calculate_sum_to_number(3);
    printf("\nFinal result: %d\n", final_sum);
    
    return 0;
}

