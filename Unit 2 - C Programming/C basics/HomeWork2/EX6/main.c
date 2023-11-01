//Adham_Hosam
//C Program to find factorial of a number
#include <stdio.h>

int main() {
    int x,sum=0;
    printf("Enter an integer:");
    scanf(" %d", &x);
    for (int i = 0; i <=x ; ++i) {
        sum+=i;
    }
    printf("sum = %d",sum);

    return 0;
}
