/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************			student.c				***************/
/**************************************************************/
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "student.h"

// Pointer to the first student in the linked list.
struct SStudent* gpFirstStudent = NULL;


static uint32 isIdExist(uint32 id) {
	// Start with the first student in the linked list
    struct SStudent* pCurrentStudent = gpFirstStudent;
	
	// Traverse the linked list
    while (pCurrentStudent != NULL) {
		// Check if the current student's ID matches the given ID
        if (id == pCurrentStudent->Student.id) {
            return 1; // ID exists
        }
		
		// Move to the next student in the linked list
        pCurrentStudent = pCurrentStudent->PNextStudent;
    }
    return 0; // ID does not exist
}

uint32 add_student() {
    struct SStudent* pNewStudent;
    struct SStudent* pLastStudent;

	// Allocate memory for the new student
    pNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));

	// Check if memory allocation is successful
    if (pNewStudent == NULL) {
        printf("\nMemory allocation failed.\n");
        return 1;	// Return 1 to indicate failure
    }
	
	// Input the ID for the new student
    printf("\nEnter the ID:");
    scanf("%u", &pNewStudent->Student.id);

    // Check if the ID already exists
    if (isIdExist(pNewStudent->Student.id)) {
        printf("\n====== ID is already exist ======\n");
        free(pNewStudent); // Free the allocated memory
        return 1;
    }

    printf("\nEnter the student name: ");
    scanf(" %[^\n]", pNewStudent->Student.name);

    printf("\nEnter the height:");
    scanf("%f", &pNewStudent->Student.height);
	
	// Set the next pointer to NULL
    pNewStudent->PNextStudent = NULL;

    if (gpFirstStudent == NULL) {
		// Empty list, the new student becomes the first
        gpFirstStudent = pNewStudent;
    } else {
        // List contains data, find the last student and append the new student
        pLastStudent = gpFirstStudent;
        while (pLastStudent->PNextStudent != NULL) {
            pLastStudent = pLastStudent->PNextStudent;
        }
        pLastStudent->PNextStudent = pNewStudent;
    }

    return 0;
}

uint32 delete_student() {

    uint32 selected_id,count=0;
	
	//checking if the list is empty
    if(gpFirstStudent != NULL)      
    {
		// Input the ID to be deleted
        printf("\nEnter the student ID to be erased:");
        scanf("%d",&selected_id);
        struct SStudent* pSelectedStudent = gpFirstStudent;
        struct SStudent* pPreviousStudent = NULL;
		
		// Traverse the list
        while (pSelectedStudent)
        {
			
			// Check if the selected ID is found
            if(pSelectedStudent->Student.id == selected_id)
            {
				//the selected ID isn't the first student
                if(pPreviousStudent)        
                {
                    pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
                }
				// If the selected ID is the first student
                else
                {
                    gpFirstStudent = pSelectedStudent->PNextStudent;
                }
				
				// Free the memory for the selected student
                free(pSelectedStudent);
                printf("\n======== Student data has been deleted ========\n");
                return 1;
            }
            else         //if the ID isn't found
                count++;
            pPreviousStudent = pSelectedStudent;
            pSelectedStudent = pSelectedStudent->PNextStudent;
        }

    }
    else
        printf("\n======== The list is already empty ========\n");
    if(count>0)
        printf("\n======== can't find the student ID ========\n");

    return 0;
}

void view_students() {

    uint32 count=0;
    struct SStudent* pCurrentStudent = gpFirstStudent;
	
	// Check if the list is empty
    if( gpFirstStudent == NULL)
        printf("\n\t========== List is empty ==========\t\n");

	// Loop through all nodes
    while(pCurrentStudent)      
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

void delete_all() {

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

uint32 Get_Index() {

    struct SStudent * pCurrentStudent = gpFirstStudent;
    uint32 count = 0 , index;
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

uint32 Find_len() {

    struct SStudent * pCurrentStudent = gpFirstStudent;
    uint32 len=0 ;
    if(gpFirstStudent == NULL) {
        printf("\n========= The list is already empty =========\n");
        return 1;
    }
    while (pCurrentStudent){
        len++;
        pCurrentStudent = pCurrentStudent->PNextStudent;
    }
    printf("\nLength of the list = %d\n",len);

    return 0;
}

uint32 Get_node_from_the_last() {

    struct SStudent* pRefStudent = gpFirstStudent;
    struct SStudent* pCurrentStudent = gpFirstStudent;
    uint32 node_number;
    if(gpFirstStudent == NULL) {
        printf("\n========= The list is already empty =========\n");
        return 1;
    }
    printf("\nEnter the n'th node from the end to be viewed: ");
    scanf("%d",&node_number);
    for (uint32 i = 1; i <=node_number ; ++i) {
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

void Get_middle() {

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

void reverse_nodes() {

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


