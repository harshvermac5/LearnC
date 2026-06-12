#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 5

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    if (bufp > 0)
        return buf[--bufp];
    else
        return getchar();
}

int ungetch(int c){
    if (bufp >= BUFSIZE){
        fprintf(stderr, "ungetch: too many characters\n");
        fflush(stderr);
        return -1;
    } else {
        buf[bufp++] = c;
        return 0;
    }
}

int get_int(int *pn){
    int c, sign;
    
    while ((c = getch()) == ' ' || c == '\n' || c == '\t');
    
    sign = 1;
    if (c == '+' || c == '-'){
        sign = (c == '+') ? 1 : -1;
        c = getch();
    }
    
    for (*pn = 0; c >= '0' && c <= '9'; c = getch())
        *pn = 10 * *pn + c - '0';
    
    *pn *= sign;
    
    if (c != EOF){
        if (ungetch(c) == -1){
            fprintf(stderr, "Warning: character loss during input.\n");
            fflush(stderr);
        }
    }
    
    return (c);
}


int main(void){
    int num, result;
    
    printf("Enter an integer: ");
    fflush(stdout);
    result = get_int(&num);
    
    printf("\nYou entered: %d\n", num);
    printf("Stopped at character: '%c' (ASCII %d)\n", 
           result == EOF ? 'E' : result, result);
    
    printf("\nEnter another integer: ");
    fflush(stdout);
    result = get_int(&num);
    
    printf("\nYou entered: %d\n", num);
    printf("Stopped at character: '%c' (ASCII %d)\n", 
           result == EOF ? 'E' : result, result);
    
    return 0;
}
