#include "Subject.h"
#include "Semester.h"
#include "Student.h"
#include "CWLib.h"


int BothWayList::count = 0;
BothWayList* BothWayList::pStart = nullptr;


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
//    auto *Ivan1 = new Student(
//            "Alekseev",
//            "John",
//            "Valerievich",
//            {16, 3, 1911},
//            2020,
//            "IT",
//            "KB-3",
//            "INBO-5-19",
//            "19B6141",
//            Male
//    );
//    cout << Ivan1->getFullName() << endl;
//
//    (*Ivan1)++;
//    Ivan1->addSubject(1, "Math");
//    Ivan1->addSubject(1, "Programming");
//    Ivan1->addSubject(1, "IT");
//    Ivan1->printSubjects(1);
//    Ivan1->setGrade(1, "IT", 5);
//    Ivan1->setGrade(1, "Math", INCOMPLETE);
//    Ivan1->removeSubject(1, "Programming");
//    Ivan1->printSubjects(1);
//    (*Ivan1)++;
//    Ivan1->addSubject(2, "Physics");
//    Ivan1->addSubject(2, "Math");
//    Ivan1->addSubject(2, "IT");
//    Ivan1->addSubject(2, "Special courses");
//    Ivan1->setGrade(2, "IT", 5);
//    Ivan1->setGrade(2, "Math", 5);
//    Ivan1->setGrade(2, "Special courses", COMPLETE);
//    Ivan1->setGrade(2, "Physics", 5);
//    (*Ivan1)++;
//    *Ivan1 - 3;
//    Ivan1->setGrade(3, "Physics", 3);
//    Ivan1->printInfo();
//
//    saveToFile("Ivan.CW", Ivan1);
//
//
////    auto* John = new Student(nullptr);
////    if (!loadFromFile("Ivan.CW", John))
////        John->printInfo();
//
//    delete Ivan1;

    menu();
    deleteAllStudents();
//    string ss = "String to encrypt and decrypt";
//    Crypto cr = *CWEncrypt(ss.c_str());
//    ss = cr.getValue();
//    cout << ss << endl;
//    cout << CWDecrypt(ss.c_str(), cr.getSessionKey()) << endl;
    return 0;
}
