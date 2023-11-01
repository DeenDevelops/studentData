#pragma once
#include "student.h"

class Roster
{
private:
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    int lastIndex = -1;

public:
    void parse(string row); //The parse method extracts the data between commas
    //Student data is passed into this add method
    void add(string sID, string sFirstName, string sLastName, string sEmailAddress, string sGetAge, int sDay1, int sDay2, int sDay3, DegreeType dt);

    void remove(string studentID); //Removes based off of studentID
    void printAll(); //prints a tab-separated list of student data
    void printAverageDaysInCourse(); //Prints the average number of days in the course
    void printInvalidEmails(); //Prints emails that do do not respect valid email parameters
    void printByDegreeProgram(DegreeType dt);
    ~Roster();
};