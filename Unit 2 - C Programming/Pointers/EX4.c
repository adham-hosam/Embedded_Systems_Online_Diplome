/* Write a program in C to print the elements of an array in reverse
order. */

#include <stdio.h>

int main()
{
    char data[15];
    int elementsNum = 0;

    printf("Input the number of elements to store in the array (max 15):");
    scanf("%d", &elementsNum);

    printf("Input %d number of elements in the array :\n",elementsNum);
    for (int i = 0; i <elementsNum ; ++i) {
        printf("element - %d:",i+1);
        scanf("%d",&data[i]);
    }

    printf("The elements of array in reverse order are :\n");
    for (int i = elementsNum-1; i >= 0 ; --i) {
        printf("element - %d : %d\n",i+1 , data[i]);
    }
    
    return 0;
}
