// CasidyLynhClassRosterProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;

int main()
{
	int numStudents = 5;
	const string studentData[] =
	{
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Lynh,Casidy,lcasidy@wgu.edu,27, 20, 20, 20,SOFTWARE"
	};

	Roster* classRoster = new Roster(numStudents);
	for (int i = 0; i < numStudents; i++) {
		classRoster->parseAndAdd(studentData[i]);
	}

	//Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Scripting and Programming - Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #001390025" << endl;
	cout << "Name: Lynh Casidy" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;

	cout << "Displaying all students: " << endl <<endl;
	classRoster->printAll();
	cout << "-------------------------------------------------------------------------------" << endl;
	
	cout << "Displaying invalid emails:" << endl;
	classRoster->printInvalidEmails();
	cout << "-------------------------------------------------------------------------------" << endl;

	cout << "Displaying average days left in course:" << endl << endl;
	classRoster->printAverageDaysInCourse("A1");
	classRoster->printAverageDaysInCourse("A2");
	classRoster->printAverageDaysInCourse("A3");
	classRoster->printAverageDaysInCourse("A4");
	classRoster->printAverageDaysInCourse("A5");
	cout << "-------------------------------------------------------------------------------" << endl;

	cout << "Showing students in degree program: SOFTWARE"<< endl << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "-------------------------------------------------------------------------------" << endl;

	cout << "Removing A3:" << endl << endl;
	classRoster->remove("A3");
	cout << "-------------------------------------------------------------------------------" << endl;

	cout << "Remove A3 again: " << endl << endl;
	classRoster->remove("A3");
	cout << "-------------------------------------------------------------------------------" << endl;

	}
	