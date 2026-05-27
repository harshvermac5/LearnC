#include <stdio.h>

/* corrected atoi: returns integer value of s */
int atoi(char s[])
{
    int i, n, sign;
    for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++)
        ;
    sign = 1;
    if (s[i] == '+' || s[i] == '-')
        sign = (s[i++] == '+') ? 1 : -1;
    for (n = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

int main(void)
{
    char *tests[] = {
        "123",
        "   -42",
        "+17abc",
        "0",
        "  +0",
        "  987654321",
        "  -2147483648",
        "non-number",
        ""
    };
    int i, val;

    for (i = 0; i < (int)(sizeof tests / sizeof tests[0]); i++) {
        val = atoi((char *)tests[i]);
        printf("atoi(\"%s\") = %d\n", tests[i], val);
    }
    return 0;
}

