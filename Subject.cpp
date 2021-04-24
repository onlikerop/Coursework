//
// Created by Eugene on 16.04.2021.
//

#include "Subject.h"

string GRADEToString(GRADE grade) {
    switch (grade) {
        case 0: return "UNSET";
        case 2: return "INCOMPLETE (2)";
        case 3: return "SATISFACTORY (3)";
        case 4: return "GOOD (4)";
        case 5: return "GREAT (5)";
        case 6: return "COMPLETE";
        default: return "Error displaying the grade";
    }
}

string SEXToString (SEX sex) {
    switch (sex) {
        case 0: return "Male";
        case 1: return "Female";
        default: return "Error displaying the sex";
    }
}

SEX stringToSEX (const string& sex) {
    if (sex == "Male" or sex == "male" or sex == "M" or sex == "m" or sex == "М" or sex == "м")
        return Male;
    else if (sex == "Female" or sex == "female" or sex == "F" or sex == "f" or sex == "Ж" or sex == "ж")
        return Female;
    else
        return Undefined;
}

Subject::Subject(){
    name = "";
    grade = UNSET;
    is_active_ = false;
}

void Subject::setGrade (GRADE grade_to_set){
    grade = grade_to_set;
}

void Subject::setGrade (int grade_to_set){
    grade = static_cast<GRADE>(grade_to_set);
}

GRADE Subject::getGrade () const{
    return grade;
}

string Subject::getName() const{
    return name;
}

bool Subject::is_active() const {
    return is_active_;
}

void Subject::is_active(bool is_active_) {
    this->is_active_ = is_active_;
}

void Subject::setName(const string &subjName) {
    this->name = subjName;
}
