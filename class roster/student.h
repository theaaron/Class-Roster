//
//  student.h
//  class roster
//
//  Created by aaron on 5/12/21.
//
#pragma once
#include <iostream>
#include "degree.h"
using std::string;
using std::cout;


class Student {
public:
    const static int daysToCompleteSize = 3;
    
private:
    //D1 - Creating all the variables.
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddy;
    std::string age;
    int daysToCompleteCourse[daysToCompleteSize];
    DegreeProgram degreeProgram;
    
    // D.2.c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
public:
    // contructor, sets to default.
    Student(); 
    // contructor --> D.2.d.  constructor using all of the input parameters provided in the table
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddy, std::string age, int daysToCompleteCourse[], DegreeProgram degreeProgram);
    ~Student();
    
    // getters -- D.2.a.  an accessor (i.e., getter) for each instance variable from part D1
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddy();
    std::string getAge();
    int* getDaysToCompleteCourse();
    DegreeProgram getDegreeProgram();
    
    //setters -- D.2.b  a mutator (i.e., setter) for each instance variable from part D1
    void setStudentID(std::string studID);
    void setFirstName(std::string first);
    void setLastName(std::string last);
    void setEmailAddy(std::string addy);
    void setAge(std::string years);
    void setDaysToCompleteCourse(int daysLeft[]);
    void setDegreeProgram(DegreeProgram degree);
    
    // prints student data. --> D.2.E.  print() to print specific student data
    void print();
    
    
    
};
