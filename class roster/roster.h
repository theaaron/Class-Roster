//
//  roster.hpp
//  class roster
//
//  Created by aaron on 5/12/21.
//

#pragma once
#include "student.h"


class Roster {
private:
    //Creating a variable for the last index to make it easier to loop through arrays
    int finalIndex = -1;
    const static int numStudents = 5;
    
    
public:
    //E1 - Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
    Student* classRosterArray[numStudents];
    
    //E2a - Parses each set of data identified in the “studentData Table.” and calls .add to add each student object to classDataArray.
    void parse(string studentData);
    
    //E3a - Adds each student object to classDataArray
    void add(string studID, string first, string last, string emailAdd, string age, int days1, int days2, int days3, DegreeProgram deg);
    
    //E3b -  Removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
    void remove(string studentID);
    
    //E3C - Prints all student data from each student in roster in tabbed format.
    void printAll(); //E3c
    
    //E3D - Prints a student’s average number of days in the three courses.
    void printAverageDaysInCourse(string studentID);
    
    //E3E - Verifies student email addresses and displays all invalid email addresses to the user.
    void printInvalidEmails();
    
    //E3F - prints out student information for a degree program specified by an enumerated type.
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    //Destructor
    ~Roster();
    
};

