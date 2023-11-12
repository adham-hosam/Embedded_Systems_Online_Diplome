/* Write a program in C to print a string in reverse using a pointer */

#include <stdio.h>
#include "string.h"

int main()
{
    char string[40];
    unsigned int size =0;
    printf("Enter a string to be reversed: ");
    gets(string);

    size = strlen(string);
    char *ptr = &string[size-1];

    printf("The string after reversion: ");
    for (int i = 0; i <size ; ++i) {
        printf("%c",*ptr--);
    }
    return 0;
}
