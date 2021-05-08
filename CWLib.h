//
// Created by Eugene on 23.04.2021.
//

#ifndef COURSEWORK_CWLIB_H
#define COURSEWORK_CWLIB_H


#include <fstream>
#include "Subject.h"
#include "Semester.h"
#include "Student.h"
#include <algorithm>


int saveToFile(const string& path, Student* student);
inline int loadFromFile(const string& path, Student* student, ifstream* fin);
int createStudent(Student* value);
int deleteStudent(BothWayList* list);
int deleteAllStudents();
BothWayList* findStudent(string fullNameOrID);
BothWayList* findStudent(string fullNameOrID, unsigned short BDYearMin, unsigned short BDYearMax);
BothWayList* findStudent(unsigned short BDYearMin, unsigned short BDYearMax);
int printAllStudents();
int saveAllToFile(const string& fileName);
int loadAllFromFile(const string& fileName);
int sortStudents();

void menu();

Crypto* CWEncrypt(const char* toEncode);
Crypto* CWEncrypt(const char* toEncode, HCRYPTKEY hSessionKey);
char* CWDecrypt(const char* toDecode, HCRYPTKEY hSessionKey);


#endif //COURSEWORK_CWLIB_H
