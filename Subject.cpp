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

Subject::Subject(string subjName){
    name = move(subjName);
    grade = UNSET;
}

void Subject::setGrade (GRADE grade_to_set){
grade = grade_to_set;
}

void Subject::setGrade (int grade_to_set){
    grade = static_cast<GRADE>(grade_to_set);
}

GRADE Subject::getGrade (){
    return grade;
}

string Subject::getName(){
    return name;
}