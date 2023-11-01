//Adham_Hosam
//C Program to check whether a number is positive or negative
#include <stdio.h>

int main() {
    float x;
    printf("Enter a number,please:");
    scanf(" %f", &x);
    if (x>0)
    {
        printf("%f is positive",x);
    }
    else if (x<0)
    {
        printf("%f is negative",x);
    }
    else
    {
        printf("You entered zero");
    }


    return 0;
}
