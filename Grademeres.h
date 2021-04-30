//
// Created by Eugene on 26.04.2021.
//

#ifndef COURSEWORK_GRADEMERES_H
#define COURSEWORK_GRADEMERES_H


#include "OwnTypes.h"


class Grademeres {
    virtual int getNumberOfGrades(int grade) = 0;
    virtual int getNumberOfGrades(GRADE grade) = 0;
    virtual int getNumberOfSubjects() = 0;
};


#endif //COURSEWORK_GRADEMERES_H
