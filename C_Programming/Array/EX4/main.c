#include <stdio.h>
//C program to insert an element in an array
//Adham Hosam

int main() {
    int a[10],i,n,x,p;
    printf("Enter number of elements:");
    scanf("%d",&n);
    for ( i = 0; i <n ; ++i) {
        printf("%d.Enter the element:",i+1);
        scanf("%d",&a[i]);
    }
    printf("The entered elements are:\n");
    for ( i = 0; i <n ; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("Enter the element to be inserted:");
    scanf("%d",&x);
    printf("Enter the position");
    scanf("%d",&p);
    a[p-1]=x;
    for ( i = 0; i <n ; ++i) {
        printf("%d ",a[i]);
    }
    return 0;
}
