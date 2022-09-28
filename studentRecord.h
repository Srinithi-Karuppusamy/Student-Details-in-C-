#include<iostream>
#include<string.h>

enum Grade {A, B, C, D, E, F};

typedef struct {
    struct studentNames{
        string firstName;
        string lastName;
    }studentName;
    int id;
    int age;
    struct studentGrades{
        int programGrade;
        int quizGrade;
        int finalExam;
        float GPA;
        Grade courseGrade;
     }studentGrade;
}studentRecord;