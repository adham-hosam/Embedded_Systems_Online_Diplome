
#include "Platform_Types.h"
#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void write_student(struct sinfo student) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fwrite(&student, sizeof(struct sinfo), 1, file);
    fclose(file);
}

static uint32 is_id_unique(uint32 id) {
    struct sinfo student;
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 1; // Assuming the file doesn't exist, ID is unique
    }

    while (fread(&student, sizeof(struct sinfo), 1, file) == 1) {
        if (student.Id == id) {
            fclose(file);
            return 0; // ID already exists
        }
    }

    fclose(file);
    return 1; // ID is unique
}

static void show_student(struct sinfo student) {
    printf("First Name: %s\n", student.Fname);
    printf("Last Name: %s\n", student.Lname);
    printf("ID: %d\n", student.Id);
    printf("GPA: %.2f\n", student.GPA);
    printf("Courses: ");
    for (uint32 i = 0; i < 10 && student.courses[i] != -1; ++i) {
        printf("%d ", student.courses[i]);
    }
    printf("\n");
}

void add_student_manually() {
    struct sinfo newStudent;

    do {
        printf("Enter ID: ");
        scanf("%d", &newStudent.Id);

        if (!is_id_unique(newStudent.Id)) {
            printf("Error: ID %d already exists. Please choose a different ID.\n", newStudent.Id);
        }
    } while (!is_id_unique(newStudent.Id));

    printf("Enter First Name: ");
    scanf("%s", newStudent.Fname);
    printf("Enter Last Name: ");
    scanf("%s", newStudent.Lname);
    printf("Enter GPA: ");
    scanf("%f", &newStudent.GPA);

    printf("Enter up to 10 course IDs (end input with -1):\n");
    uint32 i = 0, courseId;
    do {
        scanf("%d", &courseId);
        if (courseId != -1 && i < 10) {
            newStudent.courses[i++] = courseId;
        }
    } while (courseId != -1);

    // Fill the rest of the array with -1 to mark the end
    for (; i < 10; ++i) {
        newStudent.courses[i] = -1;
    }

    write_student(newStudent);
}

void show_all_students() {
    struct sinfo student;
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\nAll Students:\n");
    while (fread(&student, sizeof(struct sinfo), 1, file) == 1) {
        show_student(student);
        printf("--------------\n");
    }

    fclose(file);
}

void find_Id() {
    uint32 targetId;
    printf("Enter ID to search for: ");
    scanf("%d", &targetId);

    struct sinfo student;
    uint32 found = 0;

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fread(&student, sizeof(struct sinfo), 1, file) == 1) {
        if (student.Id == targetId) {
            show_student(student);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Student with ID %d not found.\n", targetId);
    }
}

void find_fname() {
    uint8 targetFirstName[50];
    printf("Enter First Name to search for: ");
    scanf("%s", targetFirstName);

    struct sinfo student;
    uint32 found = 0;

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\nStudents with First Name %s:\n", targetFirstName);

    while (fread(&student, sizeof(struct sinfo), 1, file) == 1) {
        if (strcmpi(student.Fname, targetFirstName) == 0) {
            show_student(student);
            printf("\n");
            found = 1;
        }
    }

    fclose(file);

    if (!found) {
        printf("No students found with First Name %s.\n", targetFirstName);
    }
}

void find_courses() {
    uint32 targetCourseId;
    printf("Enter Course ID to search for: ");
    scanf("%d", &targetCourseId);

    struct sinfo student;
    uint32 found = 0;

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\nStudents enrolled in Course ID %d:\n", targetCourseId);

    while (fread(&student, sizeof(struct sinfo), 1, file) == 1) {
        for (uint32 i = 0; i < 10 && student.courses[i] != -1; ++i) {
            if (student.courses[i] == targetCourseId) {
                show_student(student);
                printf("\n");
                found = 1;
                break;  // Break the loop once a match is found for this student
            }
        }
    }

    fclose(file);

    if (!found) {
        printf("No students found enrolled in Course ID %d.\n", targetCourseId);
    }
}

void find_total() {
    struct sinfo student;
    uint32 totalStudents = 0;

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fread(&student, sizeof(struct sinfo), 1, file) == 1) {
        totalStudents++;
    }

    fclose(file);

    uint32 remainingPlaces = MAX_STUDENTS - totalStudents;

    printf("\nTotal number of students: %d\n", totalStudents);
    printf("Remaining places to add more students: %d\n", remainingPlaces);
}

void del_student() {
    uint32 targetId;
    printf("Enter ID of the student to delete: ");
    scanf("%d", &targetId);

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    FILE *tempFile = fopen("temp_database.txt", "w");
    if (tempFile == NULL) {
        fclose(file);
        printf("Error creating temporary file!\n");
        exit(1);
    }

    struct sinfo student;
    uint32 found = 0;

    while (fread(&student, sizeof(struct sinfo), 1, file) == 1) {
        if (student.Id == targetId) {
            found = 1;
            printf("Student with ID %d deleted.\n", targetId);
        } else {
            fwrite(&student, sizeof(struct sinfo), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp_database.txt", FILENAME);

    if (!found) {
        printf("Student with ID %d not found.\n", targetId);
    }
}

void update_student() {
    uint32 targetId;
    printf("Enter ID of the student to update: ");
    scanf("%d", &targetId);

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    FILE *tempFile = fopen("temp_database.txt", "w");
    if (tempFile == NULL) {
        fclose(file);
        printf("Error creating temporary file!\n");
        exit(1);
    }

    struct sinfo student;
    uint32 found = 0;

    while (fread(&student, sizeof(struct sinfo), 1, file) == 1) {
        if (student.Id == targetId) {
            found = 1;
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
                    scanf("%s", student.Fname);
                    break;
                case 2:
                    printf("Enter new Last Name: ");
                    scanf("%s", student.Lname);
                    break;
                case 3:
                    printf("Enter new ID: ");
                    scanf("%d", &student.Id);
                    break;
                case 4:
                    printf("Enter new GPA: ");
                    scanf("%f", &student.GPA);
                    break;
                case 5:
                    printf("Enter new courses (end input with -1):\n");
                    uint32 i = 0, courseId;
                    do {
                        scanf("%d", &courseId);
                        if (courseId != -1 && i < 10) {
                            student.courses[i++] = courseId;
                        }
                    } while (courseId != -1);

                    // Fill the rest of the array with -1 to mark the end
                    for (; i < 10; ++i) {
                        student.courses[i] = -1;
                    }
                    break;
                default:
                    printf("Invalid choice. No updates performed.\n");
            }
        }

        fwrite(&student, sizeof(struct sinfo), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp_database.txt", FILENAME);

    if (!found) {
        printf("Student with ID %d not found.\n", targetId);
    } else {
        printf("Student with ID %d updated successfully.\n", targetId);
    }
}