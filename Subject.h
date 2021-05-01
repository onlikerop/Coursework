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
GRADE StringToGRADE(string grade);
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

    int setGrade ();

    GRADE getGrade () const;

    string getName() const;

    int setName (const string &subjName);

    int setName ();


    friend int saveToFile(const string& path, Student* student);
    friend inline int loadFromFile(const string& path, Student* student, ifstream* fin);
    friend int loadFromFile(const string& path, Student* student);
};


#endif //COURSEWORK_SUBJECT_H
