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
int loadFromFile(const string& path, Student* student);
int createStudent(Student* value);
BothWayList* findStudent(string fullNameOrID);
BothWayList* findStudent(string fullNameOrID, unsigned short BDYearMin, unsigned short BDYearMax);
BothWayList* findStudent(unsigned short BDYearMin, unsigned short BDYearMax);

void menu();


#endif //COURSEWORK_CWLIB_H
