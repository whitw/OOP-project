#include "SIMS.h"
#include <iostream>

using namespace std;
SIMS::SIMS(string filename) {
	SIMS::filename = filename;
	db = StudentDB(filename);
}

void SIMS::start() {
	int input;
	SIMS::show_menu();
	do {
		cout << ">";
		cin >> input;
		if (cin.fail()) { //not integer
			cout << "Please input integer between 1 and 3" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			if (input < 1 || input > 3) {
				cout << "Please input integer between 1 and 3" << endl;
			}
			else
				break;
		}
	} while (true);
	//DO TASK
	switch (input) {
		case 1://Insertion
			SIMS::insertion();
			break;
		case 2://Search
			SIMS::search();
			break;
		case 3: //EXIT
			running = false;
			db.writeToFile();
			return;
	}
}

void SIMS::show_menu() {
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Exit" << endl;
}

void SIMS::insertion() {
	char name[256];
	string studentID;
	int age;
	char department[256];
	long long int tel;
	Student* student = new Student();
	/*
	- Insertion -
	Name ?
	Student ID ?
	Age ?
	Department ?
	Tel ?
	*/
	cout << "- Insertion -" << endl;
	cin.ignore(256, '\n');
	do {
		cout << "Name ";
		cin.getline(name, 256);
	} while (!Student::validName(name));
	do {
		cout << "Student ID ";
		cin >> studentID;
	} while (!Student::validID(atoll(studentID.c_str())));
	do {
		cout << "Age ";
		cin >> age;
	} while (!Student::validAge(age));
	cin.ignore(256, '\n');
	do {
		cout << "Department ";
		cin.getline(department, 256);
	} while (!Student::validDepartment(department));
	do {
		cout << "Tel ";
		cin >> tel;
	} while (!Student::validTel(tel));
	student->init(name, atoll(studentID.c_str()), age, department, tel);
	db.insert(student);
}

SIMS::~SIMS() {
}