/*
student.h
C867 Scripting and Programing
Created by Shelly Myatt - November 15,2022
*/

#pragma once // Source file will only run once

#include <string>
#include "degree.h"

using namespace std;

// Defining the student class
class Student 
{

// Constructor using all input parameters 
public:

// Mutators, defining the set methods for the class variables
void setStudentId(string studentID);
void setFirstName(string firstName);
void setLastName(string lastName);
void setEmailAddress(string email);
void setAge(int age);
void setNumDays(int daysPerCourse[]);
void setDegreeProgram(DegreeProgram degreeProgram);
void Print();

// Accessors, defining the getters for the class variables
	string getStudentId() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getDaysPerCourse() const;
	DegreeProgram getDegreeProgram(
	);
	
// Empty constructor 
	Student();

// Constructor for student class
	Student(
	string studentID,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysPerCourse[],
	DegreeProgram degreeProgram);

// Destructor
	~Student();

// Variables that make up the student info
private:

	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* daysPerCourse;
	DegreeProgram degreeProgram;
};

