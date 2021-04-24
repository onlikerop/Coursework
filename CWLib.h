//
// Created by Eugene on 23.04.2021.
//

#ifndef COURSEWORK_CWLIB_H
#define COURSEWORK_CWLIB_H


#include <fstream>
#include "Subject.h"
#include "Semester.h"
#include "Student.h"


int saveToFile(const string &path, Student* student);
//Student loadFromFile(const string& path);


#endif //COURSEWORK_CWLIB_H
