//
// Created by Eugene on 16.04.2021.
//
#ifndef COURSEWORK_SUBJECT_H
#define COURSEWORK_SUBJECT_H


#include <iostream>
#include <utility>
#include <Windows.h>
#include "Active.h"
#include "OwnTypes.h"


string GRADEToString(GRADE grade);
string SEXToString (SEX sex);
SEX stringToSEX (const string& sex);

class Subject : public Active{
private:
    string name;
    GRADE grade;


public:
    Subject();

    int setGrade (GRADE grade_to_set);

    int setGrade (int grade_to_set);

    GRADE getGrade () const;

    string getName() const;

    int setName (const string &subjName);


    friend int saveToFile(const string& path, Student* student);
    friend int loadFromFile(const string& path, Student* student);
};


#endif //COURSEWORK_SUBJECT_H
