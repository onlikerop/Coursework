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


inline int saveToFile(const string& path, Student* student, FILE* file);
inline int loadFromFile(const string& path, Student* student, FILE* file);
int createStudent(Student* value, const char* fileName);
int deleteStudent(Student *student, const char* fileName);
int deleteStudent(const char* IDCard, const char* fileName);
Student* findStudent(string fullNameOrID, const char* fileName);
Student* findStudent(string fullNameOrID, unsigned short BDYearMin, unsigned short BDYearMax, const char* fileName);
Student* findStudent(unsigned short BDYearMin, unsigned short BDYearMax, const char* fileName);
int printAllStudents(const char* fileName);

void menu(const char* fileName);

int CWEncrypt(char* toEncode, HCRYPTKEY hSessionKey);
int CWDecrypt(char* toDecode, HCRYPTKEY hSessionKey);


#endif //COURSEWORK_CWLIB_H
