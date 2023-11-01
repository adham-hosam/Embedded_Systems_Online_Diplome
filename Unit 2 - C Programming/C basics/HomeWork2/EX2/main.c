//Adham_Hosam
//C Program to check vowel or consonant
#include <stdio.h>

int main() {
    char c;
    printf("Enter an alphabet you want to check:");
    scanf(" %c", &c);
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        {
            printf("%c is a vowel",c);
        }
            break;
        default:
            printf("%c is consonant",c);
    }
    return 0;
}
