//Adham_Hosam
//C Program to find the largest number among three numbers
#include <stdio.h>

int main() {
   float x,y,z,max;
   printf("Enter the three number,please:");
   scanf(" %f %f %f",&x,&y,&z);
   max=x;
   if(y>max)
   {
       printf("Largest number is:%f",y);
   }
   else if(z>max)
   {
       printf("Largest number is:%f",z);
   }
   else
   {
       printf("Largest number is:%f",x);
   }

    return 0;
}
