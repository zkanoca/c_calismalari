//This program was coded by zkanoca 
// 20.10.2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_STUDENTS 10  // Sınıf kapasitesi 10 öğrenci
#define MAX_LENGTH 255           // Her öğrenci ismi veya soyismi azami 255 karakter uzunluğunda olabilir

// Öğrenci yapısı
typedef struct {
    char name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    int studentID;
} Student;

// Sözlüğe öğrenci ekleyen fonksiyon
void addStudent(Student students[], int *count) {
    if (*count < MAX_NUMBER_STUDENTS) {
        printf("Enter name: ");
        scanf("%s", students[*count].name);
        printf("Enter surname: ");
        scanf("%s", students[*count].surname);
        printf("Enter student ID: ");
        scanf("%d", &students[*count].studentID);
        (*count)++;
        printf("Student added.\n");
    } else {
        printf("Class is full.\n");
    }
}

// Öğrencileri yazdıran fonksiyon
void printStudents(Student students[], int count) {
    printf("Student List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s %s (ID: %d)\n", i + 1, students[i].name, students[i].surname, students[i].studentID);
    }
}

// Öğrenci numarasına göre öğrenciyi bulan fonksiyon
void findStudentByID(Student students[], int count, int studentID) {
    for (int i = 0; i < count; i++) {
        if (students[i].studentID == studentID) {
            printf("Found: %s %s (ID: %d)\n", students[i].name, students[i].surname, students[i].studentID);
            return;
        }
    }
    printf("Student not found.\n");
}

// Öğrenci numarasına göre öğrenciyi silen fonksiyon
void removeStudentByID(Student students[], int *count, int studentID) {
    for (int i = 0; i < *count; i++) {
        if (students[i].studentID == studentID) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student with ID %d removed.\n", studentID);
            return;
        }
    }
    printf("Student not found.\n");
}

// Öğrencileri isimlerine göre sıralayan fonksiyon
void sortStudentsByName(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by name.\n");
}

// Öğrencileri soyisimlerine göre sıralayan fonksiyon
void sortStudentsBySurname(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].surname, students[j + 1].surname) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by surname.\n");
}

// Öğrencileri numaralarına göre sıralayan fonksiyon
void sortStudentsByID(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].studentID > students[j + 1].studentID) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by ID.\n");
}

// Ana fonksiyon
int main() {
    Student students[MAX_NUMBER_STUDENTS]; // Öğrenci dizisi
    int count = 0;  // Öğrenci sayısını takip etmek için

    char command;
    while (1) {
        printf("Command (a: add, p: print, f: find, r: remove, sn: sort by name, ss: sort by surname, si: sort by ID, q: quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                addStudent(students, &count);
                break;
            case 'p':
                printStudents(students, count);
                break;
            case 'f': {
                int studentID;
                printf("Enter student ID to find: ");
                scanf("%d", &studentID);
                findStudentByID(students, count, studentID);
                break;
            }
            case 'r': {
                int studentID;
                printf("Enter student ID to remove: ");
                scanf("%d", &studentID);
                removeStudentByID(students, &count, studentID);
                break;
            }
            case 'sn': // İsimlerine göre sıralama
                sortStudentsByName(students, count);
                break;
            case 'ss': // Soyisimlerine göre sıralama
                sortStudentsBySurname(students, count);
                break;
            case 'si': // Numaralarına göre sıralama
                sortStudentsByID(students, count);
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}
