//Adham_Hosam
//C Program to find factorial of a number
#include <stdio.h>

int main() {
    int x,fact=1;
    printf("Enter and integer");
    scanf(" %d", &x);
    if (x<0)
    {
        printf("Error! factorial of negative number doesn't exist");
    }
    else
    {
        for (int i = 1; i <= x; ++i) {
            fact *= i;
        }
        printf("Factorial = %d",fact);
    }
    return 0;
}
