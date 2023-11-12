/* Write a program in C to show a pointer to an array which contents
are pointer to structure. */

#include <stdio.h>


typedef struct{
    char EmployeeName[40];
    int EmployeeID;
}Date;

int main()
{
    Date s[2];


    printf("Enter the data of the employees:\n");
    for (int i = 0; i <2 ; ++i) {
        printf("Enter the name of employee %d:\n",i+1);
        scanf("%s",s[i].EmployeeName);
        printf("Enter the Id of employee %d:\n",i+1);
        scanf("%d",&s[i].EmployeeID);
    }
    for (int i = 0; i <2 ; ++i) {
        printf("Employee Name: %s\n",s[i].EmployeeName);
        printf("Employee ID: %d\n",s[i].EmployeeID);
    }


    return 0;
}
