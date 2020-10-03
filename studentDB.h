#include<string>
#include<cstdint>
#include "student.h"
#include "highSchoolStudent.h"
#pragma once
#include <list>
#include <iterator>
#pragma once


class StudentDB :  public HighSchoolStudent {

//private :
public :

std::list <HighSchoolStudent> hs_student;

public :

    void addStudent(int , std::string , double , std::string ,std::string, std::string , int);
    void removeStudent(std::string);
    HighSchoolStudent* findStudentById(int);
    double computeMaxPercantage();
    int countStudentsBygender(std::string);
    int countAll();

};





