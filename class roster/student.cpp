//
//  student.cpp
//  class roster
//
//  Created by aaron on 5/12/21.
//

#include "student.h"


//default student made of empty strings.
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddy = "";
    this->age = "";
    for (int i = 0; i < daysToCompleteSize; i++) this->daysToCompleteCourse[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
};


//The functions that assigns the parsed data to variables.
Student::Student( std::string studentID, std::string firstName, std::string lastName, std::string emailAddy, std::string age, int daysToCompleteCourse[], DegreeProgram degreeProgram ) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddy = emailAddy;
    this->age = age;
    for (int i = 0; i < daysToCompleteSize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
    this->degreeProgram = degreeProgram;
}

// Destructor. Does nothing. Destruction will be handled by roster.cpp
Student::~Student() {}

//Getter Functions
std::string Student::getStudentID() {return this->studentID;}
std::string Student::getFirstName() {return this->firstName;}
std::string Student::getLastName() {return this->lastName;}
std::string Student::getEmailAddy() {return this->emailAddy;}
std::string Student::getAge() {return this->age;}
int* Student::getDaysToCompleteCourse() {return this->daysToCompleteCourse;}
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}

//Setter Functions
void Student::setStudentID(std::string ID) {this->studentID = ID;}
void Student::setFirstName(std::string first) {this->firstName = first;}
void Student::setLastName(std::string last) {this->lastName = last;}
void Student::setEmailAddy(std::string addy) {this->emailAddy = addy;}
void Student::setAge(std::string years) {this->age = years;}
void Student::setDaysToCompleteCourse(int daysLeft[]) {
    for (int i = 0; i < daysToCompleteSize; i++) this->daysToCompleteCourse[i] = daysLeft[i];
        }
void Student::setDegreeProgram(DegreeProgram degree) {this->degreeProgram = degree;}

//Print function. Prints all student data for a single student.
void Student::print() {
    cout << this->getStudentID() << "\t";
    cout << this->getFirstName() << "\t";
    cout << this->getLastName() << "\t";
    cout << this->getEmailAddy() << "\t";
    cout << this->getAge() << "\t";
    cout << this->getDaysToCompleteCourse()[0] << ", ";
    cout << this->getDaysToCompleteCourse()[1] << ", ";
    cout << this->getDaysToCompleteCourse()[2] << "\t";
    cout << degreeProgramStrs[this->getDegreeProgram()] << std::endl;
}




