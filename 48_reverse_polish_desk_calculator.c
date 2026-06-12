#include <stdio.h>

#define MAXOP 20
#define NUMBER '0'
#define TOOBIG '9'

int getop(char s[], int lim);
double pop(void);
double push(double f);
void clear(void);
int is_digit(char c);
double ascii_to_float(char s[]);
int get_ch(void);
int unget_ch(int c);

int main(void){
  int type;
  char s[MAXOP];
  double op2;

  while ((type = getop(s, MAXOP)) != EOF) {
    switch (type) {
      case NUMBER:
        push(ascii_to_float(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '=':
        printf("\t%.6f\n", pop());
        break;
      case 'c':
        clear();
        break;
      case TOOBIG:
        printf("error: %.20s ... is too long\n", s);
        break;
      default:
        printf("error: unknown command %c\n", type);
        break;
    }
  }
  return 0;
}

int getop(char s[], int lim){
  int i, c;
  
  while ((c = get_ch()) == ' ' || c == '\t' || c == '\n' || c == '\r')
    ;
  
  if (c == EOF)
    return EOF;
  
  if (!is_digit(c) && c != '.') {
    return c;
  }
  
  i = 0;
  if (is_digit(c))
    s[i++] = c;
    while (is_digit(c = get_ch()))
      s[i++] = c;
  
  if (c == '.') {
    s[i++] = c;
    while (is_digit(c = get_ch()))
      s[i++] = c;
  }
  
  s[i] = '\0';
  
  if (i >= lim)
    return TOOBIG;
  else
    unget_ch(c);
  
  return NUMBER;
}

