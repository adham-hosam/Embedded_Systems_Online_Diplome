#include <stdio.h>
int power(int base ,int exp){
    int i,res=1;
    for ( i = 1; i <=exp ; ++i) {
        res*=base;

    }
    return res;
}
int main() {
    int n1,n2;
    printf("Enter the number:");
    scanf(" %d",&n1);
    printf("Enter the power:");
    scanf(" %d",&n2);
    printf("%d",power(n1,n2));

    return 0;
}

