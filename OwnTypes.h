//
// Created by Eugene on 26.04.2021.
//

#ifndef COURSEWORK_OWNTYPES_H
#define COURSEWORK_OWNTYPES_H

#include <cstring>
#include <string>


using namespace std;


class Subject;
class Semester;
class Student;


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

struct BothWayList{

    BothWayList(BothWayList *pPrevious, BothWayList *pNext, Student* value) {

        this->id = ++BothWayList::count;
        this->previous = pPrevious;
        this->next = pNext;
        this->value = value;
    }

    int id;
    BothWayList* previous;
    BothWayList* next;
    Student* value;

    static int count;
    static BothWayList* pStart;

};

struct Crypto{
public:
    Crypto(const char* value, HCRYPTKEY hSessionKey){
        this->value = value;
        this->hSessionKey = hSessionKey;
    }
    Crypto(const char* value, BYTE* hPublicKey){
        this->value = value;
        this->hPublicKey = hPublicKey;
    }
    const char* getValue() const{
        return value;
    }
    HCRYPTKEY getSessionKey() const{
        return hSessionKey;
    }
    BYTE* getPublicLey(){
        return hPublicKey;
    }

private:
    const char* value;
    HCRYPTKEY hSessionKey;
    BYTE* hPublicKey;
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
