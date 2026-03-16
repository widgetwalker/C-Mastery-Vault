#include<stdio.h>
int main(){
    char a;
    printf("Enter a word or a sentence (\n to quit): ");
    while ((a = getchar()) != '\n') {
        if (isalpha(a)){
            printf("Character %c is an alphabet\n",a);
        } else if (isdigit(a)){
            printf("Character %c is a number\n",a);
        } else {
            printf("character %c is a special character\n",a);
        }
    }
    return 0;
}
