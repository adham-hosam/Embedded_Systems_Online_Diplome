#include <stdio.h>
//Transpose a matrix entered by user
//Adham Hosam

int main() {
    int a[100][100],t[100][100],r,c,i,j;
    printf("Enter no of rows and columns:");
    scanf("%d %d",&r,&c);
    printf("Enter elements of matrix:\n");
    for ( i = 0; i <r ; ++i) {
        for ( j = 0; j <c ; ++j) {
            printf("Enter element a%d%d:",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Entered matrix:\n");
    for ( i = 0; i <r ; ++i) {
        for ( j = 0; j <c ; ++j) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for ( i = 0; i <r ; ++i) {
        for ( j = 0; j <c ; ++j) {
            t[j][i]=a[i][j];
        }
    }

    printf("Transpose of matrix:\n");
    for ( i = 0; i <c ; ++i) {
        for ( j = 0; j <r ; ++j) {
            printf("%d ",t[i][j]);
        }
        printf("\n");

    }


    return 0;
}
