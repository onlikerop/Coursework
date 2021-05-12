//
// Created by Eugene on 16.04.2021.
//

#ifndef COURSEWORK_SEMESTER_H
#define COURSEWORK_SEMESTER_H


#include "Grademeres.h"

class Semester : public Active, public Grademeres{
private:
    Subject subjects[10];


public:

    Semester();
    ~Semester();

    int addSubject(const string& subjName);
    int addSubject();

    int removeSubject(const string& subjName);

    void cleanSubjects();

    void printSubjects();

    int getNumberOfGrades(GRADE grade) final;

    int getNumberOfGrades(int grade) final;

    int getNumberOfSubjects() final;

    Subject* getSubject(const string& subjName);

    int operator +(const string& subjName);
    int operator -(const string& subjName);


    int setGrade (const string& subjName, GRADE grade_to_set);

    int setGrade (const string& subjName, int grade_to_set);

    GRADE getGrade (const string& subjName);

    int setName (const string& subjName, const string &subjNameToSet);


    friend int saveToFile(const string& path, Student* student, HCRYPTKEY key);
    friend inline int loadFromFile(const string& path, Student* student, FILE* file, BYTE *hPublicKey, DWORD hPublicKeyLen);

};


#endif //COURSEWORK_SEMESTER_H
