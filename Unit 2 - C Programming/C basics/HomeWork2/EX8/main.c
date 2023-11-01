//Adham_Hosam
//C Program to make simple calculator
#include <stdio.h>

int main() {
    float x,y;
    char oper;
    printf("Enter the operator symbol:");
    scanf(" %c", &oper);
    printf("Enter the two operands:");
    scanf("%f %f", &x,&y);
    switch (oper) {
        case '+':
        {
            printf("%f + %f = %f",x,y,x+y);
        }
        break;
        case '-':
        {
            printf("%f - %f = %f",x,y,x-y);
        }
        break;
        case '*':
        {
            printf("%f * %f = %f", x, y, x * y);
        }
        break;
        case '/':
        {
            printf("%f / %f = %f",x,y,x/y);
        }
        break;
        default:
            printf("Please enter a correct operation symbol");

    }
    return 0;
}
