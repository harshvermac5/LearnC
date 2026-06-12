#include <stdio.h>

cust_strlen(char *s){
	char *p = s;
	while (*p != '\0')
		p++;
	return (p-s);
}
