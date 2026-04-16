
#include <iostream>
#include <iomanip>
#include "student.h"


using namespace std;

// Accessor (getter) for each instance variable
string Student::getStudentId() const 
{
return studentID;
}

string Student::getFirstName() const
{
return firstName;
}

string Student::getLastName() const
{
return lastName;
}

string Student::getEmailAddress() const 
{
return email;
}

int Student::getAge() const 
{
return age;
}

int* Student::getDaysPerCourse() const
{
return daysPerCourse;
}

DegreeProgram Student::getDegreeProgram() 
{
return degreeProgram;
}

// mutator (setter) for each instance variable
void Student::setStudentId(string studentID) 
{
	this->studentID = studentID;
return;
}

void Student::setFirstName(string firstName) 
{
	this->firstName = firstName;
return;
}

void Student::setLastName(string lastName) 
{
	this->lastName = lastName;
return;
}

void Student::setEmailAddress(string email) 
{
	this->email = email;
return;
}

void Student::setAge(int age)
{
	this->age = age;
return;
}

void Student::setNumDays(int daysPerCourse[]) 
{
	this->daysPerCourse = new int[3];
	for (int i = 0; i < 3; i++) {
		this->daysPerCourse[i] = daysPerCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) 
{
	this->degreeProgram = degreeProgram;
return;
}

// Constructor using all input parameters 
Student::Student(	 
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysPerCourse[],
	DegreeProgram degreeProgram)
{
	setStudentId(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(email);
	setAge(age);
	setNumDays(daysPerCourse);
	setDegreeProgram(degreeProgram);
}

// Prints all student data
void Student::Print() 
{
	int* days = getDaysPerCourse();

	string degreeProgram = "NULL";
	
	switch (getDegreeProgram()) { 
	
	case DegreeProgram::SECURITY:
		degreeProgram = "SECURITY";
		break;
	
	case DegreeProgram::NETWORK:
		degreeProgram = "NETWORK";
		break;
	
	case DegreeProgram::SOFTWARE:
		degreeProgram = "SOFTWARE";
		break;
}
	
	cout << studentID << "\t";
	cout << firstName << "\t";
	cout << lastName << "\t";
	cout << age << "\t";
	cout << "{";

	for (int i = 0; i < 3; i++) {
	
	cout << days[i];

		if (i < 2) {

	cout << ", ";
		}
	}

	cout << "}" << "\t " << degreeProgram << endl;
}

//Destructor
Student::~Student() 
{
return;
}