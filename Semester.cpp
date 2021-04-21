//
// Created by Eugene on 16.04.2021.
//

#include "Subject.h"
#include "Semester.h"

Semester::Semester() {
    for (auto & subject : subjects)
        subject = nullptr;
}

//Semester::~Semester(){
//    for (auto & i : subjects)
//        if (i != nullptr){
//            delete i;
//            i = nullptr;
//        }
//}

int Semester::addSubject(const string& subjName){
    for (auto & subject : subjects){
        if (subject == nullptr){
            subject = new Subject(subjName);
            cout << "You've just successfully added " << subjName << " subject" << endl;
            return 0;
        }
    }
    cout << "You can't add subject in this semester, because it is fully loaded (max. number of subjects in one semester - 10)" << endl;
    return 1;
}

int Semester::removeSubject(const string& subjName){
    for (auto & subject : subjects){
        if (subject->getName() == subjName){
            delete subject;
            subject = nullptr;
            cout << "Subject " << subjName << " was successfully removed" << endl;
            return 0;
        }
    }
    cout << "You can't remove subject that don't exist" << endl;
    return 1;
}

void Semester::printSubjects(){
    for (auto & i : subjects)
        if (i != nullptr)
            cout << i->getName() << ": " << GRADEToString(i->getGrade()) << endl;
}

Subject* Semester::getSubject(const string& subjName){
    for (auto & i : subjects)
        if (i != nullptr)
            if (i->getName() == subjName)
                return i;
    return nullptr;
}

int Semester::operator+(const string &subjName) {
    return addSubject(subjName);
}

int Semester::operator-(const string &subjName) {
    return removeSubject(subjName);
}
