#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

int is_digit(char c) {
  if (c >= '0' && c <= '9')
    return 1;
  else
    return 0;
}

double ascii_to_float(char s[]) {
  double result = 0.0;
  int decimal_place = 0;
  int i = 0;
  int is_negative = 0;
  
  if (s[0] == '-') {
    is_negative = 1;
    i = 1;
  }
  
  while (s[i] != '\0') {
    if (s[i] == '.') {
      decimal_place = 1;
      i++;
      continue;
    }
    
    if (is_digit(s[i])) {
      result = result * 10.0 + (s[i] - '0');
      
      if (decimal_place > 0) {
        decimal_place *= 10;
      }
    }
    
    i++;
  }
  
  if (decimal_place > 1) {
    result = result / decimal_place;
  }
  
  if (is_negative)
    result = -result;
  
  return result;
}

double push(double f){
  if (sp < MAXVAL)
    return (val[sp++] = f);
  else {
    printf("error: stack full\n");
    sp = 0;
    return 0;
  }
}

double pop(void){
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0;
  }
}

void clear(void){
  sp = 0;
}

