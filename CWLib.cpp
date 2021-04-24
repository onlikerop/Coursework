//
// Created by Eugene on 23.04.2021.
//

#include "CWLib.h"


int saveToFile(string path, Student* student){
    ofstream fout;
    fout.open(path, ofstream::app);
    if (!fout.is_open()){
        cout << "Error opening save-file" << endl;
        fout.close();
        return 1;
    }
    else{
        try {
            fout.write(reinterpret_cast<char*>(&student), sizeof(Student));
            fout.close();
        }
        catch (...){
            return 1;
        }
        return 0;
    }

}

//Student loadFromFile(string path){ //Не работает!
//    ifstream fin;
//    fin.open(path, ios_base::in);
//    Student student(nullptr);
//    if (!fin.is_open()){
//        cout << "Error opening save-file" << endl;
//        return student;
//    }
//    else{
//        try {
//            fin.read(reinterpret_cast<char*>(&student), sizeof(Student));
//            fin.close();
//        }
//        catch (...){
//            return student;
//        }
//        return student;
//    }
//
//}
