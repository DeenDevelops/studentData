#include "roster.h"
void Roster::parse(string studentData)
{
    int rSide = studentData.find(","); //Finding commas. rSide means the comma on right and lSide means comma on the left
    string studID = studentData.substr(0,rSide); //Extracts the substring

    int lSide = rSide + 1; //The +1 moves us past the comma
    rSide = studentData.find(",", lSide);
    string studFirstName = studentData.substr(lSide, rSide - lSide); //Extracted first name

    lSide = rSide + 1; //Moving past the next comma
    rSide = studentData.find(",", lSide);
    string studLastName = studentData.substr(lSide, rSide - lSide); //Extracted last name

    lSide = rSide + 1; //Moving past the next comma
    rSide = studentData.find(",", lSide);
    string studEmail = studentData.substr(lSide, rSide - lSide); //Extracted email

    lSide = rSide + 1; //Moving past the next comma
    rSide = studentData.find(",", lSide);
    string studAge = studentData.substr(lSide, rSide - lSide); //Extracted age

    lSide = rSide + 1; //Moving past the next comma
    rSide = studentData.find(",", lSide);
    int d1 = stoi(studentData.substr(lSide, rSide - lSide)); //Extracts the first day and converts it to an integer
    lSide = rSide + 1; //Moving past the next comma
    rSide = studentData.find(",", lSide);
    int d2 = stoi(studentData.substr(lSide, rSide - lSide)); //Extracts the first day and converts it to an integer
    lSide = rSide + 1; //Moving past the next comma
    rSide = studentData.find(",", lSide);
    int d3 = stoi(studentData.substr(lSide, rSide - lSide)); //Extracts the first day and converts it to an integer

    lSide = rSide + 1; // Moving past the last comma
    string degreeString = studentData.substr(lSide); // Extracted the final value, degreeType

    DegreeType dt;
    if (degreeString == "SECURITY") { dt = SECURITY; } //The if statements here are used to convert the final extracted value to our enumerated type
    else if (degreeString == "NETWORK") { dt = NETWORK; }
    else if (degreeString == "SOFTWARE") { dt = SOFTWARE; }

    add(studID, studFirstName, studLastName, studEmail, studAge, d1, d2, d3, dt);
}
//The add method
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, string age, int day1, int day2, int day3, DegreeType dt)
{
    int daysArray[3] = { day1, day2, day3 }; //Put days into this array for the constructor
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, dt); //Making the new Student object
}

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i]->getID(); cout << '\t';
        cout << classRosterArray[i]->getFirstName(); cout << '\t';
        cout << classRosterArray[i]->getLastName(); cout << '\t';
        cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
        cout << classRosterArray[i]->getAge(); cout << '\t';
        cout << classRosterArray[i]->getDays()[0]; cout << '\t';
        cout << classRosterArray[i]->getDays()[1]; cout << '\t';
        cout << classRosterArray[i]->getDays()[2]; cout << '\t';
        cout << degreeTypeStrings[classRosterArray[i]->getDegreeType()] << std::endl;
    }
}

void Roster::printByDegreeProgram(DegreeType dt) //displays degrees that match degree type
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++){
        if (Roster::classRosterArray[i]->getDegreeType() == dt) classRosterArray[i]->print();
    }
    cout <<std::endl;
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string sEmailAddress = (classRosterArray[i]->getEmailAddress());
        if (sEmailAddress.find('@') == string::npos || sEmailAddress.find('.') == string::npos || sEmailAddress.find(' ') != string::npos) //Valid email should include an @ sign and a . sign. It should not include a space
        {
            any = true;
            cout << sEmailAddress << ": " << classRosterArray[i]->getEmailAddress() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}
 void Roster::printAverageDaysInCourse()
 {
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i]->getID() << ":";
        cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2])/3.0 <<std::endl;
    }
    cout << std::endl;
 }

 void Roster::remove(string studentID) //We remove student based on ID, in this case A3
 {
    bool flag = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            flag = true;
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i]; //last student gets switched
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
        }
    }
    if(flag)
    {
        cout << studentID << " removed from table." << std::endl << std::endl;
        this->printAll(); //Everything but the removed student will be displayed
    }
    else cout << studentID << " not found." << std::endl << std::endl;
 }

 Roster::~Roster()
 {
    cout << "Destructing..." << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Removing student: " << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
 }