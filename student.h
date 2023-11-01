#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student 
{
public:
    const static int numberOfDays = 3;

private:
    string studentID;   //Declaring all variables for the parsed data
    string firstName;
    string lastName;
    string emailAddress;
    string age;
    int days[numberOfDays];
    DegreeType degreeType;
public:
Student();  //Empty constructor declared
Student(string studentID, string firstName, string lastName, string emailAddress, string age, int days[], DegreeType degreeType);    //Constructor with all parameters set
~Student(); //Destructor

    //Getters
    string getID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    string getAge();
    int* getDays();
    DegreeType getDegreeType();

    //Setters
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(string age);
    void setDays(int days[]);
    void setDegreeType(DegreeType dt);

    void print();   //Prints student's data (this->)
    static void printHeader();  //Displays the header

};