//Adham Hosam
#include <stdio.h>
#define area(r)((3.14)*r*r)
int main() {
    float radius,area;
    printf("Enter the radius:");
    scanf(" %f",&radius);
    area= area(radius);
    printf("Area= %.2f",area);
    return 0;
}
