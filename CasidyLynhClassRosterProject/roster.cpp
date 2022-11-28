#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include <vector>
using namespace std;

Roster::Roster() {
	this->lastIndex = -1;
	this->maxSize = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int maxSize) {
	this->lastIndex = -1;
	this->maxSize = maxSize;
	this->classRosterArray = new Student * [maxSize];
}

//Parse each set of data identified in the “studentData Table.”
void Roster::parseAndAdd(string student) {
	int parsedDays[Student::completionArraySize];
	DegreeProgram degreeprogram;

	if (lastIndex < maxSize)
	{
		lastIndex++;
	}

	this->classRosterArray[lastIndex] = new Student();

	int long rhs = student.find(",");
	classRosterArray[lastIndex]->SetstudentID(student.substr(0, rhs));

	int long lhs = rhs + 1;
	rhs = student.find(",", lhs);
	classRosterArray[lastIndex]->SetfirstName(student.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	classRosterArray[lastIndex]->SetlastName(student.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	classRosterArray[lastIndex]->SetEmail(student.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	int x = stoi(student.substr(lhs, rhs - lhs));
	classRosterArray[lastIndex]->SetAge(x);

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	parsedDays[0] = stoi(student.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	parsedDays[1] = stoi(student.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	parsedDays[2] = stoi(student.substr(lhs, rhs - lhs));

	classRosterArray[lastIndex]->SetDaysToComplete(parsedDays);

	lhs = rhs + 1;
	if (student[lhs] == 'S')
	{
		if (student[lhs + 1] == 'E') classRosterArray[lastIndex]->SetDegreeProgram(DegreeProgram::SECURITY);
		else if (student[lhs + 1] == 'O') classRosterArray[lastIndex]->SetDegreeProgram(DegreeProgram::SOFTWARE);
		else if (student[lhs] == 'N') classRosterArray[lastIndex]->SetDegreeProgram(DegreeProgram::NETWORK);
	}
	
}

// sets the instance variables from part D1 and updates the roster.
void Roster::add (string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysToComplete[Student::completionArraySize];
	daysToComplete[0] = daysInCourse1;
	daysToComplete[1] = daysInCourse2;
	daysToComplete[2] = daysInCourse3;
	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
}

Student* Roster::getStudent(int index) {
	return classRosterArray[index];
}

//The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; ++i) {
		(this->classRosterArray)[i]->print();
	}
}

//removes students from the roster by student ID. 
//If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID) {
	bool studentIDFound = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetstudentID() == studentID)
		{
			studentIDFound = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
		if (studentIDFound == true)
		{
			cout << "Student ID " << studentID << " removed." << endl;
		}
		else {
			cout << "Error! StudentID not found!" << endl;
		}

		return;
}

//correctly prints a student’s average number of days in the three courses. 
//The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->GetstudentID() == studentID) {
			cout << "Student ID: " << classRosterArray[i]->GetstudentID() << ", ";
			int* daysToComplete = classRosterArray[i]->GetDaysToComplete();
			cout << "Average number of days in courses is: " << (daysToComplete[0] + daysToComplete[1] + daysToComplete[2]) / 3 << endl;
			return;
		}
	}
}

//verifies student email addresses and displays all invalid email addresses to the user.
//Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails(){
	for (int i = 0; i < lastIndex; ++i) {
		string emailAddress = classRosterArray[i]->GetEmail();
		if ((emailAddress.find("@") == string::npos || emailAddress.find(".") == string::npos || emailAddress.find(" ") != string::npos)) {

			cout << emailAddress << endl;
		}
	}
}

//prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram (DegreeProgram degreeProgram) {
	for (int i = 0; i <= lastIndex; i++){
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) 
			classRosterArray[i]->print(); 
	}
	
}

Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}