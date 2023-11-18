/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************			student.h				***************/
/**************************************************************/
/**************************************************************/

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Platform_Types.h"


// Structure to hold data about a student
struct SData {
	uint32 id;         // Student ID
    uint8 name[40];    // Student name 
    float32 height;    // Student height
};

// Structure to represent a student in a linked list
struct SStudent {
    struct SData Student;	// Student data
    struct SStudent* PNextStudent;	// Pointer to the next student in the list
};

// Global pointer to the first student in the list
extern struct SStudent* gpFirstStudent;

// Function prototypes
uint32 add_student();
uint32 delete_student();
void view_students();
void delete_all();
uint32 Get_Index();
uint32 Find_len();
uint32 Get_node_from_the_last();
void Get_middle();
void reverse_nodes();

#endif /* STUDENT_H_ */
