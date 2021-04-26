#include "Subject.h"
#include "Semester.h"
#include "Student.h"
#include "CWLib.h"


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    auto *Ivan1 = new Student(
            "Алексеев",
            "Иван",
            "Валерьевич",
            {16, 3, 1911},
            2020,
            "Информационных технологий",
            "КБ-3",
            "ИНБО-5-19",
            "19Б6141",
            Male
    );
    cout << Ivan1->getFullName() << endl;

    +*Ivan1;
    Ivan1->addSubject(1, "Math");
    Ivan1->addSubject(1, "Programming");
    Ivan1->addSubject(1, "IT");
    Ivan1->printSubjects(1);
    Ivan1->setGrade(1, "IT", 5);
    Ivan1->setGrade(1, "Math", INCOMPLETE);
    Ivan1->removeSubject(1, "Programming");
    Ivan1->printSubjects(1);
    +*Ivan1;
    Ivan1->addSubject(2, "Physics");
    Ivan1->addSubject(2, "Math");
    Ivan1->addSubject(2, "IT");
    Ivan1->addSubject(2, "Special courses");
    Ivan1->setGrade(2, "IT", 5);
    Ivan1->setGrade(2, "Math", 5);
    Ivan1->setGrade(2, "Special courses", COMPLETE);
    Ivan1->setGrade(2, "Physics", 5);
    +*Ivan1;
    *Ivan1 - 3;
    Ivan1->printInfo();

//    saveToFile("Ivan.CW", Ivan1);
//
//
//    Student* John;
//    loadFromFile("Ivan.CW", John);
//    John->printInfo();
//
//    delete John;
    delete Ivan1;

    return 0;
}
