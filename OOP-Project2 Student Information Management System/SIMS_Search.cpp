#include <iostream>
#include "SIMS.h"

using namespace std;

void SIMS::show_search_menu() {
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID (10 numbers)" << endl;
	cout << "3. Search by department name" << endl;
	cout << "4. Search by age" << endl;
	cout << "5. List All" << endl;
}


void SIMS::search() {
	int input;
	show_search_menu();
	cout << "> ";
	while (true) {
		cin >> input;
		if (cin.fail()) {
			cout << "Please input integer between 1 and 5";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else if (input < 1 || input > 5) {
			cout << "Please input integer between 1 and 5";
		}
		else break;
	}
	switch (input) {
	case 1:
		search_name();
		break;
	case 2:
		search_studentID();
		break;
	case 3:
		search_department();
		break;
	case 4:
		search_age();
		break;
	case 5:
		search_listall();
		break;
	}
}

void SIMS::search_name() {
	char input[256];
	StudentDB* result;
	cout << "Name keyword? ";
	cin.ignore(256, '\n');
	cin.getline(input, 256);
	result = db.searchName(input);
	result->print();
	delete result;
}

void SIMS::search_studentID() {
	string input;
	int64_t id;
	StudentDB* result;
	cout << "Student ID? ";
	cin >> input;
	id = atol(input.c_str());
	result = db.searchID(id);
	result->print();
	delete result;
}

void SIMS::search_department() {
	string input;
	StudentDB* result;
	cout << "Department name keyword? ";
	cin >> input;
	result = db.searchDepart(input);
	result->print();
	delete result;
}

void SIMS::search_age() {
	int input;
	StudentDB* result;
	cout << "Age? ";
	cin >> input;
	result = db.searchAge(input);
	result->print();
	delete result;
}

void SIMS::search_listall() {
	db.print();
}
