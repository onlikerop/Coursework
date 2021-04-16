//
// Created by Eugene on 16.04.2021.
//

#define UNINITIALIZED 0xCDCDCDCD
#ifndef COURSEWORK_STUDENT_H
#define COURSEWORK_STUDENT_H


#include "Semester.h"

class Student {
    private:
        Name name;
        Date BDate;
        University university;
        SEX sex;

        Semester* semesters[9];

    public:
        Student(string SName, string FName, string TName, Date BDate, unsigned short receiptYear, string faculty, string department, string group, string IDCard, SEX sex){
            name = {move(SName), move(FName), move(TName)};
            this->BDate = BDate;
            university = {receiptYear, move(faculty), move(department), move(group), move(IDCard)};
            this->sex = sex;

            cout << "You've just successfully added " << getFullName() << " to the list of students" << endl;
        }

        ~Student(){
            for (auto i : semesters)
                delete i;
            delete[] *semesters;
            cout << "You've just successfully removed student " << getFullName() << endl;
        }

        int addSemester(){
            for (auto & semester : semesters){
                if (semester){
                    semester = new Semester();
                    return 0;
                }
            }
            cout << "You can't add subject in this semester, because it is fully loaded (max. number of subjects in one semester - 10)" << endl;
            return 1;
        }

        int removeSemester(int semesterNumber){
            delete semesters[semesterNumber-1];
        }

        string getFullName(){
            return name.Second + " " + name.First + " " + name.Third;
        }

        void addSubject(int semNumber, const string& subjName){
            semesters[semNumber-1]->addSubject(subjName);
        }

        void removeSubject(int semNumber, const string& subjName){
            semesters[semNumber-1]->removeSubject(subjName);
        }

        void printSubjects(int semNumber){
            semesters[semNumber-1]->printSubjects();
        }

        Semester* getSemester(int semNumber){
            if ((unsigned int)semesters[semNumber-1] != UNINITIALIZED)
                return semesters[semNumber-1];
            return nullptr;
        }

};


#endif //COURSEWORK_STUDENT_H
