#include <string>
#include "student.h"
#pragma once


class HighSchoolStudent : public Student {

private :

    std::string grade;
    std::string address;
    int busDistance;


public :

    HighSchoolStudent();
    HighSchoolStudent(int ,std::string,double , std::string,std::string,std::string, int);


    double computeTravelTime();


    int getID();
    std::string getGender();
    std::string getName();
    double getPercantage();
    int getDistance();
};
