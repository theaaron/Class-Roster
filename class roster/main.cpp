//
//  main.cpp
//  class roster
//
//  Created by aaron on 5/7/21.
//
#include "roster.h"
//F - Demonstrate the program’s required functionality by adding a main() function in main.cpp
int main()
{
    const std::string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Aaron,Anguiano,aangui6@wgu.edu,32,32,39,48,SOFTWARE" };

//  F1 - Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "C867 | C++ | #001307831 | Aaron Anguiano" << std::endl;
    
    const int numStudents = 5;
    
    // F2 - Create an instance of the Roster class called classRoster.
    Roster classRoster;
    
    // F3  Add each student to classRoster.
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]); //F3
    
    //F4
    cout << "Print All Students" << std::endl;
    classRoster.printAll();
    cout << std::endl;
    
    cout << "Printing Invalid Emails" << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    
    cout << "Looping through Average Days in course for each student" << std::endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        
    }
    
    cout << "Printing SOFTWARE students." << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    
    cout << "Removing Student A3" << std::endl;
    classRoster.remove("A3");
    
    cout << "Print All Students" << std::endl;
    classRoster.printAll();
    
    cout << "Tring to remove A3 again..." << std::endl;
    classRoster.remove("A3");
    
    //F5 - Implement the destructor to release the memory that was allocated dynamically in Roster.
    classRoster.~Roster();

    

    
    
    return 0;
    
    
    
    
    
        
    
}


