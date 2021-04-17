#include "Subject.h"
#include "Semester.h"
#include "Student.h"
#include <fstream>


int main() {

    auto *Allah = new Student(
            "Allahov",
            "Allah",
            "Allahovich",
            {16, 3, 1911},
            2020,
            "Govna i palok",
            "KB-1",
            "OCHKO-45-20",
            "20B6141",
            Male
            );
    cout << Allah->getFullName() << endl;

    Allah->addSemester();
    Allah->getSemester(1)->addSubject("Sranina");
    Allah->getSemester(1)->addSubject("Ebanina");
    Allah->getSemester(1)->addSubject("Pizda Losya");
    Allah->getSemester(1)->printSubjects();
    Allah->getSemester(1)->getSubject("Ebanina")->setGrade(5);
    Allah->getSemester(1)->getSubject("Sranina")->setGrade(INCOMPLETE);
    Allah->getSemester(1)->removeSubject("Pizda Losya");
    Allah->getSemester(1)->printSubjects();
//    Allah->printInfo();

    delete Allah;

    return 0;
}
