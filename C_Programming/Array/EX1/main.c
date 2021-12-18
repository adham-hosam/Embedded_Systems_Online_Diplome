#include <stdio.h>
//Adham Hosam
//C program to find the sum of tw2 matrix or order 2*2


int main() {
   float a[2][2],b[2][2];
   int i,j;
    printf("Enter the elements of the 1st matrix\n");
    for ( i = 0; i <2 ; ++i) {
        for ( j = 0; j <2 ; ++j) {
            printf("Enter a%d%d:",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    printf("Enter the elements of the 2nd matrix\n");
    for ( i = 0; i <2 ; ++i) {
        for ( j = 0; j <2 ; ++j) {
            printf("Enter b%d%d:",i+1,j+1);
            scanf("%f",&b[i][j]);
        }
    }
    printf("The summation of the two matrix is:\n");
    for ( i = 0; i <2 ; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("%f ",a[i][j]+b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
