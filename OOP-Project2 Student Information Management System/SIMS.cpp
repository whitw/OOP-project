#include "SIMS.h"
#include <iostream>

using namespace std;
SIMS::SIMS() {

}

void SIMS::start() {
	int input;
	SIMS::show_menu();
	do {
		cout << ">";
		cin >> input;
		if (cin.fail()) { //not integer
			cout << "Please input integer from 1 to 4" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			if (input < 1 || input > 4) {
				cout << "Please input integer from 1 to 4" << endl;
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
			return;
	}
}
void SIMS::reset() {
	//reset all variables.
	//works same as SIMS::~SIMS() -> SIMS::SIMS() but without reallocate data.
}

void SIMS::show_menu() {
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Exit" << endl;
}



void SIMS::insertion() {
	/*
	- Insertion -
	Name ?
	Student ID ?
	Age ?
	Department ?
	Tel ?
	*/
}

SIMS::~SIMS() {
	cout << "~SIMS()";
}