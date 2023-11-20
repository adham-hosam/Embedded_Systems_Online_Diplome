// main.c
#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

int main() {
    uint8 choice;

    // Initialize FIFO for storing student data
    FIFO_Buf_t studentFIFO;
    StudentInfo studentBuffer[MAX_STUDENTS];
    if (FIFO_Init(&studentFIFO, studentBuffer, MAX_STUDENTS)  == FIFO_no_error){
        printf("FIFO Init ======== Done\n");
    }

    while (1) {
        printf("\nChoose an option from the list:\n");
        printf("1. Add Student Manually\n");
        printf("2. Show All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Search Student with First Name\n");
        printf("5. Search Students Enrolled in the Same Course ID\n");
        printf("6. Find Total Students\n");
        printf("7. Delete Student\n");
        printf("8. Update Student\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Add_Students_Manually(&studentFIFO);
                break;
            case 2:
                Show_All_Students(&studentFIFO);
                break;
            case 3:
                Find_Id();
                break;
            case 4:
                Find_Fname();
                break;
            case 5:
                Find_Courses();
                break;
            case 6:
                Find_Total();
                break;
            case 7:
                Delete_Student();
                break;
            case 8:
                Update_Student();
                break;
            case 9:
                printf("Exiting the program.\n");
                exit(1);
            default:
                printf("Wrong option!\n");
        }
    }
}
