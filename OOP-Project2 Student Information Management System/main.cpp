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
	StudentDB db = StudentDB("file1.txt");
	bool valid = false;
	valid = student->init("Valid Name", 1234567890, 123, "Valid Department", 1234567890);
	cout << "valid?(T)" << valid << endl;
	db.insert(student);
	db.print();
	student = new Student();
	valid = student->init("Wrooooooooooooooooong name", 1234567890, 123, "Valid Department", 1234567890);
	cout << "valid?(F)" << valid << endl;
	db.insert(student);
	db.print();
	student = new Student();
	valid = student->init("Valid Name", -135, 123, "Valid Department", 1234567890);
	cout << "valid?(F)" << valid << endl;
	if(valid)
		db.insert(student);
	db.print();
	cout << "\n";
	student = new Student();
	student->init("George", 1234567899, 3, "Here", 131);
	db.insert(student);
	db.print();
	cout << "\n";
	student = new Student();
	student->init("Aleph", 1234567897, 123, "There", 3334);
	db.insert(student);
	student = new Student();
	student->init("Zombie", 1234556782, 333, "Somewhere", 1237489);
	db.insert(student);
	db.print();
#endif
}
