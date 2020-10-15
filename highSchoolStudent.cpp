#include <string>
#include "student.h"
#include "highSchoolStudent.h"


HighSchoolStudent::HighSchoolStudent():Student(),grade(""),
    address(""),
    busDistance(0){}

HighSchoolStudent::HighSchoolStudent(int ID, std::string name, double percentage, std::string gender,std::string grade,std::string address,int distance):
    Student(ID,name,percentage,gender),grade(grade),address(address),busDistance(distance){

    }



    double HighSchoolStudent::computeTravelTime(){

    return (busDistance)/(60.0/60);

    }


    int HighSchoolStudent::getID(){

    return ID;

    }
    std::string HighSchoolStudent::getGender(){

    return gender;

    }
    std::string HighSchoolStudent::getName(){

    return name;

    }
    double HighSchoolStudent::getPercantage(){

    return percentage;

    }
    int HighSchoolStudent::getDistance(){

    return busDistance;

    }


