//Adham Hosam
#include <stdio.h>
typedef struct students_info{
    int roll;
    char name[20];
    float mark;
}info;
int main() {
    int i;
    info student[10];
    printf("Enter information of students\n");
    for ( i = 0; i <10 ; ++i) {
        student[i].roll=i+1;
        printf("For roll number %d\n",student[i].roll);
        printf("Enter name:");
        scanf("%s",student[i].name);
        printf("Enter mark:");
        scanf("%f",&student[i].mark);
    }
    printf("Displaying information of students:\n");
    for ( i = 0; i <10 ; ++i) {
        printf("\nInformation for roll number %d\n",i+1);
        printf("\nName: %s",student[i].name);
        printf("\nMark: %.2f",student[i].mark);
    }
    return 0;
}
