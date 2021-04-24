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
            fout.write(reinterpret_cast<char*>(&student), sizeof(Student));
            fout.close();
            cout << "Successfully saved data into \'" << path << "\'" << endl;
        }
        catch (...){
            return 1;
        }
        return 0;
    }

}

//Student loadFromFile(const string& path){ //Не работает!
//    ifstream fin;
//    fin.open(path, ios_base::in);
//    Student student(nullptr);
//    if (!fin.is_open()){
//        cout << "Error opening save-file for loading" << endl;
//        return student;
//    }
//    else{
//        try {
//            fin.read(reinterpret_cast<char*>(&student), sizeof(Student));
//            fin.close();
//            cout << "Successfully loaded data from \'" << path << "\'" << endl;
//        }
//        catch (...){
//            return student;
//        }
//        return student;
//    }
//
//}
