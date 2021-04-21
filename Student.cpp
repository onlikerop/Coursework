//
// Created by Eugene on 16.04.2021.
//

#include "Subject.h"
#include "Semester.h"
#include "Student.h"


Student::Student(string SName, string FName, string TName, Date BDate, unsigned short receiptYear, string faculty, string department, string group, string IDCard, SEX sex){
    name = {move(SName), move(FName), move(TName)};
    this->BDate = BDate;
    university = {receiptYear, move(faculty), move(department), move(group), move(IDCard)};
    this->sex = sex;
    for (auto & semester : semesters)
        semester = nullptr;

    cout << "You've just successfully added " << getFullName() << " to the list of students" << endl;
}

Student::Student() {
    string SName, FName, TName, faculty, department, group, IDCard;
    Date BDate;
    unsigned short BDDay, BDMonth, BDYear, receiptYear;
    SEX sex;

    cout << "Enter student's second name: " << endl;
    cin >> SName;
    cout << "Enter student's first name: " << endl;
    cin >> FName;
    cout << "Enter student's third name: " << endl;
    cin >> TName;

    cout << "Enter student's birthdate: " << endl;
    bool flag_BD = true;
    while (flag_BD) {
        scanf_s("%d.%d.%d", &BDDay, &BDMonth, &BDYear);
        if (
                ((BDMonth == 4 || BDMonth == 6 || BDMonth == 9 || BDMonth == 11) && BDDay > 30)
                || ((BDMonth == 2) && BDDay > 29)
                || (BDDay > 31)
           ){
            cout << "ERROR! You've entered wrong birthdate. Try again!" << endl;
        }
        else
            flag_BD = false;
    }

    cout << "Enter student's receipt year: " << endl;
    bool flag_RY = true;
    while (flag_RY){
        cin >> receiptYear;
        if (receiptYear - BDYear < 14)
            cout << "ERROR! Student on receipt must be 14 years old or older. Try again!" << endl;
        else
            flag_RY = false;
    }

    cout << "Enter student's faculty: " << endl;
    cin >> faculty;
    cout << "Enter student's department: " << endl;
    cin >> department;
    cout << "Enter student's group: " << endl;
    cin >> group;
    cout << "Enter student's ID (ID Card): " << endl;
    cin >> IDCard;

    cout << "Enter student's sex: " << endl;
    // Доделать ввод пола через отдельный конвертер string to SEX


    name = {move(SName), move(FName), move(TName)};
    this->BDate = BDate;
    university = {receiptYear, move(faculty), move(department), move(group), move(IDCard)};
    this->sex = sex;
    for (auto & semester : semesters)
        semester = nullptr;

    cout << "You've just successfully added " << getFullName() << " to the list of students" << endl;
}


Student::~Student(){
//    for (auto & i : semesters)
//        if (i != nullptr){
//            delete i;
//            i = nullptr;
//        }
    cout << "You've just successfully removed student " << getFullName() << " (" << getID() << ")" << endl;
}

int Student::addSemester(){
    int counter = 1;
    for (auto & semester : semesters){
        if (semester == nullptr){
            semester = new Semester();
            cout << "You've just successfully added semester " << counter << endl;
            return 0;
        }
        counter++;
    }
    cout << "You can't add semester, because it is fully loaded (max. number of semesters - 9)" << endl;
    return 1;
}

int Student::removeSemester(int semesterNumber) {
    if (semesters[semesterNumber - 1] != nullptr){
        delete semesters[semesterNumber - 1];
        semesters[semesterNumber - 1] = nullptr;
        cout << "You've just successfully removed semester " << semesterNumber << endl;
        return 0;
    }
    cout << "You can't remove semester that do not exist" << endl;
    return 1;
}

string Student::getFullName(){
    return name.Second + " " + name.First + " " + name.Third;
}

string Student::getID(){
    return university.IDCard;
}

void Student::printInfo(){
    cout << "==================Student's Info==================" << endl;

    cout << "Name: " << getFullName() << endl;
    cout << "Sex: " << SEXToString(sex) << endl;
    cout << "Birthdate: " << BDate.day << "." << BDate.month << "." << BDate.year << endl;
    cout << "IDCard: " << university.IDCard << endl;
    cout << "Faculty: " << university.faculty << endl;
    cout << "Department: " << university.department << endl;
    cout << "Group: " << university.group << endl;
    cout << "Year of receipt: " << university.receiptYear << endl;

    cout << endl << "                 Semesters' info                  " << endl;

    int counter = 1;
    for (auto & semester : semesters)
        if (semester != nullptr){
            cout << "   Semester " << counter << endl;
            counter++;
            semester->printSubjects();
            cout << endl;
        }

    cout << "==================================================" << endl;
}

//        void Student::addSubject(int semNumber, const string& subjName){
//            semesters[semNumber-1]->addSubject(subjName);
//        }
//
//        void Student::removeSubject(int semNumber, const string& subjName){
//            semesters[semNumber-1]->removeSubject(subjName);
//        }
//
//        void Student::printSubjects(int semNumber){
//            semesters[semNumber-1]->printSubjects();
//        }

Semester* Student::getSemester(int semNumber){
    return semesters[semNumber-1];
}

int Student::operator +() {
    return addSemester();
}

int Student::operator -(int semNumber) {
    return removeSemester(semNumber);
}