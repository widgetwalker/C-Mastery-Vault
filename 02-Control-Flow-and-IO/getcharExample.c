#include<stdio.h>


int main(){
    char a[10];
    printf("Enter a character: ");
    fgets(a, sizeof(a), stdin);
    if (isalpha(a[0])){
        printf("Character is an alphabet");
    } else if (isalnum(a[0])){
        printf("Character is alphanumeric");
    } else {
        printf("Character is a special character");
