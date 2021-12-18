#include <stdio.h>
//Adham Hosam
typedef struct complex{
    float real;
    float imag;
}complex;
struct complex add_complex(complex no1,complex no2);

int main() {
    complex no1,no2,sum;
    printf("For the first complex number\n");
    printf("Enter real and imaginary respectively:");
    scanf("%f %f",&no1.real,&no1.imag);
    printf("For the second complex number\n");
    printf("Enter real and imaginary respectively:");
    scanf("%f %f",&no2.real,&no2.imag);
    sum=add_complex(no1,no2);
    printf("Sum=%.2f+%.2fi",sum.real,sum.imag);
    return 0;
}
complex add_complex(complex no1,complex no2){
    complex sum;
    sum.real=no1.real+no2.real;
    sum.imag=no1.imag+no2.imag;
    return (sum);
}
