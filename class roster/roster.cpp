//
//  roster.cpp
//  class roster
//
//  Created by aaron on 5/12/21.
//

#include "roster.h"

//Parsing the data by finding commas and assigning the data between them to variables that will be used by the .add function
void Roster::parse(string studentData) {
    int right = studentData.find(",");
    string sID = studentData.substr(0, right);
    
    int left = right + 1;
    right = studentData.find(",", left);
    string fiNa = studentData.substr(left, right - left);
    
    left = right + 1;
    right = studentData.find(",", left);
    string laNa = studentData.substr(left, right - left);
    
    left = right + 1;
    right = studentData.find(",", left);
    string eAddy = studentData.substr(left, right - left);
    
    left = right + 1;
    right = studentData.find(",", left);
    string yearsOld = studentData.substr(left, right - left);
    
    left = right + 1;
    right = studentData.find(",", left);
    int d1 = stoi(studentData.substr(left, right - left));
    
    left = right + 1;
    right = studentData.find(",", left);
    int d2 = stoi(studentData.substr(left, right - left));
    
    left = right + 1;
    right = studentData.find(",", left);
    int d3 = stoi(studentData.substr(left, right - left));
    
    left = right + 1;
    string conDegProg = studentData.substr(left);
    DegreeProgram dp;
    
    if (conDegProg == "SECURITY") dp = SECURITY;
    else if (conDegProg == "SOFTWARE") dp = SOFTWARE;
    else if (conDegProg == "NETWORK") dp = NETWORK;
    
    
    add(sID, fiNa, laNa, eAddy, yearsOld, d1, d2, d3, dp);
       
};

//creates a new student and adds it to the classRosterArray
void Roster::add(string studID, string first, string last, string emailAdd, string age, int days1, int days2, int days3, DegreeProgram deg) {
    int daysArr[3] = {days1, days2, days3};
    
    classRosterArray[++finalIndex] = new Student(studID, first, last, emailAdd, age, daysArr, deg); //E2b
    
}

//using a for loop to loop through all students and invoke the .print function for each student in the roster
void Roster::printAll() {
    for ( int i = 0; i <= Roster::finalIndex; i++) {
        classRosterArray[i]->print();        
    }
}

//looping through the roster, then using an if statement to invoke the print function if the degree program is equal to the argument.
void Roster::printByDegreeProgram(DegreeProgram dp) {
    for (int i = 0; i <= Roster::finalIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dp) {
            classRosterArray[i]->print();
        }
    }
}

//loops through the roster to verify that "@" and "." are present and that a space is not present.
void Roster::printInvalidEmails() {
    bool any = false;
    for (int i = 0; i <= Roster::finalIndex; i++) {
        string addy = (classRosterArray[i]->getEmailAddy());
        if (addy.find("@") == string::npos || addy.find(".") == string::npos || addy.find(" ") != string::npos) {
            any = true;
            cout << classRosterArray[i]->getEmailAddy() << "\t";
        }
        
    }
    if (!any) cout << "No Invalid Email Addresses" << std::endl;
};

//loops through the roster to find the correct student id, then prints out the average days to complete course.
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::finalIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID){
            cout << classRosterArray[i]->getStudentID() << ": ";
            cout << (classRosterArray[i]->getDaysToCompleteCourse()[0] + classRosterArray[i]->getDaysToCompleteCourse()[1] + classRosterArray[i]->getDaysToCompleteCourse()[2]) / 3.0 << std::endl;
        }
    }
}

//loops through roster to find the correct student id, then removes the student from roster and prints a confirmation message. if the id is not found, then an error message is printed.
void Roster::remove(string studentID) {
    bool idExists = false;
    
    for (int i = 0; i <+ Roster::finalIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID){
            idExists = true;
            if (i < numStudents - 1) {
                Student* tmp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = tmp;
            }
            Roster::finalIndex--;
        } 
    }
    
    if (idExists) {
        cout << "The student was removed from the roster." << std::endl;
//        this->printAll();
    } else {
        cout << "Student not found." << std::endl;
    }
}

//loops through the roster and deletes each student object from classRosterArray. Also sends a message with each removal.
Roster::~Roster() {
    cout << "Destruction commencing..." << std::endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Farewell Student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
