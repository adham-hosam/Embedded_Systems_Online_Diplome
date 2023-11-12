/* Write a program in C to print all the alphabets using a pointer. Go
        to the editor */
#include <stdio.h>

#define AlphaNum    26

int main()
{
   int first = 'A';
    int i = first;
    int *ptr = &i;
    for ( ;i <first+AlphaNum ; ++i) {
        printf("%c ",*ptr);
    }

    return 0;
}