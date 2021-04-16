//
// Created by Eugene on 16.04.2021.
//

#include <iostream>
#include <cstring>
#include <utility>


using namespace std;

#ifndef COURSEWORK_STUDENT_H
#define COURSEWORK_STUDENT_H


struct Name{
    string Second;
    string First;
    string Third;
};

struct Date{
    int day;
    int month;
    int year;
};

struct University {
    unsigned short receiptYear;
    string faculty;
    string department;
    string group;
    string IDCard;
};

enum SEX {
    Male,
    Female
};

enum GRADE{
    GREAT = 5,
    GOOD = 4,
    SATISFACTORY = 3,
    COMPLETE = 6,
    INCOMPLETE = 2,
    UNSET = 0
};


class Subject {
private:
    string name;
    GRADE grade;


public:
    explicit Subject(string subjName){
        name = move(subjName);
        grade = UNSET;
        cout << "You've just successfully added " << name << " subject" << endl;
    }

    ~Subject(){
        cout << "Subject " << name << " was successfully removed" << endl;
    }

    void setGrade (GRADE grade_to_set){
        grade = grade_to_set;
    }

    GRADE getGrade (){
        return grade;
    }

    string getName(){
        return name;
    }

};

class Semester{
private:

    Subject* subjects[10];


public:
    Semester(){
        cout << "You've just successfully added semester" << endl;
    }

    ~Semester(){
        for (auto i : subjects)
            delete i;
        delete[] *subjects;
        cout << "You've just successfully removed semester" << endl;
    }

    int addSubject(const string& subjName){
        for (auto & subject : subjects){
            if (subject){
                subject = new Subject(subjName);
                return 0;
            }
        }
        cout << "You can't add subject in this semester, because it is fully loaded (max. number of subjects in one semester - 10)" << endl;
        return 1;
    }

    int removeSubject(const string& subjName){
        for (auto & subject : subjects){
            if (subject->getName() == subjName){
                delete subject;
                return 0;
            }
        }
        cout << "You can't remove subject, that don't exist" << endl;
        return 1;
    }

    Subject* getSubjects(){
        Subject* G[10];
        for (int i = 0; i < 10; i++)
            *G[i] = *subjects[i];
        return *G;
    }

};

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

        string getFullName(){
            return name.Second + " " + name.First + " " + name.Third;
        }

        void addSubject(int semNumber, const string& subjName){
            semesters[semNumber-1]->addSubject(subjName);
        }

        void removeSubject(int semNumber, const string& subjName){
            semesters[semNumber-1]->removeSubject(subjName);
        }

        Subject getSubjects(int semNumber){
            return *semesters[semNumber-1]->getSubjects();
        }

};


#endif //COURSEWORK_STUDENT_H
