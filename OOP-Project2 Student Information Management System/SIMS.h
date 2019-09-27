#pragma once
#include "student.h"

class SIMS {
	bool running = true;
	//StudentDB* db = NULL;

public:
	SIMS();
	~SIMS();
	bool isrunning() { return running; }
	void start();
	void reset();
	void show_menu();
	void show_search_menu();
	void insertion();
	void search();
		void search_name();
		void search_studentID();
		void search_department();
		void search_age();
		void search_listall();
};
