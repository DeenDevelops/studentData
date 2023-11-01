#include "student.h"

Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = "";
    for (int i = 0; i < numberOfDays; i++) this->days[i] = 0;
    this->degreeType = DegreeType::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, string age, int days[], DegreeType degreeType)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < numberOfDays; i++) this->days[i] = days[i];
    this->degreeType = degreeType;
}

Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this-> emailAddress; }
string Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeType Student::getDegreeType() { return this->degreeType; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setDays(int days[])
{
    for (int i = 0; i < numberOfDays; i++) this->days[i] = days[i];
}
void Student::setDegreeType(DegreeType dt) { this->degreeType = dt;}

void Student::print()
{
    cout << this->getID() << "\t";
    cout << this->getFirstName() << "\t";
    cout << this->getLastName() << "\t";
    cout << this->getEmailAddress() << "\t";
    cout << this->getAge() << "\t";
    cout << this->getDays()[0] << ",";
    cout << this->getDays()[1] << ",";
    cout << this->getDays()[2] << "\t";
    cout << degreeTypeStrings[this->getDegreeType()] << "\n";
}

void Student::printHeader()
{
    cout << "ID|First Name|Last Name|Email Address|Age|Days|Degree\n";
}