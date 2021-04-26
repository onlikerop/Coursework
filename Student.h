//
// Created by Eugene on 16.04.2021.
//

#ifndef COURSEWORK_STUDENT_H
#define COURSEWORK_STUDENT_H


//#include "Semester.h"


class Student {
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

        ~Student();

        int addSemester();

        int removeSemester(int semesterNumber);

        string getFullName() const;

        string getID() const;

        void printInfo();

//        void addSubject(int semNumber, const string& subjName);
//
//        void removeSubject(int semNumber, const string& subjName);
//
//        void printSubjects(int semNumber);

        Semester* getSemester(int semNumber);

        int operator +();
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

};

#endif //COURSEWORK_STUDENT_H
