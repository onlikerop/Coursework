//
// Created by Eugene on 16.04.2021.
//

#ifndef COURSEWORK_STUDENT_H
#define COURSEWORK_STUDENT_H


#include "Grademeres.h"

class Student : public Grademeres{
    private:
        Name name;
        Date BDate;
        University university;
        SEX sex;

        Semester semesters[9];

    public:
        Student(string SName, string FName, string TName, Date BDate, unsigned short receiptYear, string faculty,\
        string department, string group, string IDCard, SEX sex
                );

        Student();
        Student(nullptr_t);

        ~Student();

        int addSemester();

        int removeSemester(int semesterNumber);

        string getFullName() const;

        Date getBirthdate() const;

        string getID() const;

        SEX getSex() const;

        void printInfo();

        void editInfo();

        int getNumberOfGrades(GRADE grade) final;

        int getNumberOfGrades(int grade) final;

        int getNumberOfSubjects() final;

        Semester* getSemester(int semNumber);

        int operator ++(int);
        int operator -(int semNumber);


        int addSubject(int semNumber, const string& subjName);
        int addSubject(int semNumber);

        int removeSubject(int semNumber, const string& subjName);

        int cleanSubjects(int semNumber);

        int printSubjects(int semNumber);


        int setGrade (int semNumber, const string& subjName, GRADE grade_to_set);

        int setGrade (int semNumber, const string& subjName, int grade_to_set);

        GRADE getGrade (int semNumber, const string& subjName);

        int setName (int semNumber, const string& subjName, const string &subjNameToSet);


        friend inline int saveToFile(const string& path, Student* student, FILE* file);
        friend inline int loadFromFile(const string& path, Student* student, FILE* file);

};

#endif //COURSEWORK_STUDENT_H
