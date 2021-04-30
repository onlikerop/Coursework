//
// Created by Eugene on 23.04.2021.
//

#include "CWLib.h"


int saveToFile(const string& path, Student* student){
    ofstream fout;
    fout.open(path, ofstream::app);
    if (!fout.is_open()){
        cout << "Error opening save-file for saving" << endl;
        fout.close();
        return 1;
    }
    else{
        try {
            fout.write(reinterpret_cast<char *>(&(student->name.Second)), sizeof(string));
            fout.write(reinterpret_cast<char *>(&(student->name.First)), sizeof(string));
            fout.write(reinterpret_cast<char *>(&(student->name.Third)), sizeof(string));
            fout.write(reinterpret_cast<char *>(&(student->BDate.day)), sizeof(unsigned short));
            fout.write(reinterpret_cast<char *>(&(student->BDate.month)), sizeof(unsigned short));
            fout.write(reinterpret_cast<char *>(&(student->BDate.year)), sizeof(unsigned short));
            fout.write(reinterpret_cast<char *>(&(student->university.receiptYear)), sizeof(unsigned short));
            fout.write(reinterpret_cast<char *>(&(student->university.faculty)), sizeof(string));
            fout.write(reinterpret_cast<char *>(&(student->university.department)), sizeof(string));
            fout.write(reinterpret_cast<char *>(&(student->university.group)), sizeof(string));
            fout.write(reinterpret_cast<char *>(&(student->university.IDCard)), sizeof(string));
            fout.write(reinterpret_cast<char *>(&(student->sex)), sizeof(SEX));
            for (auto semester : student->semesters){
                fout.write(reinterpret_cast<char *>(&(semester.is_active_)), sizeof(bool));
                for (auto subject : semester.subjects){
                    fout.write(reinterpret_cast<char *>(&(subject.is_active_)), sizeof(bool));
                    fout.write(reinterpret_cast<char *>(&(subject.name)), sizeof(string));
                    fout.write(reinterpret_cast<char *>(&(subject.grade)), sizeof(GRADE));
                }
            }
            fout.close();
            cout << "Successfully saved data into \'" << path << "\'" << endl;
        }
        catch (...){
            return 1;
        }
        return 0;
    }

}

int loadFromFile(const string& path, Student* student){
    ifstream fin;
    fin.open(path, ios_base::in);
    if (!fin.is_open()){
        cout << "Error opening save-file for loading" << endl;
        return 1;
    }
    else{
        try {
            fin.read(reinterpret_cast<char *>(&(student->name.Second)), sizeof(string));
            fin.read(reinterpret_cast<char *>(&(student->name.First)), sizeof(string));
            fin.read(reinterpret_cast<char *>(&(student->name.Third)), sizeof(string));
            fin.read(reinterpret_cast<char *>(&(student->BDate.day)), sizeof(unsigned short));
            fin.read(reinterpret_cast<char *>(&(student->BDate.month)), sizeof(unsigned short));
            fin.read(reinterpret_cast<char *>(&(student->BDate.year)), sizeof(unsigned short));
            fin.read(reinterpret_cast<char *>(&(student->university.receiptYear)), sizeof(unsigned short));
            fin.read(reinterpret_cast<char *>(&(student->university.faculty)), sizeof(string));
            fin.read(reinterpret_cast<char *>(&(student->university.department)), sizeof(string));
            fin.read(reinterpret_cast<char *>(&(student->university.group)), sizeof(string));
            fin.read(reinterpret_cast<char *>(&(student->university.IDCard)), sizeof(string));
            fin.read(reinterpret_cast<char *>(&(student->sex)), sizeof(SEX));
            for (int semester = 0; semester < 9; semester++){
                fin.read(reinterpret_cast<char *>(&(student->semesters[semester].is_active_)), sizeof(bool));
                for (int subject = 0; subject < 10; subject++){
                    fin.read(reinterpret_cast<char *>(&(student->semesters[semester].subjects[subject].is_active_)), sizeof(bool));
                    fin.read(reinterpret_cast<char *>(&(student->semesters[semester].subjects[subject].name)), sizeof(string));
                    fin.read(reinterpret_cast<char *>(&(student->semesters[semester].subjects[subject].grade)), sizeof(GRADE));
                }
            }
            fin.close();
            cout << "Successfully loaded data from \'" << path << "\'" << endl;
        }
        catch (...){
            return 2;
        }
        return 0;
    }

}

int createStudent(Student* value){

    if (BothWayList::pStart == nullptr) {
        BothWayList::pStart = new BothWayList(nullptr, nullptr, value);
    }
    else{
        BothWayList* temp = BothWayList::pStart;
        while (temp->next != nullptr){ // TO EDIT (check if exist 1 and 2 sem and count its number of "3") !!!!!!!!!!!!!
            if ((static_cast<double>(temp->value->getNumberOfGrades(3)) / static_cast<double>(temp->value->getNumberOfSubjects())) >
                (static_cast<double>(value->getNumberOfGrades(3)) / static_cast<double>(value->getNumberOfSubjects()))
               ){
                temp = temp->next;
            }
            else break;
        }
        auto *theNewOne = new BothWayList(temp, temp->next, value);
        temp->next = theNewOne;
    }
    return 0;

}

int deleteStudent(BothWayList* list){

    list->previous->next = list->next;
    list->next->previous = list->previous;
    delete list;
    return 0;

}

int deleteAllStudents(){
    BothWayList* pCurrent = BothWayList::pStart;
    while (pCurrent != nullptr) {
        deleteStudent(pCurrent);
        pCurrent = BothWayList::pStart;
    }
    return 0;

}

BothWayList* findStudent(string fullNameOrID){

    auto *pCurrent = BothWayList::pStart;

    string goNext = "Y";

    while(goNext == "Y") {

        while (true){

            if (pCurrent == nullptr){
                cout << "We couldn't find next item with such value" << endl;
                return nullptr;

            }
            string currName = pCurrent->value->getFullName();
            string currID = pCurrent->value->getID();
            transform(currID.begin(), currID.end(), currID.begin(), tolower);
            transform(currName.begin(), currName.end(), currName.begin(), tolower);
            transform(fullNameOrID.begin(), fullNameOrID.end(), fullNameOrID.begin(), tolower);
            if (currName != fullNameOrID && currID != fullNameOrID){
                pCurrent = pCurrent->next;
            }
            else break;

        }

        cout << "We found this item: " << endl;
        pCurrent->value->printInfo();
        cout << endl << "Wanna try next one? (Y/N)" << endl;
        cin >> goNext;

        if (goNext == "Y")
            pCurrent = pCurrent->next;

    }

    return pCurrent;

}

BothWayList* findStudent(string fullNameOrID, unsigned short BDYearMin, unsigned short BDYearMax){

    auto *pCurrent = BothWayList::pStart;

    string goNext = "Y";

    while(goNext == "Y") {

        while (true){

            if (pCurrent == nullptr){
                cout << "We couldn't find next item with such value" << endl;
                return nullptr;

            }
            string currName = pCurrent->value->getFullName();
            string currID = pCurrent->value->getID();
            transform(currID.begin(), currID.end(), currID.begin(), tolower);
            transform(currName.begin(), currName.end(), currName.begin(), tolower);
            transform(fullNameOrID.begin(), fullNameOrID.end(), fullNameOrID.begin(), tolower);
            if ((currName != fullNameOrID && currID != fullNameOrID)
                || pCurrent->value->getBirthdate().year >= BDYearMin
                || pCurrent->value->getBirthdate().year <= BDYearMax
               ){
                pCurrent = pCurrent->next;
            }
            else break;

        }

        cout << "We found this item: " << endl;
        pCurrent->value->printInfo();
        cout << endl << "Wanna try next one? (Y/N)" << endl;
        cin >> goNext;

        if (goNext == "Y")
            pCurrent = pCurrent->next;

    }

    return pCurrent;

}

BothWayList* findStudent(unsigned short BDYearMin, unsigned short BDYearMax){

    auto *pCurrent = BothWayList::pStart;

    string goNext = "Y";

    while(goNext == "Y") {

        while (true){

            if (pCurrent == nullptr){
                cout << "We couldn't find next item with such value" << endl;
                return nullptr;

            }
            if (pCurrent->value->getBirthdate().year >= BDYearMin
                || pCurrent->value->getBirthdate().year <= BDYearMax
               ){
                pCurrent = pCurrent->next;
            }
            else break;

        }

        cout << "We found this item: " << endl;
        pCurrent->value->printInfo();
        cout << endl << "Wanna try next one? (Y/N)" << endl;
        cin >> goNext;

        if (goNext == "Y")
            pCurrent = pCurrent->next;

    }

    return pCurrent;

}

void menu(){
    string choiceStr;
    int choice = -1;
    while(choice != 7){
        try {
            cout << "Choose one the following menu item:"
                << endl << "1. Create new student"
                << endl << "2. Print list of all Students (may be very long, do it only on your own risk)"
                << endl << "3. Find student"
                << endl << "4. Save list to file"
                << endl << "5. Load list from file"
                << endl << "6. Credits"
                << endl << "7. Exit"
                << endl;
            cin >> choiceStr;
            choice = stoi(choiceStr);

            switch (choice) {
                case 1: { createStudent(new Student()); break; }
                case 2: {
                    BothWayList* pCurrent = BothWayList::pStart;
                    if (pCurrent == nullptr)
                        cout << "There is no any student. Make sure, you loaded data from file or created at least one student!" << endl;
                    while(pCurrent != nullptr){
                        pCurrent->value->printInfo();
                        pCurrent = pCurrent->next;
                    }
                    break;
                }
                case 3: {
                    string choiceStr2;
                    int choice2;
                    cout << "What type of search would you like:"
                        << endl << "1. By full name or ID"
                        << endl << "2. By full name or ID + min. and max. birthdate year"
                        << endl << "3. By min. and max. birthdate year"
                        << endl;
                    cin >> choiceStr2;
                    choice2 = stoi(choiceStr2);

                    BothWayList* foundStudent;

                    switch (choice2) {
                        case 1: {
                            string fullNameOrID;
                            cout << "Enter full name or ID of the Student:" << endl;
                            cin >> fullNameOrID;
                            foundStudent = findStudent(fullNameOrID);
                            break;
                        }
                        case 2: {
                            string fullNameOrID, minYearStr, maxYearStr;
                            int minYear, maxYear;
                            cout << "Enter full name or ID of the Student:" << endl;
                            cin >> fullNameOrID;
                            cout << "Enter min. birthdate year:" << endl;
                            cin >> minYearStr;
                            minYear = stoi(minYearStr);
                            cout << "Enter max. birthdate year:" << endl;
                            cin >> maxYearStr;
                            maxYear = stoi(maxYearStr);
                            foundStudent = findStudent(fullNameOrID, minYear, maxYear);
                            break;
                        }
                        case 3: {
                            string minYearStr, maxYearStr;
                            int minYear, maxYear;
                            cout << "Enter min. birthdate year:" << endl;
                            cin >> minYearStr;
                            minYear = stoi(minYearStr);
                            cout << "Enter max. birthdate year:" << endl;
                            cin >> maxYearStr;
                            maxYear = stoi(maxYearStr);
                            foundStudent = findStudent(minYear, maxYear);
                            break;
                        }
                        default: {
                            throw invalid_argument("Invalid input");
                        }
                    }
                    if (foundStudent != nullptr){
                        cout << "What would you like to with found student:"
                            << endl << "1. Edit"
                            << endl << "2. Delete"
                            << endl << "3. Nothing"
                            << endl;
                        cin >> choiceStr2;
                        choice2 = stoi(choiceStr2);

                        switch(choice2){
                            case 1: { foundStudent->value->editInfo(); break; }
                            case 2: { deleteStudent(foundStudent); break; }
                            case 3: {break;}
                            default: {cout << "ERROR! Unknown menu item, skipping!" << endl;}
                        }
                    }
                    break;
                }
                case 4: {
                    string fileName;
                    bool flag = true;
                    ofstream fout;

                    while (flag){
                        cout << "Enter the name of the file in which you want to save list:" << endl;
                        cin >> fileName;
                        fileName += ".CW";
                        fout.open(fileName);
                        if (fout.is_open()){
                            string wanna;
                            cout << "This file is already exist, do you really want to rewrite all data inside it? (Y/N):" << endl;
                            cin >> wanna;
                            if (wanna == "Y" && wanna == "y"){
                                flag = false;
                                remove(fileName.c_str());
                            }
                        }
                        fout.close();
                    }

                    BothWayList* pCurrent = BothWayList::pStart;
                    while (pCurrent != nullptr) {
                        saveToFile(fileName, pCurrent->value);
                        pCurrent = pCurrent->next;
                    }
                    break;
                }
                case 5: {
                    string fileName;
                    bool flag = true;
                    ofstream fin;

                    while (flag){
                        cout << "Enter the name of the file in which you want to load from:" << endl;
                        cin >> fileName;
                        fileName += ".CW";
                        fin.open(fileName);
                        if (!fin.is_open()) {
                            cout << "File do not exist or it's damaged or it's protected by system!" << endl;
                            fin.close();
                        }
                        else flag = false;
                        }

                    deleteAllStudents();
                    while (!fin.eof()) {
                        auto *temp = new Student(nullptr);
                        loadFromFile(fileName, temp);
                        createStudent(temp);
                    }
                    break;
                }
                case 7: {break;}
                default: {
                    throw invalid_argument("Invalid input");
                }
            }
        }
        catch (invalid_argument const &exception){
            cout << "Error! Invalid input, try all steps again!" << endl;
            continue;
        }
    }
}