
#ifndef Degree_h
#define Degree_h

using namespace std;

#include <string>

// Define a new variable type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE
enum DegreeProgram 
{
	SECURITY, NETWORK, SOFTWARE 
};

// Parallel array of strings for output
static const std::string DegreeProgramstrings[] = 
{
	"SECURITY", "NETWORK", "SOFTWARE" 
}; 

#endif 