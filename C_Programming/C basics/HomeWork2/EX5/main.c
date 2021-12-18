//Adham_Hosam
//C Program to check whether a character is alphabet or not
#include <stdio.h>

int main() {
    char c;
    printf("Enter a character:");
    scanf(" %c", &c);
    if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
    {
        printf("%c is alphabet",c);
    }
    else
    {
        printf("%c is not alphabet",c);
    }

    return 0;
}
