#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float grades[10];
};

void inputGrades(struct Student students[], int numStudents, int numSubjects) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Enter grades for Math Science English History: ");
        for (int j = 0; j < numSubjects; j++) {
            scanf("%f", &students[i].grades[j]);
        }
    }
    printf("Grades successfully entered!\n");
}

void calculateAverage(struct Student students[], int numStudents, int numSubjects) {
    for (int i = 0; i < numStudents; i++) {
        float sum = 0;
        for (int j = 0; j < numSubjects; j++) {
            sum += students[i].grades[j];
        }
        float average = sum / numSubjects;
        printf("%s (Roll Number: %d) - %.2f\n", students[i].name, students[i].rollNumber, average);
    }
}

void findHighestLowest(struct Student students[], int numStudents, int numSubjects) {
    float highestGrade = 0, lowestGrade = 100;
    int highestStudentIndex = -1, lowestStudentIndex = -1, highestSubjectIndex = -1, lowestSubjectIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            if (students[i].grades[j] > highestGrade) {
                highestGrade = students[i].grades[j];
                highestStudentIndex = i;
                highestSubjectIndex = j;
            }
            if (students[i].grades[j] < lowestGrade) {
                lowestGrade = students[i].grades[j];
                lowestStudentIndex = i;
                lowestSubjectIndex = j;
            }
        }
    }
    printf("Highest Grade:\nStudent: %s (Roll Number: %d), Subject: %s, Grade: %.2f\n",students[highestStudentIndex].name, students[highestStudentIndex].rollNumber,(highestSubjectIndex == 0 ? "Math" : (highestSubjectIndex == 1 ? "Science" : (highestSubjectIndex == 2 ? "English" : "History"))),highestGrade);
    printf("Lowest Grade:\nStudent: %s (Roll Number: %d), Subject: %s, Grade: %.2f\n",students[lowestStudentIndex].name, students[lowestStudentIndex].rollNumber,(lowestSubjectIndex == 0 ? "Math" : (lowestSubjectIndex == 1 ? "Science" : (lowestSubjectIndex == 2 ? "English" : "History"))),lowestGrade);
}

void displayGradeSummary(struct Student students[], int numStudents, int numSubjects) {
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Roll Number: %d, Grades: Math: %.2f, Science: %.2f, English: %.2f, History: %.2f\n",students[i].name, students[i].rollNumber, students[i].grades[0], students[i].grades[1],students[i].grades[2], students[i].grades[3]);
    }
}

int main() {
    int choice, numStudents, numSubjects;
    struct Student students[100]; // Assuming a maximum of 100 students
    printf("Welcome to the Student Grade Management System!\n");
    do {
        printf("\n1. Input Grades\n2. Calculate Average Grade\n3. Find Highest and Lowest Grade\n4. Display Grade Summary\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of students: ");
                scanf("%d", &numStudents);
                printf("Enter the number of subjects: ");
                scanf("%d", &numSubjects);
                inputGrades(students, numStudents, numSubjects);
            break;
            case 2:
                calculateAverage(students, numStudents, numSubjects);
            break;
            case 3:
                findHighestLowest(students, numStudents, numSubjects);
            break;
            case 4:
                displayGradeSummary(students, numStudents, numSubjects);
            break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice >= 1 && choice <= 4);
 return 0;
}