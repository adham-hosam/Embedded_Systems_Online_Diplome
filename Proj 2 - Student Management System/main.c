
#include "Platform_Types.h"
#include <stdio.h>
#include <stdlib.h>

#include "student.h"

int main(){

    uint32 choice;
    while(1) {
        printf("\n1. Add Student Manually\n");
        printf("2. Add Student from File\n");
        printf("3. Find by ID\n");
        printf("4. Find by First Name\n");
        printf("5. Find by Courses\n");
        printf("6. Find Total\n");
        printf("7. Delete Student\n");
        printf("8. Update Student\n");
        printf("9. Show All Students\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student_manually();
                break;
            case 2:
                //add_student_file();
                break;
            case 3:
                find_Id();
                break;
            case 4:
                find_fname();
                break;
            case 5:
                find_courses();
                break;
            case 6:
                find_total();
                break;
            case 7:
                del_student();
                break;
            case 8:
                update_student();
                break;
            case 9:
                show_all_students();
                break;
            case 10:
                exit(1);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}