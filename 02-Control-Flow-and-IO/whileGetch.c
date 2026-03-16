#include<stdio.h>
int main()
{
char ch;
ch=getchar();
printf("enter a char:");
while(ch!='\n')
{
    printf("upper case letter is:");
    putchar(toupper(ch));
    fflush(stdin);
    ch=getchar();
}
}
