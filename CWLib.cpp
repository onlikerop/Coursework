//
// Created by Eugene on 23.04.2021.
//

#include "CWLib.h"


int createStudent(Student* value, const char* fileName){
    FILE *file;
    fopen_s(&file, fileName, "rb");
    int err = 0;
    auto *temp = new Student(nullptr);
    while(!err){
        err = loadFromFile(fileName, temp, file);
        if (temp->getID() == value->getID()){
            cout << "Error, saving added student! A student with such ID already exists!" << endl;
            return 1;
        }
    }
    fseek(file, 0, SEEK_SET);
    long prevPosition = 0;
    FILE* tempFile;
    string tempName = fileName;
    tempName += ".tmp";
    fopen_s(&tempFile, tempName.c_str(), "wb+");
    double tempGrades3_1_2_sem = 0, tempAllGrades_1_2_sem = 0, valueGrades3_1_2_sem = 0, valueAllGrades_1_2_sem = 0;

    if (value->getSemester(1) != nullptr) {
        valueGrades3_1_2_sem += value->getSemester(1)->getNumberOfGrades(3);
        valueAllGrades_1_2_sem += value->getSemester(1)->getNumberOfSubjects();
    }
    if (value->getSemester(2) != nullptr) {
        valueGrades3_1_2_sem += value->getSemester(2)->getNumberOfGrades(3);
        valueAllGrades_1_2_sem += value->getSemester(2)->getNumberOfSubjects();
    }
    if (valueAllGrades_1_2_sem != 0){
        do {
            tempGrades3_1_2_sem = 0; tempAllGrades_1_2_sem = 0;
            prevPosition = ftell(file);
            err = loadFromFile(fileName, temp, file);
            if (temp->getSemester(1) != nullptr) {
                tempGrades3_1_2_sem += temp->getSemester(1)->getNumberOfGrades(3);
                tempAllGrades_1_2_sem += temp->getSemester(1)->getNumberOfSubjects();
            }
            if (temp->getSemester(2) != nullptr) {
                tempGrades3_1_2_sem += temp->getSemester(2)->getNumberOfGrades(3);
                tempAllGrades_1_2_sem += temp->getSemester(2)->getNumberOfSubjects();
            }
        } while ((tempGrades3_1_2_sem / tempAllGrades_1_2_sem) >= (valueGrades3_1_2_sem / valueAllGrades_1_2_sem) &&!err);
    }
    fseek(file, 0, SEEK_SET);
    for (long i = 0; i < prevPosition; i++){
        fputc(fgetc(file), tempFile);
    }
    saveToFile(tempName, value, tempFile);

    fseek(file, prevPosition, SEEK_SET);
    while (!feof(file)){
        int tmp = fgetc(file);
        if (tmp != EOF)
            fputc(tmp, tempFile);
    }
    fclose(file);
    fopen_s(&file, fileName, "wb+");
    fseek(tempFile, 0, SEEK_SET);
    while (!feof(tempFile)){
        int tmp = fgetc(tempFile);
        if (tmp != EOF)
            fputc(tmp, file);
    }
    fclose(file);
    fclose(tempFile);
    remove(tempName.c_str());

    delete temp;
    return 0;

}

int deleteStudent(Student *student, const char* fileName){
    FILE *file;
    fopen_s(&file, fileName, "rb+");
    if (!file){
        cout << "Error opening save-file for loading" << endl;
        return 1;
    }
    auto *temp = new Student(nullptr);
    long prevPosition, currPosition;
    do{
        prevPosition = ftell(file);
        int err = loadFromFile(fileName, temp, file);
        currPosition = ftell(file);
        if (err){
            fclose(file);
            return err;
        }
    } while(student->getID() != temp->getID());
    FILE* tempFile;
    string tempName = fileName;
    tempName += ".tmp";
    fopen_s(&tempFile, tempName.c_str(), "wb+");
    fseek(file, 0, SEEK_SET);
    for (long i = 0; i < prevPosition; i++){
        fputc(fgetc(file), tempFile);
    }
    fseek(file, currPosition, SEEK_SET);
    while (!feof(file)){
        int tmp = fgetc(file);
        if (tmp != EOF)
            fputc(tmp, tempFile);
    }
    fclose(file);
    fopen_s(&file, fileName, "wb+");
    fseek(tempFile, 0, SEEK_SET);
    while (!feof(tempFile)){
        int tmp = fgetc(tempFile);
        if (tmp != EOF)
            fputc(tmp, file);
    }
    fclose(file);
    fclose(tempFile);
    remove(tempName.c_str());

    delete temp;
    return 0;
}

int deleteStudent(const char* IDCard, const char* fileName){
    FILE *file;
    fopen_s(&file, fileName, "rb+");
    if (!file){
        cout << "Error opening save-file for loading" << endl;
        return 1;
    }
    auto *temp = new Student(nullptr);
    long prevPosition, currPosition;
    do{
        prevPosition = ftell(file);
        int err = loadFromFile(fileName, temp, file);
        currPosition = ftell(file);
        if (err){
            fclose(file);
            return err;
        }
    } while(IDCard != temp->getID());
    FILE* tempFile;
    string tempName = fileName;
    tempName += ".tmp";
    fopen_s(&tempFile, tempName.c_str(), "wb+");
    fseek(file, 0, SEEK_SET);
    for (long i = 0; i < prevPosition; i++){
        fputc(fgetc(file), tempFile);
    }
    fseek(file, currPosition, SEEK_SET);
    while (!feof(file)){
        int tmp = fgetc(file);
        if (tmp != EOF)
            fputc(tmp, tempFile);
    }
    fclose(file);
    fopen_s(&file, fileName, "wb+");
    fseek(tempFile, 0, SEEK_SET);
    while (!feof(tempFile)){
        int tmp = fgetc(tempFile);
        if (tmp != EOF)
            fputc(tmp, file);
    }
    fclose(file);
    fclose(tempFile);
    remove(tempName.c_str());

    delete temp;
    return 0;
}

Student* findStudent(string fullNameOrID, const char* fileName){
    FILE *file;
    fopen_s(&file, fileName, "rb+");
    if (!file){
        cout << "Error opening save-file for loading" << endl;
        return nullptr;
    }
    string goNext = "Y";

    auto *temp = new Student(nullptr);
    int err = 0;

    while(goNext == "Y" || goNext == "y") {

        while (true){
            if (feof(file) || err){
                cout << "Student not found!" << endl;
                fclose(file);
                return nullptr;
            }
            err = loadFromFile(fileName, temp, file);
            string currName = temp->getFullName();
            string currID = temp->getID();
            transform(currID.begin(), currID.end(), currID.begin(), tolower);
            transform(currName.begin(), currName.end(), currName.begin(), tolower);
            transform(fullNameOrID.begin(), fullNameOrID.end(), fullNameOrID.begin(), tolower);
            if (currName == fullNameOrID || currID == fullNameOrID)
                break;
        }

        cout << "We found this item: " << endl;
        temp->printInfo();
        cout << endl << "Wanna try next one? (Y/N)" << endl;
        cin >> goNext;

        if (goNext == "Y")
            err = loadFromFile(fileName, temp, file);

    }

    fclose(file);
    return temp;
}

Student* findStudent(string fullNameOrID, unsigned short BDYearMin, unsigned short BDYearMax, const char* fileName){
    FILE *file;
    fopen_s(&file, fileName, "rb+");
    if (!file){
        cout << "Error opening save-file for loading" << endl;
        return nullptr;
    }
    string goNext = "Y";

    auto *temp = new Student(nullptr);
    int err = 0;

    while(goNext == "Y" || goNext == "y") {

        while (true){
            if (feof(file) || err){
                cout << "Student not found!" << endl;
                fclose(file);
                return nullptr;
            }
            err = loadFromFile(fileName, temp, file);
            string currName = temp->getFullName();
            string currID = temp->getID();
            transform(currID.begin(), currID.end(), currID.begin(), tolower);
            transform(currName.begin(), currName.end(), currName.begin(), tolower);
            transform(fullNameOrID.begin(), fullNameOrID.end(), fullNameOrID.begin(), tolower);
            if ((currName == fullNameOrID || currID == fullNameOrID)
                && temp->getBirthdate().year >= BDYearMin
                && temp->getBirthdate().year <= BDYearMax
               )
                break;

        }

        cout << "We found this item: " << endl;
        temp->printInfo();
        cout << endl << "Wanna try next one? (Y/N)" << endl;
        cin >> goNext;

        if (goNext == "Y")
            err = loadFromFile(fileName, temp, file);

    }

    fclose(file);
    return temp;
}

Student* findStudent(unsigned short BDYearMin, unsigned short BDYearMax, const char* fileName){
    FILE *file;
    fopen_s(&file, fileName, "rb+");
    if (!file){
        cout << "Error opening save-file for loading" << endl;
        return nullptr;
    }
    string goNext = "Y";

    auto *temp = new Student(nullptr);
    int err = 0;

    while(goNext == "Y" || goNext == "y") {

        while (true){
            if (feof(file) || err){
                cout << "Student not found!" << endl;
                fclose(file);
                return nullptr;
            }
            err = loadFromFile(fileName, temp, file);
            if (temp->getBirthdate().year >= BDYearMin && temp->getBirthdate().year <= BDYearMax)
                break;

        }

        cout << "We found this item: " << endl;
        temp->printInfo();
        cout << endl << "Wanna try next one? (Y/N)" << endl;
        cin >> goNext;

        if (goNext == "Y")
            err = loadFromFile(fileName, temp, file);

    }

    fclose(file);
    return temp;
}

void menu(const char* fileName){
    string choiceStr;
    int choice = -1;
    while(choice != 5){
        try {
            cout << "Choose one the following menu item:"
                << endl << "1. Create new student"
                << endl << "2. Print list of all Students (may be very long)"
                << endl << "3. Find student"
                << endl << "4. Credits"
                << endl << "5. Exit"
                << endl;
            cin >> choiceStr;
            choice = stoi(choiceStr);

            switch (choice) {
                case 1: { createStudent(new Student(), fileName); break; }
                case 2: { printAllStudents(fileName); break; }
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

                    Student* foundStudent;

                    switch (choice2) {
                        case 1: {
                            string fullNameOrID;
                            cout << "Enter full name or ID of the Student:" << endl;
                            if (cin.get() != '\n')
                                cin.unget();
                            getline(cin, fullNameOrID);
                            foundStudent = findStudent(fullNameOrID, fileName);
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
                            foundStudent = findStudent(fullNameOrID, minYear, maxYear, fileName);
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
                            foundStudent = findStudent(minYear, maxYear, fileName);
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
                            case 1: {
                                string backupIDCard = foundStudent->getID();
                                foundStudent->editInfo();
                                FILE *file;
                                fopen_s(&file, fileName, "rb+");
                                if (!file){
                                    cout << "Error opening save-file for loading" << endl;
                                    break;
                                }
                                auto *temp = new Student(nullptr);
                                int err = 0;
                                bool flag = false;
                                if (foundStudent->getID() != backupIDCard) {
                                    while (!err) {
                                        err = loadFromFile(fileName, temp, file);
                                        if (temp->getID() == foundStudent->getID()) {
                                            cout << "Error, saving added student! A student with such ID already exists!" << endl;
                                            flag = true;
                                            break;
                                        }
                                    }
                                    if (flag) {
                                        fclose(file);
                                        break;
                                    }
                                }
                                deleteStudent(backupIDCard.c_str(), fileName);
                                fseek(file, 0, SEEK_SET);
                                long prevPosition = 0;
                                FILE* tempFile;
                                string tempName = fileName;
                                tempName += ".tmp";
                                fopen_s(&tempFile, tempName.c_str(), "wb+");
                                double tempGrades3_1_2_sem = 0, tempAllGrades_1_2_sem = 0, valueGrades3_1_2_sem = 0, valueAllGrades_1_2_sem = 0;
                                if (foundStudent->getSemester(1) != nullptr) {
                                    valueGrades3_1_2_sem += foundStudent->getSemester(1)->getNumberOfGrades(3);
                                    valueAllGrades_1_2_sem += foundStudent->getSemester(1)->getNumberOfSubjects();
                                }
                                if (foundStudent->getSemester(2) != nullptr) {
                                    valueGrades3_1_2_sem += foundStudent->getSemester(2)->getNumberOfGrades(3);
                                    valueAllGrades_1_2_sem += foundStudent->getSemester(2)->getNumberOfSubjects();
                                }
                                if (valueAllGrades_1_2_sem != 0){
                                    do {
                                        tempGrades3_1_2_sem = 0; tempAllGrades_1_2_sem = 0;
                                        prevPosition = ftell(file);
                                        err = loadFromFile(fileName, temp, file);
                                        if (temp->getSemester(1) != nullptr) {
                                            tempGrades3_1_2_sem += temp->getSemester(1)->getNumberOfGrades(3);
                                            tempAllGrades_1_2_sem += temp->getSemester(1)->getNumberOfSubjects();
                                        }
                                        if (temp->getSemester(2) != nullptr) {
                                            tempGrades3_1_2_sem += temp->getSemester(2)->getNumberOfGrades(3);
                                            tempAllGrades_1_2_sem += temp->getSemester(2)->getNumberOfSubjects();
                                        }
                                    } while ((tempGrades3_1_2_sem / tempAllGrades_1_2_sem) >= (valueGrades3_1_2_sem / valueAllGrades_1_2_sem) &&!err);
                                }
                                fseek(file, 0, SEEK_SET);
                                for (long i = 0; i < prevPosition; i++){
                                    fputc(fgetc(file), tempFile);
                                }
                                saveToFile(tempName, foundStudent, tempFile);

                                while (!feof(file)){
                                    int tmp = fgetc(file);
                                    if (tmp != EOF)
                                        fputc(tmp, tempFile);
                                }
                                fclose(file);
                                fopen_s(&file, fileName, "wb+");
                                fseek(tempFile, 0, SEEK_SET);
                                while (!feof(tempFile)){
                                    int tmp = fgetc(tempFile);
                                    if (tmp != EOF)
                                        fputc(tmp, file);
                                }
                                fclose(file);
                                fclose(tempFile);
                                remove(tempName.c_str());

                                delete temp;
                                break;
                            }
                            case 2: { deleteStudent(foundStudent, fileName); break; }
                            case 3: { continue; }
                            default: { cout << "ERROR! Unknown menu item, skipping!" << endl; }
                        }
                    }
                    break;
                }
                case 4: {
                    cout << endl << "\t\tCREDITS" << endl;
                    cout << "This program is developed by student of Information security specialization of" << endl;
                    cout << "group BBBO-05-20 Karabanov Evgeniy (Eugene) Gennadyevich. Personal ID: 20B0791" << endl;
                    cout << "as coursework of the 1st course for Russian Technological University MIREA" << endl << endl;
                    break;
                }
                case 5: { break; }
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

inline int saveToFile(const string& path, Student* student, FILE* file){
    if (!file){
        cout << "Error opening save-file for saving" << endl;
        return 1;
    }
    else{
        try {
            int temp_size = student->name.Second.size();
            fputc(temp_size, file);
            fputs(student->name.Second.c_str(), file);
            temp_size = student->name.First.size();
            fputc(temp_size, file);
            fputs(student->name.First.c_str(), file);
            temp_size = student->name.Third.size();
            fputc(temp_size, file);
            fputs(student->name.Third.c_str(), file);

            string temp0;

            temp0 = reinterpret_cast<char *>(&student->BDate.day);
            temp0.resize(sizeof(unsigned short));
            for (int i = 0; i < sizeof(unsigned short); i++)
                fputc(temp0[i], file);

            temp0 = reinterpret_cast<char *>(&student->BDate.month);
            temp0.resize(sizeof(unsigned short));
            for (int i = 0; i < sizeof(unsigned short); i++)
                fputc(temp0[i], file);

            temp0 = reinterpret_cast<char *>(&student->BDate.year);
            temp0.resize(sizeof(unsigned short));
            for (int i = 0; i < sizeof(unsigned short); i++)
                fputc(temp0[i], file);

            temp0 = reinterpret_cast<char *>(&student->university.receiptYear);
            temp0.resize(sizeof(unsigned short));
            for (int i = 0; i < sizeof(unsigned short); i++)
                fputc(temp0[i], file);

            temp_size = student->university.faculty.size();
            fputc(temp_size, file);
            fputs(student->university.faculty.c_str(), file);
            temp_size = student->university.department.size();
            fputc(temp_size, file);
            fputs(student->university.department.c_str(), file);
            temp_size = student->university.group.size();
            fputc(temp_size, file);
            fputs(student->university.group.c_str(), file);
            temp_size = student->university.IDCard.size();
            fputc(temp_size, file);
            fputs(student->university.IDCard.c_str(), file);
            string temp = SEXToString(student->sex);
            temp_size = temp.size();
            fputc(temp_size, file);
            fputs(temp.c_str(), file);
            for (auto & semester : student->semesters){
                fputc(semester.is_active_, file);
                for (auto & subject : semester.subjects){
                    fputc(subject.is_active_, file);
                    temp_size = subject.name.size();
                    fputc(temp_size, file);
                    fputs(subject.name.c_str(), file);
                    temp = GRADEToString(subject.grade);
                    temp_size = temp.size();
                    fputc(temp_size, file);
                    fputs(temp.c_str(), file);
                }
            }
        }
        catch (...){
            return 1;
        }
        return 0;
    }
}

inline int loadFromFile(const string& path, Student* student, FILE* file){
    if (!file){
        cout << "Error opening save-file for loading (or program met end of file)" << endl;
        return 1;
    }
    else if(feof(file)){
        return 2;
    }
    else{
        try {
            int temp_size;
            char* temp;

            temp_size = fgetc(file);
            temp = new char[temp_size];
            fgets(temp, temp_size + 1, file);
            student->name.Second = temp;

            temp_size = fgetc(file);
            temp = new char[temp_size];
            fgets(temp, temp_size + 1, file);
            student->name.First = temp;

            temp_size = fgetc(file);
            temp = new char[temp_size];
            fgets(temp, temp_size + 1, file);
            student->name.Third = temp;


            fgets(reinterpret_cast<char *>(&student->BDate.day), sizeof(unsigned short) + 1, file);
            fgets(reinterpret_cast<char *>(&student->BDate.month), sizeof(unsigned short) + 1, file);
            fgets(reinterpret_cast<char *>(&student->BDate.year), sizeof(unsigned short) + 1, file);

            fgets(reinterpret_cast<char *>(&student->university.receiptYear), sizeof(unsigned short) + 1, file);

            temp_size = fgetc(file);
            temp = new char[temp_size];
            fgets(temp, temp_size + 1, file);
            student->university.faculty = temp;

            temp_size = fgetc(file);
            temp = new char[temp_size];
            fgets(temp, temp_size + 1, file);
            student->university.department = temp;

            temp_size = fgetc(file);
            temp = new char[temp_size];
            fgets(temp, temp_size + 1, file);
            student->university.group = temp;

            temp_size = fgetc(file);
            temp = new char[temp_size];
            fgets(temp, temp_size + 1, file);
            student->university.IDCard = temp;

            temp_size = fgetc(file);
            temp = new char[temp_size];
            fgets(temp, temp_size + 1, file);
            student->sex = stringToSEX(temp);
            for (auto &semester : student->semesters) {
                semester.is_active_ = fgetc(file);
                for (auto &subject : semester.subjects) {
                    subject.is_active_ = fgetc(file);

                    temp_size = fgetc(file);
                    temp = new char[temp_size];
                    fgets(temp, temp_size + 1, file);
                    subject.name = temp;

                    temp_size = fgetc(file);
                    temp = new char[temp_size];
                    fgets(temp, temp_size + 1, file);
                    subject.grade = StringToGRADE(temp);
                }
            }
        }
        catch (...){
            return 1;
        }
        return 0;
    }
}

int printAllStudents(const char* fileName) {
    FILE* file;
    fopen_s(&file, fileName, "rb");
    if (!file){
        cout << "Error opening save-file for loading" << endl;
    }
    int tmpChar = fgetc(file);
    if (tmpChar == EOF) {
        cout << "There is no any student. Make sure, you've created at least one student!" << endl;
        fclose(file);
        return 0;
    }
    ungetc(tmpChar, file);
    auto *temp = new Student(nullptr);
    while(!feof(file)){
        int err = loadFromFile(fileName, temp, file);
        if (temp->getSex() == Undefined)
            err = 3;
        if (err)
            break;
        if (temp->getNumberOfSubjects()) {
            temp->printInfo();
            cout << endl;
        }
    }
    fclose(file);
    delete temp;
    return 0;
}


// CRYPTOGRAPHY
int CWEncrypt(char* toEncode, HCRYPTKEY hSessionKey) {
    DWORD count = 1;
    if(!CryptEncrypt(hSessionKey, NULL, true, NULL, reinterpret_cast<BYTE*>(toEncode), &count, count)){
        cout << "Error, encrypting provided data: " << GetLastError() << endl;
        return 1;
    }
    return 0;
}

int CWDecrypt(char* toDecode, HCRYPTKEY hSessionKey) {
    DWORD count = 1;
    if(!CryptDecrypt(hSessionKey, NULL, true, NULL, reinterpret_cast<BYTE*>(toDecode), &count)){
        cout << "Error, decrypting provided data" << endl;
        return 1;
    }
    return 0;
}
