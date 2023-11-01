#include <stdio.h>
//Adham Hosam
//C program to calculate factorial of a number using recursion
int factorial(int num){
    int fact=1,i;
    for ( i = 1; i <=num ; ++i) {
        fact*=i;
    }
    return fact;
}

int main() {
    int num;
    printf("Enter the number:");
    scanf(" %d",&num);
    printf("Factorial of %d is :%d", num ,factorial(num));
    return 0;
}
