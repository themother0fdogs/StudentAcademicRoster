#pragma once

#include "degree.h"
#include <string>
#include <iostream> 
using namespace std;

/*Create the class Student  in the files student.h and student.cpp, 
which includes each of the following variables:*/
//student ID
//first name
//last name
//email address
//age
//array of number of days to complete each course
//degree program 


class Student {

public:
	const static int completionArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysToComplete;
	DegreeProgram degreeProgram;

public:
	//Default Constructor
	Student();

	//
	Student(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysToComplete[], DegreeProgram degreeProgram);

	//Getters 
	string GetstudentID();
	string GetfirstName();
	string GetlastName();
	string GetEmail();
	int GetAge();
	int* GetDaysToComplete();
	DegreeProgram GetDegreeProgram();

	//Setters
	void SetstudentID(string studentID);
	void SetfirstName(string firstName);
	void SetlastName(string lastName);
	void SetEmail(string emailAddress);
	void SetAge(int age);
	void SetDaysToComplete(int daysToComplete[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);
	void print();
	
	//Destructor
	~Student();
};