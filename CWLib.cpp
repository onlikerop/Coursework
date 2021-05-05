//
// Created by Eugene on 23.04.2021.
//

#include "CWLib.h"


int createStudent(Student* value){

    if (BothWayList::pStart == nullptr) {
        BothWayList::pStart = new BothWayList(nullptr, nullptr, value);
    }
    else{
        BothWayList* temp = BothWayList::pStart;
        while (temp != nullptr){
            double tempGrades3_1_2_sem = 0, tempAllGrades_1_2_sem = 0, valueGrades3_1_2_sem = 0, valueAllGrades_1_2_sem = 0;
            if (temp->value->getSemester(1) != nullptr) {
                tempGrades3_1_2_sem += temp->value->getSemester(1)->getNumberOfGrades(3);
                tempAllGrades_1_2_sem += temp->value->getSemester(1)->getNumberOfSubjects();
            }
            if (temp->value->getSemester(2) != nullptr) {
                tempGrades3_1_2_sem += temp->value->getSemester(2)->getNumberOfGrades(3);
                tempAllGrades_1_2_sem += temp->value->getSemester(2)->getNumberOfSubjects();
            }
            if (value->getSemester(1) != nullptr) {
                valueGrades3_1_2_sem += value->getSemester(1)->getNumberOfGrades(3);
                valueAllGrades_1_2_sem += value->getSemester(1)->getNumberOfSubjects();
            }
            if (value->getSemester(2) != nullptr) {
                valueGrades3_1_2_sem += value->getSemester(2)->getNumberOfGrades(3);
                valueAllGrades_1_2_sem += value->getSemester(2)->getNumberOfSubjects();
            }
            if ((tempGrades3_1_2_sem / tempAllGrades_1_2_sem) >= (valueGrades3_1_2_sem / valueAllGrades_1_2_sem)){
                if (temp->next != nullptr)
                    temp = temp->next;
                else{
                    auto *theNewOne = new BothWayList(temp, temp->next, value);
                    temp->next = theNewOne;
                    break;
                }
            }
            else{
                auto *theNewOne = new BothWayList(temp->previous, temp, value);
                if (temp->previous != nullptr)
                    temp->previous->next = theNewOne;
                else
                    BothWayList::pStart = theNewOne;
                temp->previous = theNewOne;
                break;
            }
        }

    }
    return 0;

}

int deleteStudent(BothWayList* list){
    if (list->previous != nullptr)
        list->previous->next = list->next;
    else
        BothWayList::pStart = list->next;
    if (list->next != nullptr)
        list->next->previous = list->previous;
    BothWayList::count--;
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
                && pCurrent->value->getBirthdate().year <= BDYearMax
               ) break;
            else pCurrent = pCurrent->next;


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
    while(choice != 8){
        try {
            cout << "Choose one the following menu item:"
                << endl << "1. Create new student"
                << endl << "2. Print list of all Students (may be very long, do it only on your own risk)"
                << endl << "3. Find student"
                << endl << "4. Save list to file"
                << endl << "5. Load list from file"
                << endl << "6. Credits"
                << endl << "7. Sorting"
                << endl << "8. Exit"
                << endl;
            cin >> choiceStr;
            choice = stoi(choiceStr);

            switch (choice) {
                case 1: { createStudent(new Student()); break; }
                case 2: { printAllStudents(); break; }
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
                            if (cin.get() != '\n')
                                cin.unget();
                            getline(cin, fullNameOrID);
                            foundStudent = findStudent(fullNameOrID);
                            break;
                        }
                        case 2: {
                            string fullNameOrID, minYearStr, maxYearStr;
                            int minYear, maxYear;
                            cout << "Enter full name or ID of the Student:" << endl;
                            if (cin.get() != '\n')
                                cin.unget();
                            getline(cin, fullNameOrID);
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
                            case 3: { continue; }
                            default: {cout << "ERROR! Unknown menu item, skipping!" << endl;}
                        }
                    }
                    break;
                }
                case 4: {
                    string fileName;
                    cout << "Enter the name of the file in which you want to save list:" << endl;
                    cin >> fileName;
                    fileName += ".CW";
                    saveAllToFile(fileName);
                    break;
                }
                case 5: {
                    string fileName;
                    bool flag = true;
                    while (flag) {
                        cout << "Enter the name of the file in which you want to load from:" << endl;
                        cin >> fileName;
                        fileName += ".CW";
                        flag = static_cast<bool>(loadAllFromFile(fileName));
                    }
                    break;
                }
                case 6: {
                    cout << endl << "\t\tCREDITS" << endl;
                    cout << "\tProgram is created by student of Information security specialization" << endl;
                    cout << "\tgroup BBBO-05-20 Karabanov Evgeniy (Eugene) Gennadyevich. Personal ID: 20B0791" << endl;
                    cout << "\tas coursework of 1st course for Russian Technical University MIREA" << endl << endl;
                }
                case 7: {
                    switch (sortStudents()){
                        case 0: { cout << "Successfully sorted students!" << endl; break; }
                        case 1: { cout << "ERROR! There is nothing to sort!" << endl; break; }
                        default: { cout << "ERROR! Unknown error!" << endl; }
                    }
                }
                case 8: { break; }
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
            unsigned int temp_size = student->name.Second.size();
            fout.write(reinterpret_cast<char *>(&temp_size), sizeof(int));
            for(int i = 0; i < temp_size; i++)
                fout.write(reinterpret_cast<char *>(&(student->name.Second[i])), 1);
            temp_size = student->name.First.size();
            fout.write(reinterpret_cast<char *>(&temp_size), sizeof(int));
            for(int i = 0; i < temp_size; i++)
                fout.write(reinterpret_cast<char *>(&(student->name.First[i])), 1);
            temp_size = student->name.Third.size();
            fout.write(reinterpret_cast<char *>(&temp_size), sizeof(int));
            for(int i = 0; i < temp_size; i++)
                fout.write(reinterpret_cast<char *>(&(student->name.Third[i])), 1);
            fout.write(reinterpret_cast<char *>(&(student->BDate.day)), sizeof(unsigned short));
            fout.write(reinterpret_cast<char *>(&(student->BDate.month)), sizeof(unsigned short));
            fout.write(reinterpret_cast<char *>(&(student->BDate.year)), sizeof(unsigned short));
            fout.write(reinterpret_cast<char *>(&(student->university.receiptYear)), sizeof(unsigned short));
            temp_size = student->university.faculty.size();
            fout.write(reinterpret_cast<char *>(&temp_size), sizeof(int));
            for(int i = 0; i < temp_size; i++)
                fout.write(reinterpret_cast<char *>(&(student->university.faculty[i])), 1);
            temp_size = student->university.department.size();
            fout.write(reinterpret_cast<char *>(&temp_size), sizeof(int));
            for(int i = 0; i < temp_size; i++)
                fout.write(reinterpret_cast<char *>(&(student->university.department[i])), 1);
            temp_size = student->university.group.size();
            fout.write(reinterpret_cast<char *>(&temp_size), sizeof(int));
            for(int i = 0; i < temp_size; i++)
                fout.write(reinterpret_cast<char *>(&(student->university.group[i])), 1);
            temp_size = student->university.IDCard.size();
            fout.write(reinterpret_cast<char *>(&temp_size), sizeof(int));
            for(int i = 0; i < temp_size; i++)
                fout.write(reinterpret_cast<char *>(&(student->university.IDCard[i])), 1);
            fout.write(reinterpret_cast<char *>(&(student->sex)), sizeof(SEX));
            for (auto semester : student->semesters){
                fout.write(reinterpret_cast<char *>(&(semester.is_active_)), sizeof(bool));
                for (auto subject : semester.subjects){
                    fout.write(reinterpret_cast<char *>(&(subject.is_active_)), sizeof(bool));
                    temp_size = subject.name.size();
                    fout.write(reinterpret_cast<char *>(&temp_size), sizeof(int));
                    for(int i = 0; i < temp_size; i++)
                        fout.write(reinterpret_cast<char *>(&(subject.name[i])), 1);
                    fout.write(reinterpret_cast<char *>(&(subject.grade)), sizeof(GRADE));
                }
            }
            cout << "Successfully saved data into \'" << path << "\'" << endl;
            fout.close();
        }
        catch (...){
            fout.close();
            return 1;
        }
        return 0;
    }
}

inline int loadFromFile(const string& path, Student* student, ifstream* fin){
    if (!fin->is_open()){
        cout << "Error opening save-file for loading" << endl;
        return 1;
    }
    else{
        try {
            unsigned int temp_size;
            fin->read(reinterpret_cast<char *>(&temp_size), sizeof(int));
            student->name.Second.resize(temp_size);
            for(int i = 0; i < temp_size; i++)
                fin->read(reinterpret_cast<char *>(&(student->name.Second[i])), 1);
            fin->read(reinterpret_cast<char *>(&temp_size), sizeof(int));
            student->name.First.resize(temp_size);
            for(int i = 0; i < temp_size; i++)
                fin->read(reinterpret_cast<char *>(&(student->name.First[i])), 1);
            fin->read(reinterpret_cast<char *>(&temp_size), sizeof(int));
            student->name.Third.resize(temp_size);
            for(int i = 0; i < temp_size; i++)
                fin->read(reinterpret_cast<char *>(&(student->name.Third[i])), 1);
            fin->read(reinterpret_cast<char *>(&(student->BDate.day)), sizeof(unsigned short));
            fin->read(reinterpret_cast<char *>(&(student->BDate.month)), sizeof(unsigned short));
            fin->read(reinterpret_cast<char *>(&(student->BDate.year)), sizeof(unsigned short));
            fin->read(reinterpret_cast<char *>(&(student->university.receiptYear)), sizeof(unsigned short));
            fin->read(reinterpret_cast<char *>(&temp_size), sizeof(int));
            student->university.faculty.resize(temp_size);
            for(int i = 0; i < temp_size; i++)
                fin->read(reinterpret_cast<char *>(&(student->university.faculty[i])), 1);
            fin->read(reinterpret_cast<char *>(&temp_size), sizeof(int));
            student->university.department.resize(temp_size);
            for(int i = 0; i < temp_size; i++)
                fin->read(reinterpret_cast<char *>(&(student->university.department[i])), 1);
            fin->read(reinterpret_cast<char *>(&temp_size), sizeof(int));
            student->university.group.resize(temp_size);
            for(int i = 0; i < temp_size; i++)
                fin->read(reinterpret_cast<char *>(&(student->university.group[i])), 1);
            fin->read(reinterpret_cast<char *>(&temp_size), sizeof(int));
            student->university.IDCard.resize(temp_size);
            for(int i = 0; i < temp_size; i++)
                fin->read(reinterpret_cast<char *>(&(student->university.IDCard[i])), 1);
            fin->read(reinterpret_cast<char *>(&(student->sex)), sizeof(SEX));
            for (int semester = 0; semester < 9; semester++){
                fin->read(reinterpret_cast<char *>(&(student->semesters[semester].is_active_)), sizeof(bool));
                for (int subject = 0; subject < 10; subject++){
                    fin->read(reinterpret_cast<char *>(&(student->semesters[semester].subjects[subject].is_active_)), sizeof(bool));
                    fin->read(reinterpret_cast<char *>(&temp_size), sizeof(int));
                    student->semesters[semester].subjects[subject].name.resize(temp_size);
                    for(int i = 0; i < temp_size; i++)
                        fin->read(reinterpret_cast<char *>(&(student->semesters[semester].subjects[subject].name[i])), 1);
                    fin->read(reinterpret_cast<char *>(&(student->semesters[semester].subjects[subject].grade)), sizeof(GRADE));
                }
            }
            if (SEXToString(student->sex) == "Error displaying the sex")
                throw exception();
            cout << "Successfully loaded data from \'" << path << "\'" << endl;
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
        fin.close();
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
            cout << "Successfully loaded data from \'" << path << "\'" << endl;
            fin.close();
        }
        catch (...){
            fin.close();
            return 1;
        }
        return 0;
    }

}

int printAllStudents() {
    BothWayList* pCurrent = BothWayList::pStart;
    if (pCurrent == nullptr)
        cout << "There is no any student. Make sure, you loaded data from file or created at least one student!" << endl;
    while(pCurrent != nullptr){
        pCurrent->value->printInfo();
        cout << endl;
        pCurrent = pCurrent->next;
    }
    return 0;
}

int saveAllToFile(const string& fileName) {
    bool flag = true;
    ofstream fout;

    while (flag){
        ifstream fin;
        fin.open(fileName);
        if (fin.is_open()){
            string wanna;
            cout << "This file is already exist, do you really want to rewrite all data inside it? (Y/N):" << endl;
            cin >> wanna;
            if (wanna == "Y" || wanna == "y"){
                flag = false;
                fin.close();
                remove(fileName.c_str());
            }
        }
        else {
            flag = false;
            fin.close();
        }
    }

    BothWayList* pCurrent = BothWayList::pStart;
    while (pCurrent != nullptr) {
        saveToFile(fileName, pCurrent->value);
        pCurrent = pCurrent->next;
    }
    return 0;
}

int loadAllFromFile(const string& fileName){
    ifstream fin;

    fin.open(fileName);
    if (!fin.is_open()) {
        cout << "File do not exist or it's damaged or it's protected by system!" << endl;
        fin.close();
        return 1;
    }

    deleteAllStudents();
    int error = 0, count = 0;
    while (!fin.eof() && error == 0) {
        auto *temp = new Student(nullptr);
        error = loadFromFile(fileName, temp, &fin);
        if (!error){
            createStudent(temp);
            count++;
        }
        else{
            cout << "End of file. Removing temporary variable..." << "\n\t";
            delete temp;
        }
    }
    fin.close();
    cout << "Loaded " << count << " students from file" << endl;
    return 0;
}

int sortStudents() {
    unsigned int local_count = BothWayList::count;
    if (local_count < 2)
        return 1;
    try{
        void **temp = new void*[local_count];
        for (int i = 0; i < local_count; i++)
            temp[i] = malloc(sizeof(Student));
        BothWayList *pCurrent = BothWayList::pStart;
        cout << "Starting sorting...\n\tCreating backup for current student's data..." << endl;
        for (int i = 0; i < local_count; i++) {
            temp[i] = pCurrent->value;
            pCurrent = pCurrent->next;
        }
        cout << "\tClearing student's data..." << endl;
        deleteAllStudents();
        cout << "\tLoading data for sorting..." << endl;
        for (int i = 0; i < local_count; i++) {
            createStudent(static_cast<Student *>(temp[i]));
        }
        delete[] temp;
        return 0;
    }
    catch (exception &e){
        return sizeof(*e.what());
    }

}
