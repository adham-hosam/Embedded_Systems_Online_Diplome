#include <stdio.h>
#include <string.h>

//C program to find the frequency of characters in a string
//Adham Hosam

int main() {
    char str[100],ch;
    int count=0,i;
    printf("Enter a string:");
    gets(str);
    printf("Enter a character to find frequency:");
    scanf("%c",&ch);
    for ( i = 0; i <100 ; ++i) {
        if(ch == str[i])
        {
         count++;
        }
    }
    printf("Frequency of %c = %d",ch,count);
    return 0;
}
