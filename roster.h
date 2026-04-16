/*
roster.h
C867 Scripting and Programing
Created by Shelly Myatt - November 15,2022
*/

#include <string>
#include "degree.h"
#include "student.h"

static int arrayI = 0;

// Roster contains a array of pointers to all students
class Roster 
{

public:
	
// Functions
void Parse(string data);
void Add(string studentID, string firstName, string lastName, string email, int age, int daysPercourse1, int daysPercourse2, int daysPercourse3, DegreeProgram degreeProgram);
void Remove(string studentID);
void PrintAll();
void PrintAvgDaysPerCourse(string studentID);
void PrintInvalidEmails();
void PrintByDegreeProgram(DegreeProgram degreeProgram);

Student* classRosterArray[5]{ NULL };

// Roster Destructor
	~Roster(); 
};
