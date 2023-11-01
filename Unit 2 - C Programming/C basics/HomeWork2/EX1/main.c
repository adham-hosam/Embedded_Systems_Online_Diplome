//Adham_Hosam
//C Program to check whether a number is even or odd
#include <stdio.h>

int main() {
    int x;
    printf("Enter an integer number you want to check:");
    scanf("%d", &x);
    if( x%2 ==0)
    {
        printf("%d is even",x);
    }
    else if ( x%2 !=0)
    {
        printf("%d is odd",x);
    }
    return 0;
}
