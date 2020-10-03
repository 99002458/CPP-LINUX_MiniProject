all.out : highSchoolStudent.cpp student.cpp studentDB.cpp student-test.cpp student-testDB.cpp  
	g++ highSchoolStudent.cpp student.cpp studentDB.cpp student-test.cpp student-testDB.cpp  -lgtest -lgtest_main -lpthread -o all.out

run:all.out
	./all.out

clean:
	rm all.out
