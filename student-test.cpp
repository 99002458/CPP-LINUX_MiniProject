#include "student.h"
#include "highSchoolStudent.h"
#include "studentDB.h"
#include <gtest/gtest.h>

namespace {

class StudentTest : public ::testing::Test {

protected:
  void SetUp() { // override {
    ptr = new HighSchoolStudent(1,"Rahul", 98.73 , "M", "A","Mumbai", 8);
  }
  void TearDown() {
    delete ptr;
  }
  Student *ptr;
};

TEST_F(StudentTest, DefaultConstructor) {
  HighSchoolStudent ft;
  EXPECT_EQ(0, ft.getID());
  EXPECT_EQ(0, ft.getGender().length());
  EXPECT_EQ(0, ft.getName().length());
  EXPECT_EQ(0, ft.getPercantage());
  EXPECT_EQ(0, ft.getDistance());
}
TEST_F(StudentTest, ParameterizedConstructor) {
  HighSchoolStudent *fptr = dynamic_cast<HighSchoolStudent*>(ptr);
  EXPECT_EQ( 1, fptr->getID());
  EXPECT_STREQ("M", fptr->getGender().c_str());
  EXPECT_STREQ("Rahul", fptr->getName().c_str());
  EXPECT_EQ(98.73, fptr->getPercantage());
  EXPECT_EQ(8, fptr->getDistance());
}
TEST_F(StudentTest, ComputationTest) {
  EXPECT_EQ(8, ptr->computeTravelTime());  //96 mins, if speed in 60 miles per hr
}
TEST_F(StudentTest, AnotherTest) {
  HighSchoolStudent ft(2,"Komal", 91.73 , "F", "A","Pune", 3);
  Student *pt = &ft;
  EXPECT_EQ( 2, ft.getID());
  EXPECT_STREQ("F", ft.getGender().c_str());
  EXPECT_STREQ("Komal", ft.getName().c_str());
  EXPECT_EQ(91.73, ft.getPercantage());
  EXPECT_EQ(3, ft.getDistance());
  EXPECT_EQ(3, pt->computeTravelTime());
}

}


