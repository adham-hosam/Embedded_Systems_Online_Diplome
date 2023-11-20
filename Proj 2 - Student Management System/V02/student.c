

#include "Platform_Types.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "student.h"

typedef enum {

    ID_Not_Found,
    ID_Found

}ID_Status;

static void ReadStudent(StudentInfo newStudent){
    printf("First Name: %s\n",newStudent.Fname);
    printf("Last Name: %s\n",newStudent.Lname);
    printf("ID: %d\n",newStudent.Id);
    printf("GPA %.2f\n",newStudent.GPA);
    printf("Courses ID: ");
    for(int i = 0 ; i < 10 && newStudent.Courses[i] != -1 ; i++){
        printf("%d ", newStudent.Courses[i] );
    }
    printf("\n");
}

static void WriteStudent(StudentInfo newStudent){

    FILE *file = fopen(FILE_NAME , "a");
    if(file == NULL){
        printf("Can't Open File!\n");
        exit(1);
    }

    fwrite(&newStudent , sizeof(newStudent), 1 , file );
    fclose(file);
}

static ID_Status IsIDUnique(uint32 id){
    StudentInfo newStudent;
    ID_Status checkID = ID_Not_Found;

    FILE *file = fopen(FILE_NAME , "r");
    if(file == NULL){
        checkID = ID_Not_Found;     // Assume the file doesn't exist yet
    }
    while(fread(&newStudent , sizeof(newStudent) , 1 , file ) == 1){
        if(newStudent.Id == id){
            checkID = ID_Found;
            fclose(file);
        }
    }
    fclose(file);

    return checkID;
}

void Add_Students_Manually(struct buf* studentFIFO){

    StudentInfo newStudent;
    uint8 i = 0;
    uint32 course;
    do {
        printf("Enter ID: ");
        scanf("%d",&newStudent.Id);
        if(IsIDUnique(newStudent.Id) == ID_Found){
            printf("Error, ID %d already taken, Please Enter unique ID\n",newStudent.Id);
        }
    } while (IsIDUnique(newStudent.Id) == ID_Found);

    printf("Enter First Name: ");
    scanf("%s",newStudent.Fname);
    printf("Enter Last Name: ");
    scanf("%s",newStudent.Lname);
    printf("Enter GPA: ");
    scanf("%f",&newStudent.GPA);
    printf("Enter the courses ID (end input with -1):\n");
    do {
        scanf("%d",&course);
        if( course != -1 && i <10 ) {
            newStudent.Courses[i++] = course;
        }
    }while(course != -1);

    for(; i <10 ; i++){
        newStudent.Courses[i] = -1;
    }
    FIFO_Status_t enqueueStatus =  FIFO_Enqueue(studentFIFO ,newStudent );
    if (enqueueStatus == FIFO_no_error) {
        printf("Student enqueued successfully!\n");
    } else if (enqueueStatus == FIFO_full) {
        printf("Error: FIFO is full. Unable to enqueue.\n");
    } else if (enqueueStatus == FIFO_null) {
        printf("Error: FIFO is not properly initialized (NULL).\n");
    }

    // Write data in external file
    WriteStudent(newStudent);
}

void Show_All_Students(FIFO_Buf_t* studentFIFO) {

    uint8 choice;

    printf("Choose where to read from:\n");
    printf("1.Read from FIFO\n");
    printf("2.Read from file\n");
    scanf("%d",&choice);

    if(choice == 1) {

        // Check if the FIFO is empty
        if (studentFIFO->count == 0) {
            printf("No students to display.\n");
            return;
        }
        // Temporary pointer to iterate through the FIFO
        StudentInfo *temp = studentFIFO->tail;

        printf("============== Students in FIFO  ==============\n");

        // Iterate through the FIFO and print each student
        for (uint32 i = 0; i < studentFIFO->count; i++) {
            printf("Student %d:\n", i + 1);
            ReadStudent(*temp);
            printf("--------------\n");
            temp++;
        }

    } else if(choice == 2){

        // Read students from file and enqueue them into the FIFO
        FILE *file = fopen(FILE_NAME, "r");
        if (file == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }

        StudentInfo newStudentFromFile;
        /*
        if(fread(&newStudentFromFile, sizeof(newStudentFromFile), 1, file) == 0) {
            printf("No students to display.\n");
            return;
        }*/
        printf("============== Students Data  ==============\n");
        while (fread(&newStudentFromFile, sizeof(struct sinfo), 1, file) == 1) {
            ReadStudent(newStudentFromFile);
            printf("--------------\n");
        }
        fclose(file);
    }
    else{
        printf("Wrong option!\n");
    }
}

void Find_Id() {

    StudentInfo newStudent;
    ID_Status checkID = ID_Not_Found;
    uint32 id;
    printf("Enter the ID for search: ");
    scanf("%d",&id);

    FILE *file = fopen(FILE_NAME , "r");

    while(fread(&newStudent , sizeof(newStudent) , 1 , file) == 1){
        if(newStudent.Id == id){
            ReadStudent(newStudent);
            checkID = ID_Found;
            break;
        }
    }
    fclose(file);

    if(!checkID){
        printf("Can't find ID %d\n",id);
    }
}

void Find_Fname(){
    StudentInfo newStudent;
    uint8 name[30];
    uint8 found = 0;

    printf("Enter the First Name for search\n");
    scanf("%s",name);

    FILE *file = fopen(FILE_NAME , "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while (fread(&newStudent , sizeof(newStudent), 1 , file) == 1){
        if(strcmpi(newStudent.Fname, name) == 0){
            ReadStudent(newStudent);
            printf("--------------\n");
            found = 1;
        }
    }
    if(!found){
        printf("No student with First Name '%s'\n",name);
    }
    fclose(file);
}

void Find_Courses(){
    StudentInfo newStudent;
    uint8 found = 0;

    uint32 course;
    printf("Enter the Courses for search:\n");
    scanf("%d",&course);

    FILE *file = fopen(FILE_NAME , "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("\nStudents enrolled in Course ID %d:\n", course);
    while (fread(&newStudent , sizeof(newStudent), 1 , file) == 1 ){
        for(int i = 0 ; i < 10 && newStudent.Courses[i] != -1 ; i++){
            if(newStudent.Courses[i] == course){
                ReadStudent(newStudent);
                printf("--------------\n");
                found = 1;
                break;
            }
        }
    }
    fclose(file);
    if(!found){
        printf("No students found enrolled in Course ID %d.\n" , course);
    }
}
void Find_Total(){

    StudentInfo newStudent;
    uint8 count = 0;

    FILE *file = fopen(FILE_NAME , "r");
    if(file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    while (fread(&newStudent , sizeof(newStudent) , 1 , file) == 1){
        count++;
    }
    fclose(file);

    if(count){
        printf("--------------\n");
        printf("Total number of enrolled students: %d\n",count);
        printf("Remaining places to add more students: %d\n", MAX_STUDENTS - count);
        printf("--------------\n");
    }
    else{
        printf("--------------\n");
        printf("There is no Students enrolled in the system");
        printf("--------------\n");
    }
}
void Delete_Student(){

    StudentInfo newStudent;
    ID_Status found = ID_Not_Found;

    uint32 id;
    printf("Enter the student ID to delete the data: ");
    scanf("%d",&id);

    FILE *file = fopen(FILE_NAME , "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    FILE *tempFile = fopen("temp_database.txt" , "w");
    if (tempFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while (fread(&newStudent , sizeof(newStudent) , 1 , file) == 1){
        if(newStudent.Id == id){
            found = ID_Found;
            printf("--------------\n");
            printf("Student with ID %d has been deleted.\n", id);
            printf("--------------\n");
        }
        else{
            fwrite(&newStudent , sizeof(newStudent) , 1 , tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp_database.txt" , FILE_NAME);
    if (!found) {
        printf("--------------\n");
        printf("Student with ID %d not found.\n", id);
        printf("--------------\n");
    }
}

void Update_Student(){

    StudentInfo newStudent;
    uint8 choice;
    uint32 id;
    ID_Status found = ID_Not_Found;

    printf("Enter ID of student to update: ");
    scanf("%d", &id);

    FILE *file = fopen(FILE_NAME , "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    FILE *tempFile = fopen("temp_database.txt" , "w");
    if (tempFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while (fread(&newStudent, sizeof(struct sinfo), 1, file) == 1) {
        if (newStudent.Id == id) {
            found = ID_Found;
            uint32 choice;
            printf("\nSelect the attribute to update:\n");
            printf("1. First Name\n");
            printf("2. Last Name\n");
            printf("3. ID\n");
            printf("4. GPA\n");
            printf("5. Courses\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter new First Name: ");
                    scanf("%s", newStudent.Fname);
                    break;
                case 2:
                    printf("Enter new Last Name: ");
                    scanf("%s", newStudent.Lname);
                    break;
                case 3:
                    printf("Enter new ID: ");
                    scanf("%d", &newStudent.Id);
                    break;
                case 4:
                    printf("Enter new GPA: ");
                    scanf("%f", &newStudent.GPA);
                    break;
                case 5:
                    printf("Enter new courses (end input with -1):\n");
                    uint32 i = 0, courseId;
                    do {
                        scanf("%d", &courseId);
                        if (courseId != -1 && i < 10) {
                            newStudent.Courses[i++] = courseId;
                        }
                    } while (courseId != -1);

                    // Fill the rest of the array with -1 to mark the end
                    for (; i < 10; ++i) {
                        newStudent.Courses[i] = -1;
                    }
                    break;
                default:
                    printf("Invalid choice. No updates performed.\n");
            }
        }

        fwrite(&newStudent, sizeof(struct sinfo), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp_database.txt", FILE_NAME);

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    } else {
        printf("Student with ID %d updated successfully.\n", id);
    }
}