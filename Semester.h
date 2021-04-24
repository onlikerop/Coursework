//
// Created by Eugene on 16.04.2021.
//

#ifndef COURSEWORK_SEMESTER_H
#define COURSEWORK_SEMESTER_H


//#include "Subject.h"


class Semester{
private:
    Subject subjects[10];
    bool is_active_;


public:

    Semester();
    ~Semester();

    int addSubject(const string& subjName);
    int addSubject();

    int removeSubject(const string& subjName);

    void cleanSubjects();

    void printSubjects();

    bool is_active() const;

    void is_active(bool is_active_);

    Subject* getSubject(const string& subjName);

    int operator +(const string& subjName);
    int operator -(const string& subjName);


};


#endif //COURSEWORK_SEMESTER_H
