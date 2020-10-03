#include"student.h"
#include <string>


Student::Student():ID(0),name(""),percentage(0.0), gender(""){}

Student::Student(int ID, std::string name, double percentage, std::string gender) : ID(ID),name(name),percentage(percentage), gender(gender) {}
