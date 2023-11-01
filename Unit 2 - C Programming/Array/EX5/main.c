#include <stdio.h>
//C program to search an element in array
// Adham Hosam

int main() {
    int a[50],n,i,num,l;
    printf("Enter no.of element:");
    scanf("%d",&n);
    l=n;
    printf("Enter the elements:");
    for ( i = 0; i <n ; ++i) {
        scanf("%d", &a[i]);
    }
    printf("Enter the elements to be searched:");
    scanf("%d",&num);
    for ( i = 0; i <n ; ++i) {

        if(num==a[i])
        {
            printf("Number found at the location=%d",(n-l)+1);
            break;
        }
        else
        {
            l--;
        }

    }







    return 0;
}
