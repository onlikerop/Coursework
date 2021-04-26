//
// Created by Eugene on 26.04.2021.
//

#ifndef COURSEWORK_OWNTYPES_H
#define COURSEWORK_OWNTYPES_H

#include <cstring>
#include <string>


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
    Undefined_ = -1,
    GREAT = 5,
    GOOD = 4,
    SATISFACTORY = 3,
    COMPLETE = 6,
    INCOMPLETE = 2,
    UNSET = 0
};


#endif //COURSEWORK_OWNTYPES_H
