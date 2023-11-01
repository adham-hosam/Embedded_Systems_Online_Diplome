#include <stdio.h>
#include <string.h>
//C program to reverse string without using library function
//Adham Hosam

int main() {
    char s[100];
    int i,count=0;
    printf("Enter the string:");
    gets(s);
    count= strlen(s);
    printf("Reverse of the string is:");
    for ( i=(count-1);i>=0;i--) {
        printf("%c",s[i]);
    }

    return 0;
}
