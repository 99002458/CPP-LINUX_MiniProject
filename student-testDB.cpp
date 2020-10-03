#include "student.h"
#include "highSchoolStudent.h"
#include "studentDB.h"
#include <gtest/gtest.h>
#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<list>
#include<iterator>
#include<cstdint>


pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;
StudentDB students;


void* efun1(void* pv){



        pthread_mutex_lock(&m1);

        students.addStudent(1,"Rahul", 98.73 , "M", "A","Mumbai", 8);
        students.addStudent(2,"Komal", 92.23 , "F", "A","Pune", 3);
        students.addStudent(3,"Nakul", 94.53 , "M", "A","Airoli", 9);
        students.addStudent(4,"Arjun", 88.93 , "M", "A","Dadar", 4);
        students.addStudent(5,"Samir", 78.13 , "M", "B","Andheri", 7);
        students.addStudent(6,"Sara", 60.21 , "F", "C","Bandra", 2);

        pthread_mutex_unlock(&m1);
        sem_post(&s1);

}


void* efun2(void* pv)        //consumer
{


        sem_wait(&s1);            //changing sequence lead to deadlock
        pthread_mutex_lock(&m1);

        std::cout<<"\n";
        std::cout<<"The "<<students.countAll()<<" new High school student took addmission in school \n";
        std::cout<<"\n";

        pthread_mutex_unlock(&m1);
        //pthread_exit(NULL);
}

namespace {

class HighSchoolStudentDbTest : public ::testing::Test {

protected:
  void SetUp() {

  }
  void TearDown() {}
  //StudentDB students;
};

TEST_F(HighSchoolStudentDbTest, AddStudentTest) {

    pthread_t pt1,pt2;    //thread handles
    sem_init(&s1,0,0);
    pthread_create(&pt1,NULL,efun1,NULL);
    pthread_create(&pt2,NULL,efun2,NULL);
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);

    students.addStudent(7,"Kunal", 80.21 , "M", "A","Mahir", 5);
    EXPECT_EQ(7, students.countAll());

    sem_destroy(&s1);
    pthread_mutex_destroy(&m1);
}


TEST_F(HighSchoolStudentDbTest, RemoveTripTest) {
  students.removeStudent("Rahul");
  EXPECT_EQ(6, students.countAll());
}
TEST_F(HighSchoolStudentDbTest, CountTest) {             //Just After Setup
  EXPECT_EQ(6, students.countAll());
}
TEST_F(HighSchoolStudentDbTest, countStudentsBygender) {  //Just After Setup
  int count = students.countStudentsBygender("F");
  EXPECT_EQ(2, count);
}
TEST_F(HighSchoolStudentDbTest, MaxFareTest) {           //Just After Setup
  double maxPerc = students.computeMaxPercantage();
  EXPECT_EQ(94.53, maxPerc);         //For trip with distance of 1200 miles          //For trip with distance of 350 miles
}
TEST_F(HighSchoolStudentDbTest, AnotherTest) {         //Just After Setup
  students.addStudent(8,"Krishna", 84.21 , "M", "A","Lonavala", 4);
  students.addStudent(9,"Sita", 90.21 , "F", "A","Khar", 7);
  int count = students.countStudentsBygender("M");
  double maxPerc = students.computeMaxPercantage();
  EXPECT_EQ(8, students.countAll());
  EXPECT_EQ(5, count);
  EXPECT_EQ(94.53, maxPerc);
}
} // namespace

