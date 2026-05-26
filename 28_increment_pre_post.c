#include <stdio.h>

void my_strcat(char s[], char t[])
{
        int i, j;

        i = j = 0;
        while (s[i] != '\0')
                i++;
        while ((s[i++] = t[j++]) != '\0')
                ;
}

int main()
{
        char str1[100] = "Hello ";
        char str2[50] = "World";
        
        char str3[100] = "C ";
        char str4[50] = "Programming";

        printf("Test 1:\n");
        printf("Before: \"%s\" + \"%s\"\n", str1, str2);
        my_strcat(str1, str2);
        printf("After: \"%s\"\n\n", str1);

        printf("Test 2:\n");
        printf("Before: \"%s\" + \"%s\"\n", str3, str4);
        my_strcat(str3, str4);
        printf("After: \"%s\"\n", str3);

        return 0;
}

