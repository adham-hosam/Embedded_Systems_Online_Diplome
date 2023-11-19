

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Platform_Types.h"

#define MAX_STUDENTS 50
#define FILENAME "student_database.txt"

struct sinfo {
    uint8 Fname[50];
    uint8 Lname[50];
    uint32 Id;
    float32 GPA;
    uint32 courses[10];
};

void add_student_manually();
void add_student_file();
void find_Id();
void find_fname();
void find_courses();
void find_total();
void del_student();
void update_student();
void show_all_students();

#endif /* STUDENT_H_ */