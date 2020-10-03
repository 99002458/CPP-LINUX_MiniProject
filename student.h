

#include <string>
#pragma once


class Student
{
    public:
        int ID;
        std::string name;
        double percentage;
        std::string gender;

    public:
        Student();
        Student(int ID, std::string name, double percentage, std::string gender);

       // void setStudent(int ID, std::string name, double percentage, std::string gender);


        virtual double computeTravelTime()=0;
        virtual double getPercantage()=0;


};

