//
// Created by Eugene on 16.04.2021.
//

#ifndef COURSEWORK_SUBJECT_H
#define COURSEWORK_SUBJECT_H


#include <iostream>
#include <cstring>
#include <utility>


using namespace std;


struct Name{
    string Second;
    string First;
    string Third;
};

struct Date{
    int day;
    int month;
    int year;
};

struct University {
    unsigned short receiptYear;
    string faculty;
    string department;
    string group;
    string IDCard;
};

enum SEX {
    Male,
    Female
};

enum GRADE{
    GREAT = 5,
    GOOD = 4,
    SATISFACTORY = 3,
    COMPLETE = 6,
    INCOMPLETE = 2,
    UNSET = 0
};

class Subject {
private:
    string name;
    GRADE grade;


public:
    explicit Subject(string subjName){
        name = move(subjName);
        grade = UNSET;
        cout << "You've just successfully added " << name << " subject" << endl;
    }

    ~Subject(){
        cout << "Subject " << name << " was successfully removed" << endl;
    }

    void setGrade (GRADE grade_to_set){
        grade = grade_to_set;
    }

    void setGrade (int grade_to_set){
        grade = static_cast<GRADE>(grade_to_set);
    }

    GRADE getGrade (){
        return grade;
    }

    string getName(){
        return name;
    }

};


#endif //COURSEWORK_SUBJECT_H
