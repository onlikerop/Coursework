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
                    cout << "This program is created by student of Information security specialization of" << endl;
                    cout << "group BBBO-05-20 Karabanov Evgeniy (Eugene) Gennadyevich. Personal ID: 20B0791" << endl;
                    cout << "as coursework of the 1st course for Russian Technological University MIREA" << endl << endl;
                    break;
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

int saveToFile(const string& path, Student* student, HCRYPTKEY key){
    FILE *file;
    fopen_s(&file, path.c_str(), "ab+");
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
            fclose(file);
            return 1;
        }
        fclose(file);
        return 0;
    }
}

inline int loadFromFile(const string& path, Student* student, FILE* file, BYTE *hPublicKey, DWORD hPublicKeyLen){
    if (!file){
        cout << "Error opening save-file for loading" << endl;
        return 1;
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

int saveAllToFile(string fileName) {
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
            else {
                cout << "Enter the name of the file in which you want to save list:" << endl;
                cin >> fileName;
                fileName += ".CW";
            }
        }
        else {
            flag = false;
            fin.close();
        }
    }
    if (BothWayList::pStart != nullptr) {
        HCRYPTPROV hProv;
        HCRYPTKEY hSessionKey;

        if(!CryptAcquireContext(&hProv, nullptr, nullptr, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)){
            cout << "Error, getting encryption context" << endl;
            return 1;
        }

        cout << "Cryptographic provider successfully initialized!" << endl;

        if(!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey)){
            cout << "Error, generating session key for encryption!" << endl;
            return 1;
        }
        cout << "Session key successfully generated!" << endl;
        BothWayList *pCurrent = BothWayList::pStart;
        while (pCurrent != nullptr) {
            saveToFile(fileName, pCurrent->value, hSessionKey);
            pCurrent = pCurrent->next;
        }
        DWORD dwPublicKeyLen;
        if (!CryptExportKey( hSessionKey, NULL,
                        SIMPLEBLOB, 0, NULL, &dwPublicKeyLen)) {
            cout << "Error, exporting key for encryption!" << endl;
            return 1;
        }
        BYTE* hPublicKey = static_cast<BYTE*>(malloc(dwPublicKeyLen));
        if (!CryptExportKey( hSessionKey, NULL,
                        SIMPLEBLOB, NULL, hPublicKey, &dwPublicKeyLen)){
            cout << "Error, exporting key for encryption!" << endl;
            return 1;
        }
        fout.open(fileName + ".hkey");
        fout.write(reinterpret_cast<char*>(&dwPublicKeyLen), sizeof(DWORD));
        fout.write(reinterpret_cast<char*>(&hPublicKey), dwPublicKeyLen);
        fout.close();
        CryptDestroyKey(hSessionKey);
    }
    else
        cout << "There is nothing to save to file!" << endl;
    return 0;
}

int loadAllFromFile(const string& fileName){

    DWORD hPublicKeyLen;
//    fin.open(fileName + ".hkey");
//    if (!fin.is_open()) {
//        cout << "File do not exist or it's damaged or it's protected by system!" << endl;
//        fin.close();
//        return 1;
//    }
//    fin.read(reinterpret_cast<char*>(&hPublicKeyLen), sizeof(DWORD));
    BYTE *hPublicKey = new BYTE[1];
//    fin.read(reinterpret_cast<char*>(&hPublicKey), hPublicKeyLen);
//    fin.close();

    FILE *file;
    fopen_s(&file, fileName.c_str(), "rb");
    if (!file) {
        cout << "File do not exist or it's damaged or it's protected by system!" << endl;
        return 1;
    }

    deleteAllStudents();
    int error = 0, count = 0;

    while (error == 0) {
        auto *temp = new Student(nullptr);
        error = loadFromFile(fileName, temp, file, hPublicKey, /*hPublicKeyLen*/NULL);
        if (!error){
            createStudent(temp);
            count++;
        }
        else{
            cout << "End of file or file is damaged. Removing temporary variable..." << "\n\t";
            delete temp;
        }
    }
    fclose(file);
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

Crypto* CWEncrypt(const char* toEncode) {
    HCRYPTPROV hProv;
    HCRYPTKEY hSessionKey;

    if(!CryptAcquireContext(&hProv, nullptr, nullptr, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)){
        cout << "Error, getting encryption context" << endl;
        return nullptr;
    }

    cout << "Cryptographic provider successfully initialized!" << endl;

    if(!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey)){
        cout << "Error, generating session key for encryption!" << endl;
        return nullptr;
    }
    cout << "Session key successfully generated!" << endl;
    char *tempString;
    tempString = new char[strlen(toEncode)];
    strcpy_s(tempString, strlen(tempString), toEncode);
    DWORD count = strlen(tempString);
    if(!CryptEncrypt(hSessionKey, NULL, true, NULL, reinterpret_cast<BYTE*>(tempString), &count, count)){
        cout << "Error, encrypting provided data" << endl;
        return nullptr;
    }
    DWORD hPublicKeyLen;
    CryptExportKey( hSessionKey, NULL,
                    SIMPLEBLOB, NULL, nullptr, &hPublicKeyLen);
    BYTE *hPublicKey = new BYTE[hPublicKeyLen];
    CryptExportKey( hSessionKey, NULL,
                    SIMPLEBLOB, NULL, hPublicKey, &hPublicKeyLen);
    auto response = new Crypto(tempString, hPublicKey);
    CryptDestroyKey(hSessionKey);
    return response;
}

Crypto* CWEncrypt(const char* toEncode, HCRYPTKEY hSessionKey) {
    char *tempString;
    tempString = new char[strlen(toEncode)];
    strcpy_s(tempString, strlen(tempString), toEncode);
    DWORD count = strlen(tempString);
    if(!CryptEncrypt(hSessionKey, NULL, true, NULL, reinterpret_cast<BYTE*>(tempString), &count, count)){
        cout << "Error, encrypting provided data" << endl;
        return nullptr;
    }
    DWORD hPublicKeyLen;
    CryptExportKey( hSessionKey, NULL,
                    SIMPLEBLOB, NULL, nullptr, &hPublicKeyLen);
    BYTE *hPublicKey = new BYTE[hPublicKeyLen];
    CryptExportKey( hSessionKey, NULL,
                    SIMPLEBLOB, NULL, hPublicKey, &hPublicKeyLen);
    auto response = new Crypto(tempString, hPublicKey);
    CryptDestroyKey(hSessionKey);
    return response;
}

char* CWDecrypt(const char* toDecode, BYTE *hPublicKey, DWORD hPublicKeyLen) {
    char *tempString;
    HCRYPTPROV hProv;
    HCRYPTKEY hSessionKey;

    if(!CryptAcquireContext(&hProv, nullptr, nullptr, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)){
        cout << "Error, getting encryption context" << endl;
        return nullptr;
    }

    cout << "Cryptographic provider successfully initialized!" << endl;

    tempString = new char[strlen(toDecode)];
    strcpy_s(tempString, strlen(tempString), toDecode);
    DWORD count = strlen(tempString);
    CryptImportKey(hProv, hPublicKey, hPublicKeyLen, NULL, NULL, &hSessionKey);
    if(!CryptDecrypt(hSessionKey, NULL, true, NULL, reinterpret_cast<BYTE*>(tempString), &count)){
        cout << "Error, decrypting provided data" << endl;
        return nullptr;
    }
    CryptDestroyKey(hSessionKey);
    return tempString;
}
