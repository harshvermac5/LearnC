#include <stdio.h>

void squeeze(char s[], int c)
{
        int i, j;

        for (i=j=0; s[i] != '\0'; i++)
                if (s[i] != c)
                        s[j++] = s[i];
        s[j] = '\0';
}

int main()
{
        char str[100] = "hello world";
        int charToRemove = 'l';

        printf("Original string: %s\n", str);
        printf("Character to remove: '%c'\n", charToRemove);

        squeeze(str, charToRemove);

        printf("After squeeze: %s\n", str);

        return 0;
}

