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
}

Student::Student() {
    while(true) {
        try {
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
            if (cin.get() != '\n')
                cin.unget();

            bool flag = true;
            while (flag) {
                string dateString;
                cout << "Enter student's birthdate (DD.MM.YYYY): " << endl;
                cin >> dateString;

                unsigned int dots[2];
                dots[0] = dateString.find('.');
                if (dots[0] == string::npos)
                    throw invalid_argument("Wrong format!");
                dots[1] = dateString.find('.', dots[0] + 2);
                if (dots[0] == string::npos)
                    throw invalid_argument("Wrong format!");

                BDDay = stoi(dateString.substr(0, dots[0]));
                BDMonth = stoi(dateString.substr(dots[0] + 1, dots[1] - dots[0] - 1));
                BDYear = stoi(dateString.substr(dots[1] + 1));
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
                } else flag = false;
            }


            flag = true;
            while (flag) {
                cout << "Enter student's receipt year: " << endl;
                string receiptYearStr;
                cin >> receiptYearStr;
                receiptYear = stoi(receiptYearStr);
                if (receiptYear - BDYear < 14)
                    cout << "ERROR! Student on receipt must be 14 years old or older. Try again!" << endl;
                else flag = false;
            }

            cout << "Enter student's faculty: " << endl;
            if (cin.get() != '\n')
                cin.unget();
            getline(cin, faculty);
            cout << "Enter student's department: " << endl;
            getline(cin, department);
            cout << "Enter student's group: " << endl;
            cin >> group;
            cout << "Enter student's ID (ID Card): " << endl;
            cin >> IDCard;

            flag = true;
            while (flag) {
                cout << "Enter student's sex (Male, Female, M , F): " << endl;
                cin >> sexString;
                if (stringToSEX(sexString) == Undefined)
                    cout << "ERROR! Unknown sex. It must be \"Male\" or \"Female\". Try Again!" << endl;
                else flag = false;
            }

            sex = stringToSEX(sexString);


            name = {move(SName), move(FName), move(TName)};
            this->BDate = {BDDay, BDMonth, BDYear};
            university = {receiptYear, move(faculty), move(department), move(group), move(IDCard)};
            this->sex = sex;

            cout << "You've just successfully added " << name.Second << " " << name.First << " " << name.Third
                 << " to the list of students" << endl;
            break;
        }
        catch (...) {
            cout << "Error! Invalid input, try all steps again!" << endl;
            if (cin.get() != '\n')
                cin.unget();
            continue;
        }
    }
}


Student::~Student(){
    //cout << "You've just successfully removed student " << getFullName() << " (" << getID() << ")" << endl;
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

Date Student::getBirthdate() const{
    return BDate;
}

string Student::getID() const{
    return university.IDCard;
}

void Student::printInfo(){
    cout << "==================Student's Info==================" << endl;

    cout << "Name: " << getFullName() << endl;
    cout << "Birthdate: " << BDate.day << "." << BDate.month << "." << BDate.year << endl;
    cout << "Year of receipt: " << university.receiptYear << endl;
    cout << "Faculty: " << university.faculty << endl;
    cout << "Department: " << university.department << endl;
    cout << "Group: " << university.group << endl;
    cout << "IDCard: " << university.IDCard << endl;
    cout << "Sex: " << SEXToString(sex) << endl;

    cout << endl << "                 Semesters' info                  " << endl;

    int counter = 0;
    for (auto & semester : semesters) {
        counter++;
        if (semester.is_active()){
            cout << "   Semester " << counter << endl;
            semester.printSubjects();
            cout << endl;
        }
    }

    cout << "==================================================" << endl;
}

void Student::editInfo(){
    try {
        string wannaEdit;
        cout << "==================Student's Info==================" << endl;

        cout << "Name: " << getFullName() << endl;
        cout << "Do you want to edit this field? (Y/N):" << endl;
        cin >> wannaEdit;
        if (wannaEdit == "Y" || wannaEdit == "y") {
            cout << "Enter new full name of student:" << endl;
            cin >> name.Second >> name.First >> name.Third;
        }

        while (true) {
            cout << "Birthdate: " << BDate.day << "." << BDate.month << "." << BDate.year << endl;
            cout << "Do you want to edit this field? (Y/N):" << endl;
            cin >> wannaEdit;
            if (wannaEdit == "Y" || wannaEdit == "y") {
                bool flag = true;
                unsigned short BDDay, BDMonth, BDYear;
                while (flag) {
                    string dateString;
                    cout << "Enter new student's birthdate (DD.MM.YYYY): " << endl;
                    cin >> dateString;

                    unsigned int dots[2];
                    dots[0] = dateString.find('.');
                    if (dots[0] == string::npos)
                        throw invalid_argument("Wrong format!");
                    dots[1] = dateString.find('.', dots[0] + 2);
                    if (dots[0] == string::npos)
                        throw invalid_argument("Wrong format!");

                    BDDay = stoi(dateString.substr(0, dots[0]));
                    BDMonth = stoi(dateString.substr(dots[0] + 1, dots[1] - dots[0] - 1));
                    BDYear = stoi(dateString.substr(dots[1] + 1));
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
                    } else flag = false;
                }
                this->BDate = {BDDay, BDMonth, BDYear};
            }
            cout << "Year of receipt: " << university.receiptYear << endl;
            cout << "Do you want to edit this field? (Y/N):" << endl;
            cin >> wannaEdit;
            if (wannaEdit == "Y" || wannaEdit == "y") {
                bool flag = true;
                unsigned short receiptYear;
                string receiptYearStr;
                while (flag) {
                    cout << "Enter new student's receipt year:" << endl;
                    cin >> receiptYearStr;
                    receiptYear = stoi(receiptYearStr);
                    if (receiptYear - BDate.year < 14)
                        cout << "ERROR! Student on receipt must be 14 years old or older. Try again!" << endl;
                    else flag = false;
                }
                university.receiptYear = receiptYear;

            }

            if (university.receiptYear - BDate.year < 14)
                cout << "ERROR! Student on receipt must be 14 years old or older. Try again!" << endl;
            else break;
        }

        cout << "Faculty: " << university.faculty << endl;
        cout << "Do you want to edit this field? (Y/N):" << endl;
        cin >> wannaEdit;
        if (wannaEdit == "Y" || wannaEdit == "y") {
            cout << "Enter new student's faculty:" << endl;
            if (cin.get() != '\n')
                cin.unget();
            getline(cin, university.faculty);
        }
        cout << "Department: " << university.department << endl;
        cout << "Do you want to edit this field? (Y/N):" << endl;
        cin >> wannaEdit;
        if (wannaEdit == "Y" || wannaEdit == "y") {
            cout << "Enter new student's department:" << endl;
            if (cin.get() != '\n')
                cin.unget();
            getline(cin, university.department);
        }
        cout << "Group: " << university.group << endl;
        cout << "Do you want to edit this field? (Y/N):" << endl;
        cin >> wannaEdit;
        if (wannaEdit == "Y" || wannaEdit == "y") {
            cout << "Enter new student's group:" << endl;
            if (cin.get() != '\n')
                cin.unget();
            cin >> university.group;
        }
        cout << "IDCard: " << university.IDCard << endl;
        cout << "Do you want to edit this field? (Y/N):" << endl;
        cin >> wannaEdit;
        if (wannaEdit == "Y" || wannaEdit == "y") {
            cout << "Enter new student's ID (ID Card):" << endl;
            if (cin.get() != '\n')
                cin.unget();
            cin >> university.IDCard;
        }
        cout << "Sex: " << SEXToString(sex) << endl;
        cout << "Do you want to edit this field? (Y/N):" << endl;
        cin >> wannaEdit;
        if (wannaEdit == "Y" || wannaEdit == "y") {
            string newSex;
            while (stringToSEX(newSex) == Undefined) {
                cout << "Enter new sex of student (Male, Female, M , F):" << endl;
                cin >> newSex;
                if (stringToSEX(newSex) == Undefined)
                    cout << "ERROR! Unknown sex. It must be \"Male\" or \"Female\". Try Again!" << endl;
                else
                    sex = stringToSEX(newSex);
            }
        }

        cout << endl << "                 Semesters' info                  " << endl;

        bool flag = true;
        wannaEdit = "N";
        while (flag) {
            int counter = 0;
            for (auto &semester : semesters) {
                counter++;
                if (semester.is_active()) {
                    cout << "   Semester " << counter << endl;
                    semester.printSubjects();
                    cout << "Do you want to edit this semester? (Y/N):" << endl;
                    cin >> wannaEdit;
                    if (wannaEdit == "Y" || wannaEdit == "y") {
                        string subjectStr;
                        while (true) {
                            cout
                                    << "Enter subject that you want to change or enter \"exit\" to exit or enter \"DELETE\" to delete this semester or \"addnew\" to add new subject:"
                                    << endl;
                            if (cin.get() != '\n')
                                cin.unget();
                            getline(cin, subjectStr);
                            if (subjectStr == "exit") break;
                            if (subjectStr == "DELETE") {
                                int i = 1;
                                while (getSemester(i) != &semester)
                                    i++;
                                removeSemester(i);
                                break;
                            }
                            if (subjectStr == "addnew") {
                                semester.addSubject();
                                continue;
                            }

                            Subject *subject = semester.getSubject(subjectStr);
                            if (subject == nullptr) {
                                cout << "Error! You entered undeclared subject, try again!" << endl;
                                continue;
                            }
                            string choiceStr;
                            int choice;
                            cout << "What would you like to edit:"
                                 << endl << "1. Name of subject"
                                 << endl << "2. Grade"
                                 << endl << "3. Delete"
                                 << endl;
                            cin >> choiceStr;
                            choice = stoi(choiceStr);
                            switch (choice) {
                                case 1: {
                                    subject->setName();
                                    continue;
                                }
                                case 2: {
                                    subject->setGrade();
                                    continue;
                                }
                                case 3: {
                                    semester.removeSubject(subjectStr);
                                    break;
                                }
                                default: {
                                    cout << "ERROR! Wrong menu item, try this step again" << endl;
                                    continue;
                                }
                            }

                        }
                    }
                }
            }
            if (!(wannaEdit == "Y" || wannaEdit == "y")) {
                string wanna;
                cout << "Do you want to add a new semester? (Y/N):" << endl;
                cin >> wanna;
                if (wanna == "Y" || wanna == "y") {
                    addSemester();
                } else flag = false;
            }
        }

        cout << "==================================================" << endl;
    }
    catch (invalid_argument const &exception){
        cout << "Error! Invalid input, try all steps again!" << endl;
        return;
    }
    catch (range_error const &exception){
        cout << "Error! Invalid input, try all steps again!" << endl;
        return;
    }
}

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

int Student::getNumberOfSubjects(){
    int counter = 0;
    for (auto & semester : semesters){
        if (semester.is_active())
            counter += semester.getNumberOfSubjects();
    }
    return counter;
}

Semester* Student::getSemester(int semNumber){
    if (semesters[semNumber-1].is_active())
        return &semesters[semNumber-1];
    else
        return nullptr;
}

int Student::operator ++(const int) {
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

Student::Student(nullptr_t) {}

SEX Student::getSex() const {
    return sex;
}

int Student::setID(string IDCard) {
    this->university.IDCard = IDCard;
    return 0;
}
