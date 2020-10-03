#include "highSchoolStudent.h"
#include "student.h"
#include "studentDB.h"
#include <string>

#include <list>
#include <iterator>

#include <thread>
#include <semaphore.h>
#include <iostream>




	void StudentDB::addStudent(int ID, std::string name, double percantage, std::string gender,std::string grade, std::string address, int busDistance){

    hs_student.push_back(HighSchoolStudent(ID, name, percantage, gender, grade, address, busDistance));


	}
	void StudentDB::removeStudent(std::string name){

    std::list<HighSchoolStudent> :: iterator iter;

    for(iter=hs_student.begin();iter!=hs_student.end();iter++)
    {
        if(iter->getName()== name)
        {
           hs_student.erase(iter);
           break;
        }
    }


    }









    double StudentDB::computeMaxPercantage(){

    std:: list<HighSchoolStudent> :: iterator iter = hs_student.begin();

    auto maxPerc  = iter->getPercantage();

    iter++;
    for(;iter!=hs_student.end();++iter)
    {
        if(maxPerc < iter->getPercantage())
        {
            maxPerc = iter->getPercantage();
           // maxiter = iter;
        }

    }
    return maxPerc;


    }


    int StudentDB::countStudentsBygender(std::string gender){


     int m_count = 0;

    std::list<HighSchoolStudent> :: iterator iter;

    for(iter=hs_student.begin();iter!=hs_student.end();iter++)
    {
        if(gender == iter->getGender())
        {
            m_count++;
        }
    }
    return m_count;


    }

    int StudentDB::countAll(){

          return hs_student.size();
    }

