//
// Created by Eugene on 16.04.2021.
//

#include "Subject.h"
#include "Semester.h"

Semester::Semester(){
    is_active_ = false;
}

Semester::~Semester() = default;

int Semester::addSubject(const string& subjName){
    for (auto & subject : subjects){
        if (!subject.is_active()){
            subject.is_active(true);
            subject.setName(subjName);
            cout << "You've just successfully added " << subjName << " subject" << endl;
            return 0;
        }
    }
    cout << "You can't add subject in this semester, because it is fully loaded (max. number of subjects in one semester - 10)" << endl;
    return 1;
}

int Semester::addSubject(){
    for (auto & subject : subjects){
        if (!subject.is_active()){
            subject.is_active(true);

            string subjName;
            cout << "Enter name of subject:" << endl;
            cin.get();
            getline(cin, subjName);
            subject.setName(subjName);
            cout << "You've just successfully added " << subjName << " subject" << endl;
            return 0;
        }
    }
    cout << "You can't add subject in this semester, because it is fully loaded (max. number of subjects in one semester - 10)" << endl;
    return 1;
}

int Semester::removeSubject(const string& subjName){
    for (auto & subject : subjects){
        if (subject.getName() == subjName){
            subject.is_active(false);
            subject.setName("");
            cout << "Subject " << subjName << " was successfully removed" << endl;
            return 0;
        }
    }
    cout << "You can't remove subject that don't exist" << endl;
    return 1;
}

void Semester::cleanSubjects(){
    for (auto & subject : subjects) {
        subject.is_active(false);
        subject.setName("");
    }
}

void Semester::printSubjects(){
    for (auto & i : subjects)
        if (i.is_active() && !i.getName().empty())
            cout << i.getName() << ": " << GRADEToString(i.getGrade()) << endl;
}

Subject* Semester::getSubject(const string& subjName){
    for (auto & i : subjects)
        if (i.is_active())
            if (i.getName() == subjName)
                return &i;
    return nullptr;
}

int Semester::operator+(const string &subjName) {
    return addSubject(subjName);
}

int Semester::operator-(const string &subjName) {
    return removeSubject(subjName);
}

bool Semester::is_active() const {
    return is_active_;
}

void Semester::is_active(bool is_active_) {
    this->is_active_ = is_active_;
}


int Semester::setGrade (const string& subjName, GRADE grade_to_set){
    Subject* subject = getSubject(subjName);
    if (subject == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    subject->setGrade(grade_to_set);
    return 0;
}

int Semester::setGrade (const string& subjName, int grade_to_set){
    Subject* subject = getSubject(subjName);
    if (subject == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    subject->setGrade(grade_to_set);
    return 0;
}


GRADE Semester::getGrade (const string& subjName){
    Subject* subject = getSubject(subjName);
    if (subject == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return Undefined_;
    }
    return subject->getGrade();
}

int Semester::setName (const string& subjName, const string &subjNameToSet){
    Subject* subject = getSubject(subjName);
    if (subject == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    subject->setName(subjNameToSet);
    return 0;
}