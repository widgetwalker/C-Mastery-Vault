#include<stdio.h>
int main(){
    char c;
    printf("Enter a character: ");
    c = getchar();
    if (isalpha(c)){
        if (isupper(c)){
            printf("Converted character: %c\n", tolower(c));
        } else {
            printf("Converted character: %c\n", toupper(c));
        }
    } else if (isdigit(c)) {
        printf("Character is a number: %c\n", c);
    } else {
        printf("It is a special character");
    }
    return 0;
}
