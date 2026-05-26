#include <stdio.h>
int main() {
        char line[10000];
        FILE *hand;
        hand = fopen("Intraproboscis.txt", "r");
        while( fgets(line, 10000, hand) != NULL ); {
                        printf("%s", line);
	}
}
