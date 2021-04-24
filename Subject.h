//
// Created by Eugene on 16.04.2021.
//
#ifndef COURSEWORK_SUBJECT_H
#define COURSEWORK_SUBJECT_H


#include <iostream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <string>
#include <Windows.h>


using namespace std;


struct Name{
    string Second;
    string First;
    string Third;
};

struct Date{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct University {
    unsigned short receiptYear;
    string faculty;
    string department;
    string group;
    string IDCard;
};

enum SEX {
    Undefined = -1,
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

string GRADEToString(GRADE grade);
string SEXToString (SEX sex);
SEX stringToSEX (const string& sex);

class Subject{
private:
    string name;
    GRADE grade;


public:
    explicit Subject(string subjName);

    void setGrade (GRADE grade_to_set);

    void setGrade (int grade_to_set);

    GRADE getGrade () const;

    string getName() const;
};


#endif //COURSEWORK_SUBJECT_H
