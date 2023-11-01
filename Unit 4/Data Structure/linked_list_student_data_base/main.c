
#include <stdio.h>
#include <stdlib.h>
struct SData{
    unsigned int id;
    char name[40];
    float height;
};
struct SStudent{
    struct SData Student;
    struct SStudent* PNextStudent;
};
struct SStudent* gpFirstStudent=NULL;
int add_student(){
    struct SStudent* pNewStudent;
    struct SStudent* pLastStudent;
    if(gpFirstStudent == NULL)                       //checking if the list is empty
    {
        //empty list
        pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
        gpFirstStudent = pNewStudent;
        pNewStudent->PNextStudent = NULL;
    }
        //list contains data
    else
    {
        pLastStudent = gpFirstStudent;
        while(pLastStudent->PNextStudent != NULL)    //to reach the last record
        {
            pLastStudent = pLastStudent->PNextStudent;
        }
        pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
        pLastStudent->PNextStudent = pNewStudent;
        pNewStudent->PNextStudent = NULL;
    }
    //fill the data
    struct SStudent* pCurrentStudent = gpFirstStudent;
        printf("\nEnter the ID:");
        scanf("%d", &pNewStudent->Student.id);
        while (pCurrentStudent->PNextStudent) {                   //check if the ID is already exist
            if (pNewStudent->Student.id == pCurrentStudent->Student.id) {
                printf("\n====== ID is already exist ======\n");
                return 1;
            }
            else
            {
                pCurrentStudent = pCurrentStudent->PNextStudent;
            }
        }
    printf("\nEnter the student name: ");
    //gets(pNewStudent->Student.name);
    scanf("%s",pNewStudent->Student.name);

    printf("\nEnter the height:");
    scanf("%f",&pNewStudent->Student.height);
    //set the last pointer to NULL
    pNewStudent->PNextStudent = NULL;
    return 0;
}
int delete_student(){
    unsigned int selected_id,count=0;
    if(gpFirstStudent != NULL)      //checking if the list is empty
    {
        printf("\nEnter the student ID to be erased:");
        scanf("%d",&selected_id);
        struct SStudent* pSelectedStudent = gpFirstStudent;
        struct SStudent* pPreviousStudent = NULL;
        while (pSelectedStudent)
        {
            if(pSelectedStudent->Student.id == selected_id)
            {
                if(pPreviousStudent)        //the selected ID isn't the first student
                {
                    pPreviousStudent = pSelectedStudent->PNextStudent;
                }
                else
                {
                    gpFirstStudent = pSelectedStudent->PNextStudent;
                }
                free(pSelectedStudent);
                return 1;
            }
            else         //if the ID isn't found
                count++;
            pPreviousStudent = pSelectedStudent;
            pSelectedStudent = pSelectedStudent->PNextStudent;
        }
    }
    else
        printf("\n====== The list is already empty ======\n");
    if(count>0)
        printf("\n======== can't find the student ID ========\n");

    return 0;
    
}
void view_students(){
    int count=0;
    struct SStudent* pCurrentStudent = gpFirstStudent;
    if( gpFirstStudent == NULL)
        printf("\n\t========== List is empty ==========\t\n");

    while(pCurrentStudent)      //looping the all nodes
    {
        printf("\n\t=================\n");
        printf("\nRecord name: %d",count+1);
        printf("\nID: %d",pCurrentStudent->Student.id);
        printf("\nName: %s",pCurrentStudent->Student.name);
        printf("\nHeight: %.2f\n",pCurrentStudent->Student.height);
        pCurrentStudent = pCurrentStudent->PNextStudent;
        count++;
        printf("\n\t=================\n");

    }
}
void delete_all(){
    struct SStudent* pCurrentStudent = gpFirstStudent;
    if(gpFirstStudent == NULL)
        printf("\n========= The list is already empty =========\n");
    while(pCurrentStudent)
    {
        struct SStudent* pTemp = pCurrentStudent;
        pCurrentStudent = pCurrentStudent->PNextStudent;
        free(pTemp);
    }
    gpFirstStudent = NULL;
}
int Get_Index(){
    struct SStudent * pCurrentStudent = gpFirstStudent;
    int count = 0 , index;
    if(gpFirstStudent == NULL)
    {
        printf("\n========= The list is already empty =========\n");
        return 1;
    }
    printf("\nEnter the index to be viewed:");
    scanf("%d", &index);
    while (pCurrentStudent) {
            if (count == index) {
                printf("\n\t=================\n");
                printf("\nID: %d", pCurrentStudent->Student.id);
                printf("\nName: %s", pCurrentStudent->Student.name);
                printf("\nHeight: %.2f\n", pCurrentStudent->Student.height);
                printf("\n\t=================\n");
            }
            count++;
            pCurrentStudent = pCurrentStudent->PNextStudent;
        }
    return 0;
}
int Find_len(){
    struct SStudent * pCurrentStudent = gpFirstStudent;
    int len=0 ;
    if(gpFirstStudent == NULL) {
        printf("\n========= The list is already empty =========\n");
        return 1;
    }
    while (pCurrentStudent){
        len++;
        pCurrentStudent = pCurrentStudent->PNextStudent;
    }
    printf("\n%d\n",len);

    return 0;
}
int Get_node_from_the_last(){
    struct SStudent* pRefStudent = gpFirstStudent;
    struct SStudent* pCurrentStudent = gpFirstStudent;
    int node_number;
    if(gpFirstStudent == NULL) {
        printf("\n========= The list is already empty =========\n");
        return 1;
    }
    printf("\nEnter the n'th node from the end to be viewed: ");
    scanf("%d",&node_number);
    for (int i = 1; i <=node_number ; ++i) {
        pRefStudent = pRefStudent->PNextStudent;
    }
    while (pRefStudent){
        pCurrentStudent = pCurrentStudent->PNextStudent;
        pRefStudent = pRefStudent->PNextStudent;
    }
    printf("\n\t=================\n");
    printf("\nID: %d",pCurrentStudent->Student.id);
    printf("\nName: %s",pCurrentStudent->Student.name);
    printf("\nHeight: %.2f\n",pCurrentStudent->Student.height);
    return 0;
}
void Get_middle(){
    struct SStudent* pFast = gpFirstStudent;
    struct SStudent* pCurrentStudent = gpFirstStudent;
    while (pFast != NULL && pFast->PNextStudent != NULL){
        pFast = pFast->PNextStudent->PNextStudent;
        pCurrentStudent = pCurrentStudent->PNextStudent;
    }
    printf("\n\t=================\n");
    printf("Middle node data is\n");
    printf("\nID: %d",pCurrentStudent->Student.id);
    printf("\nName: %s",pCurrentStudent->Student.name);
    printf("\nHeight: %.2f\n",pCurrentStudent->Student.height);
}
void reverse_nodes(){
    struct SStudent* pCurrent = gpFirstStudent;
    struct SStudent* pNext = NULL;
    struct SStudent* pPrevious = NULL;
    if(gpFirstStudent == NULL)
        printf("\n========= The list is already empty =========\n");
    else {
        while (pCurrent) {
            pNext = pCurrent->PNextStudent;
            pCurrent->PNextStudent = pPrevious;
            pPrevious = pCurrent;
            pCurrent = pNext;
        }
        gpFirstStudent = pPrevious;
    }
}
int main() {
    int choice;
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
}
