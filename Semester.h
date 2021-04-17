//
// Created by Eugene on 16.04.2021.
//

#ifndef COURSEWORK_SEMESTER_H
#define COURSEWORK_SEMESTER_H




class Semester{
private:
    Subject* subjects[10];


public:

    Semester();
//    ~Semester();

    int addSubject(const string& subjName);

    int removeSubject(const string& subjName);

    void printSubjects();

    Subject* getSubject(const string& subjName);


};


#endif //COURSEWORK_SEMESTER_H
