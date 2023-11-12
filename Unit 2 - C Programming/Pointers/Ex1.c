/* Write a program in C to demonstrate how to handle the pointers
in the program.*/
#include <stdio.h>

int main()
{
    int m = 29;
    int* ab =&m;
    printf("m = %d , m address =%p\n",m,&m);
    printf("*ab = %d , p =%p\n",*ab,ab);

    m=34;
    printf("*ab = %d , p =%p\n",*ab,ab);

    *ab = 7;
    printf("m = %d , m address =%p\n",m,&m);

    return 0;
}
