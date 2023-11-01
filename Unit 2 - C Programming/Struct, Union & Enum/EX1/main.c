//Adham Hosam
#include <stdio.h>
struct Sinfo {
    char name[10];
    int roll_number;
    float mark;
};
int main() {
    struct Sinfo student;
    printf("Enter information of students\n");
    printf("Enter the name: ");
    scanf("%s",student.name);
    printf("\nEnter roll number: ");
    scanf("%d",&student.roll_number);
    printf("\nEnter the mark: ");
    scanf("%f",&student.mark);
    printf("\nDisplaying information\n");
    printf("name: %s\nRoll: %d\nMark: %f",student.name,student.roll_number,student.mark);
    return 0;
}
