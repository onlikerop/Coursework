#include "Student.h"
#include <clocale>


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
    cout << Allah->getSubjects(1).getName() << endl;
//    Allah->getSemester(0).addSubject("Sranina");
/*    Allah->getSemester(0).addSubject("Ebanina");
    Allah->getSemester(0).addSubject("Pizdanie");
    Allah->addSemester();
    Allah->getSemester(0).removeSubject("Sranina");
    Allah->getSemester(1).addSubject("Eblya");
    cout << Allah->getSemester(1).getSubjects() << endl;*/
    //cout << Allah->getSemester(0).getSubjects()<< endl << endl;
    int i;
    cin >> i;
    return 0;
}
