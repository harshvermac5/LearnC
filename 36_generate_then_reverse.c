#include <stdio.h>

// Forward declarations
void reverse(char s[]);
int my_strlen(char s[]);
void itoa(int n, char s[]);

void reverse(char s[]) {
    int i, j;
    char c;
    
    for (i = 0, j = my_strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int my_strlen(char s[]) {
  int count = 0;
  while (s[count] != '\0') {
    count++;
  }
  return count;
}

void itoa(int n, char s[]) {
    int i, sign;
    
    sign = n;
    if (n < 0)
        n = -n;
    
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    
    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}

int main() {
    char str[50];
    
    itoa(12345, str);
    printf("12345 converts to: %s\n", str);
    
    itoa(-9876, str);
    printf("-9876 converts to: %s\n", str);
    
    itoa(0, str);
    printf("0 converts to: %s\n", str);
    
    itoa(-42, str);
    printf("-42 converts to: %s\n", str);
    
    return 0;
}

