//
// Created by Eugene on 16.04.2021.
//

#ifndef COURSEWORK_SEMESTER_H
#define COURSEWORK_SEMESTER_H


#include "Subject.h"


class Semester{
private:

    Subject* subjects[10];


public:
    Semester(){
        cout << "You've just successfully added semester" << endl;
    }

    ~Semester(){
        for (auto i : subjects)
            delete i;
        delete[] *subjects;
        cout << "You've just successfully removed semester" << endl;
    }

    int addSubject(const string& subjName){
        for (auto & subject : subjects){
            if ((unsigned int)subject == UNINITIALIZED){
                subject = new Subject(subjName);
                return 0;
            }
        }
        cout << "You can't add subject in this semester, because it is fully loaded (max. number of subjects in one semester - 10)" << endl;
        return 1;
    }

    int removeSubject(const string& subjName){
        for (auto & subject : subjects){
            if (subject->getName() == subjName){
                delete subject;
                return 0;
            }
        }
        cout << "You can't remove subject, that don't exist" << endl;
        return 1;
    }

    void printSubjects(){
        for (auto i : subjects)
            if ((unsigned int)i != UNINITIALIZED)
                cout << i->getName() << ": " << i->getGrade() << endl;
    }

    Subject* getSubject(const string& subjName){
        for (auto i : subjects)
            if ((unsigned int) i != UNINITIALIZED)
                if (i->getName() == subjName)
                    return i;
        return nullptr;
    }


};


#endif //COURSEWORK_SEMESTER_H
