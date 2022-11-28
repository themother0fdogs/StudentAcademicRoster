#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

class Roster {
private: 
	int lastIndex;
	int maxSize;
	Student** classRosterArray;

public:
	Roster();
	Roster(int maxSize);
	
	void parseAndAdd(string student);
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	Student* getStudent(int lastIndex);
	void printAll();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
	
};
