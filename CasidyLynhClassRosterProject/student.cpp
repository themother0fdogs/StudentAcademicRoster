#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

//Default
Student::Student() {
this->studentID = "";
this->firstName = "";
this->lastName = "";
this->emailAddress = "";
this->age = 0;
this->daysToComplete = new int[completionArraySize];
		for (int i = 0; i < completionArraySize; i++) this->daysToComplete[i] = 0;
this->degreeProgram = degreeProgram;
}

//
Student::Student (string studentID, string firstName, string lastName, string email, int age, 
		int daysToComplete[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = email;
	this->age = age;
	for (int i = 0; i < completionArraySize; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

//Implementing Getters
string Student::GetstudentID() {
	return studentID;
}
string Student::GetfirstName() {
	return firstName;
}
string Student::GetlastName() {
	return lastName;
}
string Student::GetEmail() {
	return emailAddress;
}
int Student::GetAge() {
	return age;
}
int* Student::GetDaysToComplete() {
	return daysToComplete;
}
DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

//Implementing Setters
void Student::SetstudentID(string studentID) {
	this->studentID = studentID;
}
void Student::SetfirstName(string firstName) {
	this->firstName = firstName;
}
void Student::SetlastName(string lastName) {
	this->lastName = lastName;
}
void Student::SetEmail(string email) {
	this->emailAddress = email;
}
void Student::SetAge(int age) {
	this->age = age;
}
void Student::SetDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < completionArraySize; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;

}


//

void Student::print()
{
	cout << GetstudentID() <<"     " << GetfirstName() << "     " << GetlastName() << "     " << GetAge() << "     ";
	int* daysToComplete = GetDaysToComplete(); 
	cout << "{" << daysToComplete[0] << "," << daysToComplete[1] << "," << daysToComplete[2] << "}" << "     ";
	cout << degreeProgramString [GetDegreeProgram()] << endl;

}

//Destructor
Student::~Student() {
	if (daysToComplete != nullptr)
	{
		delete[] daysToComplete;
		daysToComplete = nullptr;
	}

}
