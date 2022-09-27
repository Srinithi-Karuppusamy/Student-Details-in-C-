#include <iostream>
#include<string.h>

using namespace std;

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
        char courseGrade;
     }studentGrade;
}studentRecord;
    
void addRecord(studentRecord *stuRecord) {
        cout<<"Enter id"<<endl;
        cin>>stuRecord->id;
        cout<<"Enter age"<<endl;
        cin>>stuRecord->age;
        cout<<"Enter student first name"<<endl;
        cin>>stuRecord->studentName.firstName;
        cout<<"Enter student last name"<<endl;
        cin>>stuRecord->studentName.lastName;
        cout<<"Enter program grade"<<endl;
        cin>>stuRecord->studentGrade.programGrade;
        cout<<"Enter quiz grade"<<endl;
        cin>>stuRecord->studentGrade.quizGrade;
        cout<<"Enter final exam"<<endl;
        cin>>stuRecord->studentGrade.finalExam;
        cout<<"Enter cgpa"<<endl;
        cin>>stuRecord->studentGrade.GPA;
        cout<<"Enter course grade"<<endl;
        cin>>stuRecord->studentGrade.courseGrade;
}

void display(int len, studentRecord *ptr) {
    if (!len) {
        cout<<"No records to display"<<endl;
    }
    for (int i=0; i<len; i++) {
        cout<<"Student Records:"<<endl;
		cout<<"First Name :"<<ptr[i].studentName.firstName<<endl;
		cout<<"Last Name :"<<ptr[i].studentName.lastName<<endl;
		cout<<"Age :"<<ptr[i].age<<endl;
		cout<<"Id :"<<ptr[i].id<<endl;
		cout<<"Program Grade :"<<ptr[i].studentGrade.programGrade<<endl;
		cout<<"Final Exam :"<<ptr[i].studentGrade.finalExam<<endl;
		cout<<"Quiz Grade :"<<ptr[i].studentGrade.quizGrade<<endl;
		cout<<"GPA :"<<ptr[i].studentGrade.GPA<<endl;
		cout<<"Course Grade"<<ptr[i].studentGrade.courseGrade<<endl;
    }
}

void studentDispaly(int id, studentRecord *ptr, int length) {
    if (!length) {
        cout<<"No records to display"<<endl;
    }
    int isPresent = false;
    for (int i=0; i<length; i++) {
        if (id == ptr[i].id) {
            isPresent = true;
            cout<<"Student Records:"<<endl;
		    cout<<"First Name :"<<ptr[i].studentName.firstName<<endl;
		    cout<<"Last Name :"<<ptr[i].studentName.lastName<<endl;
		    cout<<"Age :"<<ptr[i].age<<endl;
		    cout<<"Id :"<<ptr[i].id<<endl;
		    cout<<"Program Grade :"<<ptr[i].studentGrade.programGrade<<endl;
		    cout<<"Final Exam :"<<ptr[i].studentGrade.finalExam<<endl;
		    cout<<"Quiz Grade :"<<ptr[i].studentGrade.quizGrade<<endl;
		    cout<<"GPA :"<<ptr[i].studentGrade.GPA<<endl;
		    cout<<"Course Grade"<<ptr[i].studentGrade.courseGrade<<endl;
		    break;
        }
    }
    if (!isPresent) {
        cout<<"No such id present"<<endl;
    }
}

int main()
{
    cout<<"Hello World"<<endl;
    cout<<"Program to add or display student details"<<endl;
    studentRecord stuRecord[5];
    int option;
    int length = 0;
    do {
        cout<<"Enter the number to perform operation"<<endl;
        cout<<"1.Add a student detail 2.Display all student details 3.Enter student id to display specific student detail 4.Quit"<<endl;
        
        cin>>option;
        switch(option) {
            case 1:
                addRecord(stuRecord);
                length++;
                break;
            case 2:
                display(length, stuRecord);
                break;
            case 3:
                int id;
                cout<<"Enter student id"<<endl;
                cin>>id;
                studentDispaly(id, stuRecord, length);
                break;
            case 4:
                exit(0);
                break;
            default:
                break;
        }
    } while(option != 0);
    return 0;
}