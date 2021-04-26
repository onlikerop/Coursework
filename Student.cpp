//
// Created by Eugene on 16.04.2021.
//

#include "Subject.h"
#include "Semester.h"
#include "Student.h"


Student::Student(string SName, string FName, string TName, Date BDate, unsigned short receiptYear, string faculty, string department, string group, string IDCard, SEX sex){
    name = {move(SName), move(FName), move(TName)};
    this->BDate = BDate;
    university = {receiptYear, move(faculty), move(department), move(group), move(IDCard)};
    this->sex = sex;
    for (auto & semester : semesters)
        semester.is_active(false);

    cout << "You've just successfully added " << getFullName() << " to the list of students" << endl;
}

Student::Student() {
        string SName, FName, TName, faculty, department, group, IDCard, sexString;
        unsigned short BDDay, BDMonth, BDYear, receiptYear;
        SEX sex;

        cout << endl << "Now you're going to add student in database. Follow the instructions below to continue! "
             << endl;

        cout << "Enter student's second name: " << endl;
        cin >> SName;
        cout << "Enter student's first name: " << endl;
        cin >> FName;
        cout << "Enter student's third name: " << endl;
        cin >> TName;

        bool flag = true;
        while (flag) {
            cout << "Enter student's birthdate (DD.MM.YYYY): " << endl;
            scanf_s("%hu.%hu.%hu", &BDDay, &BDMonth, &BDYear);
            bool leap_year = BDYear % 100 ? !(BDYear % 4) : !(BDYear % 400);
            if (
                    ((BDMonth == 4 || BDMonth == 6 || BDMonth == 9 || BDMonth == 11) && BDDay > 30)
                    || ((BDMonth == 2) && leap_year && BDDay > 29)
                    || ((BDMonth == 2) && !leap_year && BDDay > 28)
                    || (BDDay > 31)
                    || (BDMonth > 12)
                    || !(BDDay || BDMonth)
                    ) {
                cout << "ERROR! You've entered wrong birthdate. Try again!" << endl;
            } else
                flag = false;
        }


        flag = true;
        while (flag) {
            cout << "Enter student's receipt year: " << endl;
            cin >> receiptYear;
            if (receiptYear - BDYear < 14)
                cout << "ERROR! Student on receipt must be 14 years old or older. Try again!" << endl;
            else
                flag = false;
        }

        cout << "Enter student's faculty: " << endl;
        cin.get();
        getline(cin, faculty);
        cout << "Enter student's department: " << endl;
        getline(cin, department);
        cout << "Enter student's group: " << endl;
        cin >> group;
        cout << "Enter student's ID (ID Card): " << endl;
        cin >> IDCard;

        flag = true;
        while (flag) {
            cout << "Enter student's sex (Male, Female, M (latin), F, М (cyrillic), Ж): " << endl;
            cin >> sexString;
            if (stringToSEX(sexString) == Undefined)
                cout << "ERROR! Unknown sex. It must be \"Male\" or \"Female\". Try Again!" << endl;
            else
                flag = false;
        }

        sex = stringToSEX(sexString);


        name = {move(SName), move(FName), move(TName)};
        this->BDate = {BDDay, BDMonth, BDYear};
        university = {receiptYear, move(faculty), move(department), move(group), move(IDCard)};
        this->sex = sex;

        cout << "You've just successfully added " << name.Second << " " << name.First << " " << name.Third << " to the list of students" << endl;
}


Student::~Student(){
    cout << "You've just successfully removed student " << getFullName() << " (" << getID() << ")" << endl;
}

int Student::addSemester(){
    int counter = 1;
    for (auto & semester : semesters){
        if (!semester.is_active()){
            semester.is_active(true);
            cout << "You've just successfully added semester " << counter << endl;
            return 0;
        }
        counter++;
    }
    cout << "You can't add semester, because it is fully loaded (max. number of semesters - 9)" << endl;
    return 1;
}

int Student::removeSemester(int semesterNumber) {
    if (semesters[semesterNumber - 1].is_active()){
        semesters[semesterNumber - 1].is_active(false);
        semesters[semesterNumber - 1].cleanSubjects();
        cout << "You've just successfully removed semester " << semesterNumber << endl;
        return 0;
    }
    cout << "You can't remove semester that do not exist" << endl;
    return 1;
}

string Student::getFullName() const{
    return name.Second + " " + name.First + " " + name.Third;
}

string Student::getID() const{
    return university.IDCard;
}

void Student::printInfo(){
    cout << "==================Student's Info==================" << endl;

    cout << "Name: " << getFullName() << endl;
    cout << "Sex: " << SEXToString(sex) << endl;
    cout << "Birthdate: " << BDate.day << "." << BDate.month << "." << BDate.year << endl;
    cout << "IDCard: " << university.IDCard << endl;
    cout << "Faculty: " << university.faculty << endl;
    cout << "Department: " << university.department << endl;
    cout << "Group: " << university.group << endl;
    cout << "Year of receipt: " << university.receiptYear << endl;

    cout << endl << "                 Semesters' info                  " << endl;

    int counter = 1;
    for (auto & semester : semesters)
        if (semester.is_active()){
            cout << "   Semester " << counter << endl;
            counter++;
            semester.printSubjects();
            cout << endl;
        }

    cout << "==================================================" << endl;
}

//        void Student::addSubject(int semNumber, const string& subjName){
//            semesters[semNumber-1]->addSubject(subjName);
//        }
//
//        void Student::removeSubject(int semNumber, const string& subjName){
//            semesters[semNumber-1]->removeSubject(subjName);
//        }
//
//        void Student::printSubjects(int semNumber){
//            semesters[semNumber-1]->printSubjects();
//        }

int Student::getNumberOfGrades(GRADE grade){
    int counter = 0;
    for (auto & semester : semesters){
        if (semester.is_active())
            counter += semester.getNumberOfGrades(grade);
    }
    return counter;
}

int Student::getNumberOfGrades(int grade){
    int counter = 0;
    for (auto & semester : semesters){
        if (semester.is_active())
            counter += semester.getNumberOfGrades(grade);
    }
    return counter;
}

Semester* Student::getSemester(int semNumber){
    if (semesters[semNumber-1].is_active())
        return &semesters[semNumber-1];
    else
        return nullptr;
}

int Student::operator +() {
    return addSemester();
}

int Student::operator -(int semNumber) {
    return removeSemester(semNumber);
}


int Student::addSubject(int semNumber, const string& subjName){
    Semester* semester = getSemester(semNumber);
    if (semester == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    return (*semester + subjName);
}
int Student::addSubject(int semNumber){
    Semester* semester = getSemester(semNumber);
    if (semester == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    return semester->addSubject();
}

int Student::removeSubject(int semNumber, const string& subjName){
    Semester* semester = getSemester(semNumber);
    if (semester == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    return (*semester - subjName);
}

int Student::cleanSubjects(int semNumber){
    Semester* semester = getSemester(semNumber);
    if (semester == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    semester->cleanSubjects();
    return 0;
}

int Student::printSubjects(int semNumber){
    Semester* semester = getSemester(semNumber);
    if (semester == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    semester->printSubjects();
    return 0;
}


int Student::setGrade (int semNumber, const string& subjName, GRADE grade_to_set){
    Semester* semester = getSemester(semNumber);
    if (semester == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    return semester->setGrade(subjName, grade_to_set);
}

int Student::setGrade (int semNumber, const string& subjName, int grade_to_set){
    Semester* semester = getSemester(semNumber);
    if (semester == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    return semester->setGrade(subjName, grade_to_set);
}

GRADE Student::getGrade (int semNumber, const string& subjName){
    Semester* semester = getSemester(semNumber);
    if (semester == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return Undefined_;
    }
    return semester->getGrade(subjName);
}

int Student::setName (int semNumber, const string& subjName, const string &subjNameToSet){
    Semester* semester = getSemester(semNumber);
    if (semester == nullptr){
        cout << "Error! We got nullptr as argument. May be you've chosen wrong student / semester / subject" << endl;
        return 1;
    }
    return semester->setName(subjName, subjNameToSet);
}