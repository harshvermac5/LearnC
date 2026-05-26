#include <stdio.h>
int main(){
        int guess;
        while(scanf("%d",&guess) != EOF){
                if (guess == 42){
                        printf("Nice Work!\n");
                        break;
                }       
                else if (guess < 42)
                        printf("Too low - guess again\n");
                else
                        printf("Too high - guess again\n");
        }        
}       

/* else if breaks the code into two parts, unlike python's single block of 
code */

