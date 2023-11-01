#include <stdio.h>
//Program to find the average of n elements
//Adham Hosam

int main() {
   float a[100],sum=0,average;
   int n,i;
    printf("Enter no.of data:");
    scanf(" %d", &n);
    for ( i = 0; i <n ; ++i) {
        printf("%d.Enter number:",i+1);
        scanf("%f", &a[i]);
        sum+=a[i];
    }
    average=sum/n;
    printf("Average =%.2f",average);


    return 0;
}
