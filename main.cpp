#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

// Print my details
int main() 
{
	cout << "Name: Shelly Myatt" << endl;
	cout << endl;

// Creating Roster as ClassRoster
Roster classRoster;

const string studentData[] = 
{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Stacey,Miles,smiles47@.gmail,31,60,19,85,SOFTWARE"
};

// Parse strings in studentData to add each student to classRoster
	for (int i = 0; i < 5; i++) 
{
	classRoster.Parse(studentData[i]);	
}

// Print all student data in class roster
	cout << "Displaying all Students:" << endl;
	classRoster.PrintAll();
	cout << endl;

// Print all invalid emails in the class roster
	cout << "Displaying invalid emails:" << endl;
	cout << endl;

	classRoster.PrintInvalidEmails();
	cout << endl;

	for (int i = 0; i < 5; i++) 
{
	classRoster.PrintAvgDaysPerCourse(classRoster.classRosterArray[i]->getStudentId());
}
	cout << endl;

// Print only the students who's degree program is in software
	cout << "Showing students in degree program: SOFTWARE" << endl;
	cout << endl;

	classRoster.PrintByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;

// Remove student A3 data
	cout << "Removing A3:" << endl;

	classRoster.Remove("A3");
	cout << endl;

// Print all student data in the new class roster
	classRoster.PrintAll();
	cout << endl;

// Remove student A3 data again
	cout << "Removing A3 again" << endl;
	cout << endl;

	classRoster.Remove("A3");
	cout << endl;

return 0;
}