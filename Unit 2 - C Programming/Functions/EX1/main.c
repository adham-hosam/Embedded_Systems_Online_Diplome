#include <stdio.h>
int prime_checker (int num)
{
    int j,z=0;
    for (j=2;j<=num/2;j++){
        if(num%j==0) {
            z++;
            break;
        }
    }
    return z;
}

int main() {
    int n1,n2,i,check;
    printf("Enter two numbers intervals:");
    scanf("%d %d",&n1,&n2);
    printf("Prime numbers between %d and %d is:",n1,n2);
    for ( i = n1+1; i <n2 ; ++i) {
        check= prime_checker(i);
        if(check==0)
            printf("%d ",i);
    }

    return 0;
}
