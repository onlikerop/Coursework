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
    Allah->addSubject(1,"Sranina");
    Allah->addSubject(1,"Ebanina");
    Allah->addSubject(1,"Pizda Losya");
    Allah->getSemester(1)->printSubjects();
    Allah->getSemester(1)->getSubject("Ebanina")->setGrade(5);
    Allah->getSemester(1)->getSubject("Sranina")->setGrade(INCOMPLETE);
    Allah->getSemester(1)->printSubjects();

    return 0;
}
