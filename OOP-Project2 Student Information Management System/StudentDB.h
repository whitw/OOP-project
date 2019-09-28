#pragma once
#include <vector>
#include <string>
#include "Student.h"

class StudentDB {
	/*
	StudentDB manage list of students, reading on and writing to file.
	*/
	vector<Student> studentV;
	string filename;
	bool canWriteOnFile = false;
public:
	// cannot read or write before you init the filename. use it for temporary student storage.
	StudentDB();
	//student storage, with ability to read and write to file.
	StudentDB(string filename); 
	//insert Student.
	void insert(Student student);
	size_t length() { return studentV.size(); }
	StudentDB searchname(string name);
	StudentDB searchID(int id);
	StudentDB searchDepart(string department);
	StudentDB searchAge(int age);
	
	//sort vector<Student> studentV by order of comp_func.
	void sort(int (*comp_func)(const void*, const void*));

	//read all of students from file.
	//if fail, return false.
	bool readFromFile();
	//write all of students to file. return the # of the data written successfully.
	bool writeToFile();

	void print();
};