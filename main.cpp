#include "roster.h"

int main()
{
    cout << "\nCourse C867 (Scripting and Programming Applications)\nProgramming Language: C++\nStudent ID: 011564151\nName: Deen Knotts\n\n";

    const string studentData[] =
    {
   "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Deen,Knotts,deen.knotts@gmail.com,25,20,21,22,SOFTWARE"
    };

    const int numStudents = 5;
    Roster roster;

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "All students: " << std::endl;
    roster.printAll();
    cout << std::endl;


    cout << "Degree (SOFTWARE): " << std::endl;
    roster.printByDegreeProgram((DegreeType::SOFTWARE));

    cout << "Displaying students with invalid emails: " << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;

    cout << "Average days: " << std::endl;
    roster.printAverageDaysInCourse();

    cout << "Removing student with ID A3: " << std::endl;
    roster.remove("A3");
    cout << std::endl;
    roster.remove("A3");

    system("pause");
    return 0;
}