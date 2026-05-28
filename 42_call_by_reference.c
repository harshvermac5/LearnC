#include <stdio.h>

void one(int op){
	int tn = 10;
	printf("one op before %d\n", op);
	op = op - tn;
	printf("one op after %d\n", op);
}

int main(){
	int ma = 42;
	printf("main ma before %d\n", ma);
	one(ma);
	printf("main ma before %d\n", ma);
}

