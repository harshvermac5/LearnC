#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int get_ch(){
  return((bufp > 0) ? buf[--bufp] : getchar());
}

int unget_ch(int c){
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
  return c;
}
