#include "Subject.h"
#include "Semester.h"
#include "Student.h"
#include <fstream>


int main() {

    auto *Ivan1 = new Student(
            "Alekseev",
            "Ivan",
            "Valeryevich",
            {16, 3, 1911},
            2020,
            "Informacionnih tehnologiy",
            "KB-3",
            "INBO-5-19",
            "19B6141",
            Male
            );
    cout << Ivan1->getFullName() << endl;

    +*Ivan1;
    *Ivan1->getSemester(1) + "Math";
    *Ivan1->getSemester(1) + "Programming";
    *Ivan1->getSemester(1) + "IT";
    Ivan1->getSemester(1)->printSubjects();
    Ivan1->getSemester(1)->getSubject("IT")->setGrade(5);
    Ivan1->getSemester(1)->getSubject("Math")->setGrade(INCOMPLETE);
    *Ivan1->getSemester(1) - "Programming";
    Ivan1->getSemester(1)->printSubjects();
    +*Ivan1;
    *Ivan1->getSemester(2) + "Physics";
    *Ivan1->getSemester(2) + "Math";
    *Ivan1->getSemester(2) + "IT";
    *Ivan1->getSemester(2) + "Special courses";
    Ivan1->getSemester(2)->getSubject("IT")->setGrade(5);
    Ivan1->getSemester(2)->getSubject("Math")->setGrade(4);
    Ivan1->getSemester(2)->getSubject("Special courses")->setGrade(COMPLETE);
    Ivan1->getSemester(2)->getSubject("Physics")->setGrade(5);
    +*Ivan1;
    *Ivan1 - 3;
    Ivan1->printInfo();

    delete Ivan1;

    return 0;
}
