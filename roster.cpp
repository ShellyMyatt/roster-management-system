/*
roster.cpp
C867 Scripting and Programing
Created by Shelly Myatt - November 15,2022
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "roster.h"
#include "degree.h"
#include "student.h"


using namespace std;

// Adds (string student ID)
// Creates an array of pointers (classRosterArray)
void Roster::Add (
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysPercourse1, 
	int daysPercourse2, 
	int daysPercourse3,
	DegreeProgram degreeProgram)
{
	int daysPerCourse[] = 
{ 
		daysPercourse1, 
		daysPercourse2, 
		daysPercourse3 
};

	classRosterArray[arrayI++] = new Student ( 
		studentID, 
		firstName, 
		lastName, 
		email, 
		age, 
		daysPerCourse, 
		degreeProgram);
}

// Constructor parses and adds student data
void Roster::Parse(string data) 
{
	vector<string> dataValues;
	DegreeProgram exampleDegree;

	for (int i = 0; i < 5; i++) {
		stringstream ss(data);

		while (ss.good()) {
			string subStr;
			getline(ss, subStr, ',');
			dataValues.push_back(subStr);	
		} 

		if (dataValues[8] == "SECURITY") {
			exampleDegree = DegreeProgram::SECURITY;
		}

		else if (dataValues[8] == "NETWORK") {
			exampleDegree = DegreeProgram::NETWORK;
		}

		else if (dataValues[8] == "SOFTWARE") {
			exampleDegree = DegreeProgram::SOFTWARE;
		}
}

// Adds each student object to classRosterArray
	Roster::Add(
		dataValues.at(0), //Student Id
		dataValues.at(1), // First Name
		dataValues.at(2), // Last Name
		dataValues.at(3), //Email Address

		stoi(dataValues.at(4)), // Age
		stoi(dataValues.at(5)), // Days Per Course 1
		stoi(dataValues.at(6)), // Days Per Course 2
		stoi(dataValues.at(7)), // Days Per Course 3
		exampleDegree); // Degree Program
}

// Removes student by their student ID
void Roster::Remove(string studentID) 
{	
	for (int i = 0; i < 5; ++i) {

		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
return;
			}
		}

	cout << "The student with ID: " << studentID << " was not found." << endl;

return;
}

// Prints all student data in roster
void Roster::PrintAll() 
{
	for (int i = 0; i < 5 && classRosterArray != nullptr; i++) {

		if (classRosterArray[i] != nullptr) 
		{
			classRosterArray[i]->Print();
		}
	}
}

// Prints average days number of days spent per course 
void Roster::PrintAvgDaysPerCourse(string studentID) 
{
	for (int i = 0; i < 5; i++) {

		if (studentID == classRosterArray[i]->getStudentId()) {	
			int* days = classRosterArray[i]->getDaysPerCourse();				
			int avgDays = (days[0] + days[1] + days[2]) / 3;				

	cout << "Student ID: " << studentID << ", average days per course: " << avgDays << endl;
		}
	}
}

// Prints invalid emails (zyBooks 7.2)
void Roster::PrintInvalidEmails() 
{
	string email = "";

	for (int i = 0; i < 5; i++) {
		bool at = false;
		bool period = false;
		bool space = false;

		email = classRosterArray[i]->getEmailAddress();

	for (char& character : email) {

		if (character == '@') {
			at = true;
			}

		if (character == '.') {
			period = true;
			}

		if (character == ' ') {
			space = true;
			}
		}

		if (at == false || period == false || space == true) {
			
	cout << classRosterArray[i]->getEmailAddress() << " - is invalid." << endl;
		}
	}
}

// Prints roster of student information for degree program specified by enumerated type
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) 
{
	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i] != NULL) {

		if (degreeProgram == classRosterArray[i]->getDegreeProgram()) {
			classRosterArray[i]->Print();
			}
		}
	}
}

// Destructor
Roster::~Roster() 
{
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = NULL; 
	}
	cout << "DONE" << endl;
}