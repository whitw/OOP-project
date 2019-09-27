#pragma once
#include "student.h"
#include "StudentDB.h"
#include <string>

//Student Information Management System
class SIMS {
	bool running = true;
	StudentDB* db;
	string filename;

	//those will be called by SIMS itself.

	//search by name from StudentDB* db
	void search_name();
	//search by student ID from StudentDB* db
	void search_studentID();
	//search by department from StudentDB* db
	void search_department();
	//search by age from StudentDB* db
	void search_age();
	//list all of students in StudentDB* db
	void search_listall();

public:
	SIMS(string filename);
	~SIMS();
	bool isrunning() { return running; }
	//run the SIMS.
	void start();
	//show the first menu. Nothing else.
	void show_menu();
	//show the search menu. Nothing else.
	void show_search_menu();
	//Insertion screen and execution.
	void insertion();

	//search screen and execution.
	void search();
};
