//
// Created by Eugene on 16.04.2021.
//

#include "Subject.h"

#include <utility>

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

GRADE StringToGRADE(string grade) {
    if (grade == "UNSET") return UNSET;
    if (grade == "INCOMPLETE" || grade == "2") return INCOMPLETE;
    if (grade == "SATISFACTORY" || grade == "3") return SATISFACTORY;
    if (grade == "GOOD" || grade == "4") return GOOD;
    if (grade == "GREAT" || grade == "5") return GREAT;
    if (grade == "COMPLETE") return COMPLETE;
    else return Undefined_;
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

int Subject::setGrade (GRADE grade_to_set){
    grade = grade_to_set;
    return 0;
}

int Subject::setGrade (int grade_to_set){
    grade = static_cast<GRADE>(grade_to_set);
    return 0;
}

int Subject::setGrade (){
    string grade_to_set;
    while (StringToGRADE(grade_to_set) == Undefined_) {
        cout << "Enter grade to set:"
             << endl << "\"GREAT\" or 5"
             << endl << "\"GOOD\" or 4"
             << endl << "\"SATISFACTORY\" or 3"
             << endl << "\"COMPLETE\""
             << endl << "\"INCOMPLETE\" or 2"
             << endl << "\"UNSET\""
             << endl;
        cin >> grade_to_set;
        if (StringToGRADE(grade_to_set) == Undefined_)
            cout << "ERROR! Unknown grade, try again!" << endl;
    }
    grade = StringToGRADE(grade_to_set);
    return 0;
}

GRADE Subject::getGrade () const{
    return grade;
}

string Subject::getName() const{
    return name;
}

int Subject::setName(string subjName) {
    this->name = move(subjName);
    return 0;
}

int Subject::setName() {
    string subjName;
    cout << "Enter subject name:" << endl;
    if (cin.get() != '\n')
        cin.unget();
    getline(cin, subjName);
    this->name = move(subjName);
    return 0;
}
