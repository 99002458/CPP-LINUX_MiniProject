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
/*
int getID();
    std::string getGender();
    std::string getName();
    std::string  getPercantage();
    int getDistance();
*/

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
}/*
TEST_F(StudentTest, AnotherTest) {
  FlightTrip ft("Bengaluru", "Chennai", "SG401", "SpiceJet", 200);
  Trip *pt = &ft;
  EXPECT_STREQ("Bengaluru", ft.getOrigin().c_str());
  EXPECT_STREQ("Chennai", ft.getDestination().c_str());
  EXPECT_STREQ("SG401", ft.getFlightNumber().c_str());
  EXPECT_STREQ("SpiceJet", ft.getOperator().c_str());
  EXPECT_EQ(200, ft.getDistance());
  EXPECT_EQ(2000, pt->computeFare());        //200 * 10 = 2000
  EXPECT_EQ(24, pt->computeTravelTime());    //24 mins, if speed is 500 miles per hr
}*/
} // namespace

