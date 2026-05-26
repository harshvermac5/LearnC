#include <stdio.h>

int main(){
        int lower, upper, step;
        float fahr, celsius;
        lower = 0;
        upper = 300;
        step = 20;
        fahr = lower;

        while (fahr <= upper){
                celsius = (5.0/9.0) * (fahr-32.0);
                printf("%4.0f %6.1f\n", fahr, celsius);
                fahr = fahr + step;
        }
        
        return 0;
}

/*
%4.0f — for the fahr variable:

    % = "start of a format code"
    4 = "use 4 spaces total for this number"
    .0 = "show 0 decimal places" (no numbers after the decimal point)
    f = "this is a floating-point number (decimal)"

So 0 prints as    0 (right-aligned in 4 spaces)

%6.1f — for the celsius variable:

    % = "start of a format code"
    6 = "use 6 spaces total for this number"
    .1 = "show 1 decimal place" (one number after the decimal point)
    f = "this is a floating-point number (decimal)"

So -17.777 prints as  -17.8 (rounded to 1 decimal, right-aligned in 6 spaces)
 */
