
#include "stdio.h"
#include "stdlib.h"


#include "student.h"

int main(){

    uint32 choice;
    while (1) {
        printf("\nChoose from the following options\n");
        printf("\n1. Add student\n");
        printf("\n2. View students\n");
        printf("\n3. Delete student\n");
        printf("\n4. Delete all\n");
        printf("\n5. Get index\n");
        printf("\n6. Find length\n");
        printf("\n7. Find node from the end\n");
        printf("\n8. Find the middle\n");
        printf("\n9. Reverse the nodes\n");
        printf("\n10. End process\n");
        printf("\nEnter option number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                delete_all();
                break;
            case 5:
                Get_Index();
                break;
            case 6:
                Find_len();
                break;
            case 7:
                Get_node_from_the_last();
                break;
            case 8:
                Get_middle();
                break;
            case 9:
                reverse_nodes();
                break;
            case 10:
                exit(1);
            default:
                printf("Wrong choice");
                break;
        }
    }

    return 0;
}

