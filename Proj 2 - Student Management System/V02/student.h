/*
 * student.h
 *
 *  Created on: Nov 19, 2023
 *      Author: adham
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Platform_Types.h"
#include "fifo.h"

#define FILE_NAME   "StudentData.text"
#define MAX_STUDENTS 50

typedef struct sinfo{

    uint8 Fname[50];
    uint8 Lname[50];
    uint32 Id;
    float32 GPA;
    uint32 Courses[10];
}StudentInfo;

void Add_Students_Manually(struct buf* studentFIFO);
void Show_All_Students(struct buf* studentFIFO);
void Find_Id();
void Find_Fname();
void Find_Courses();
void Find_Total();
void Delete_Student();
void Update_Student();


#endif /* STUDENT_H_ */
