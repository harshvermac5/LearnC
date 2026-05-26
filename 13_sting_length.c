#include <stdio.h>
int main(){
	char x[] = "hello";
	int py_len();
	printf("%s %d\n", x, py_len(x));
}

int py_len(self)
	char self[];
{
	int i;
	for (i=0; self[i]; i++);
	return i;
}

