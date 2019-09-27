#include <iostream>
#include "SIMS.h"
#include "student.h"
#define DEBUG
//#undef DEBUG
using namespace std;


int main(int argc, char* argv[]) {
#ifndef DEBUG
	string fileName = "file1.txt"; //default filename.
	if (argc >= 2) {
		fileName = string(argv[1]);
		//file existence will be checked by StudentDB.
		//file validitiy will be checked by Student.
	}
	//else(=>no argv): filename will automatically become "file1.txt"
	SIMS sm = SIMS(fileName);
	while (sm.isrunning() == true) {
		sm.start();
	}
	return 0;
#else
	//test for SIMS, StudentDB, Student
	cout << "SIMS TEST" << endl;
	SIMS* sm = new SIMS("testfile.txt");
	cout << "SIMS::Insert" << endl;
	sm->insertion();
	cout << "SIMS::Search" << endl;
	sm->search();
	delete sm;
	cout << endl << endl << endl;
	cout << "STUDENT TEST" << endl;
	Student* student = new Student();
	bool valid = false;
	valid = student->init("Valid Name", 1234567890, 123, "Valid Department", 1234567890);
	cout << student->getID() << endl;
	cout << "valid?(T)" << valid << endl;
	valid = student->init("Wrooooooooooooooooong name", 1234567890, 123, "Valid Department", 1234567890);
	cout << "valid?(F)" << valid << endl;
	valid = student->init("Valid Name", -135, 123, "Valid Department", 1234567890);
	cout << "valid?(F)" << valid << endl;

#endif
}
