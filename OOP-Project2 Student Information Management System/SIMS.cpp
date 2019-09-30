#include "SIMS.h"
#include <iostream>

using namespace std;
SIMS::SIMS(string filename) {
	SIMS::filename = filename;
	db = new StudentDB(filename);
}

void SIMS::start() {
	int input;
	do {
		SIMS::show_menu();
		cout << "> ";
		cin >> input;
		if (cin.fail()) { //not integer
			cout << "Please input integer between 1 and 3" << endl << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			if (input < 1 || input > 3) {
				cout << "Please input integer between 1 and 3" << endl << endl;
			}
			else
				break;
		}
	} while (true);
	cin.ignore(256, '\n');
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
			return;
	}
}

void SIMS::show_menu() {
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Exit" << endl << endl;
}

void SIMS::insertion() {
	char name[256];
	string studentID;
	int age = -1;
	char department[256];
	char tel[256];
	Student* student = new Student();

	cout << "- Insertion -" << endl;
	do {
		cout << "Name ";
		cin.getline(name, 256);
	} while (!Student::validName(name));

	do {
		cout << "Student ID ";
		cin >> studentID;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		StudentDB* IDdata = db->searchID(atoll(studentID.c_str()));
		if (IDdata->length() > 0) {
			cout << "Error: Already Inserted" << endl << endl;
			delete student;
			return;
		}
		delete IDdata;
	} while (studentID.length() != 10 || !Student::validID(atoll(studentID.c_str())));

	do {
		cout << "Age ";
		cin >> age;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
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
	db->insert(student);
	db->writeToFile();
}

SIMS::~SIMS() {
	delete db;
}