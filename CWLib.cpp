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

int loadFromFile(const string& path, Student* student){ //Не работает!
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
