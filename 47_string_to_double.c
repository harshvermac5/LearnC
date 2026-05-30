#include <stdio.h>

/* function from your message (note: name corrected to string_to_double) */
double string_to_double(char s[]){
    double val, power;
    int i, sign;

    for (i=0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++);

    sign = 1;

    if (s[i] == '+' || s[i] == '-')
        sign = (s[i++]=='+') ? 1 : -1;

    for (val=0; s[i] >= '0' && s[i] <= '9'; i++)
        val = 10 * val + s[i] - '0';

    if (s[i] == '.')
        i++;

    for (power = 1; s[i] >= '0' && s[i] <= '9'; i++){
        val = 10 * val + s[i] - '0';
        power *= 10;
    }
    return (sign * val / power);
}

int main(void){
    char *tests[] = {
        "123.45",
        "   -0.007",
        "+42",
        "3.14159",
        "0",
        "  10.",
        ".5",
        "invalid123",
        NULL
    };

    for (int t = 0; tests[t] != NULL; t++){
        double d = string_to_double((char *)tests[t]);
        printf("input: \"%s\" -> %f\n", tests[t], d);
    }
    return 0;
}

