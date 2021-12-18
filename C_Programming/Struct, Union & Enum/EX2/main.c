#include <stdio.h>
struct distance{
    int feet;
    float inch;
}dis1,dis2;
int main() {
    struct distance sum;
    float tot_sum;
    printf("Enter information of the first distance\n");
    printf("Enter feet:");
    scanf("%d",&dis1.feet);
    printf("Enter inch:");
    scanf("%f",&dis1.inch);
    printf("Enter information of the second distance\n");
    printf("Enter feet:");
    scanf("%d",&dis2.feet);
    printf("Enter inch:");
    scanf("%f",&dis2.inch);
    sum.feet=dis1.feet+dis2.feet;
    sum.inch=dis1.inch+dis2.inch;
    if (sum.inch>12.0){
        sum.inch=sum.inch-12.0;
        sum.feet++;
    }
    tot_sum=sum.inch+sum.feet;
    printf("sum of distance=%.2f feet",tot_sum);
    return 0;
}
