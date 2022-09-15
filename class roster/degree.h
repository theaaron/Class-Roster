//
//  degree.cpp
//  class roster
//
//  Created by aaron on 5/12/21.
//

#include <stdio.h>

// C.  Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// An array of the degree program types to make it easier to assign names to student degree programs.
static const std::string degreeProgramStrs[] = { "SECURITY", "NETWORK", "SOFTWARE" };

