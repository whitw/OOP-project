#include "studentDB.h"
#include <fstream>
#include <algorithm>
#include <iostream>

StudentDB::StudentDB() {
	studentV.clear();
	filename = string("");
	canWriteOnFile = false;
}

StudentDB::StudentDB(string filename) {
	studentV.clear();
	StudentDB::filename = filename;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open()) { //fail to open the file
		ofstream ofs;
		ofs.open(filename, ios::out);
		if (!ofs.is_open()) { //fail to open new file/ or some other reason.
			canWriteOnFile = false;
		}//No file->create file
		canWriteOnFile = true;
		ofs.close();
	}
	else {//No error.
		canWriteOnFile = true;
		ifs.close();
	}
}

StudentDB::~StudentDB(){
	size_t len = length();
	for (int i = 0; i < len; i++) {
		delete studentV[i];
	}
}
void StudentDB::insert(Student* student){
	if (!student->isValid()) {
		delete student;
		return;
	}
	if (canWriteOnFile) {
		studentV.push_back(student);
	}
}

StudentDB StudentDB::searchname(string name){
	return StudentDB();
}

StudentDB StudentDB::searchID(int id){
	return StudentDB();
}

StudentDB StudentDB::searchDepart(string department){
	return StudentDB();
}

StudentDB StudentDB::searchAge(int age){
	return StudentDB();
}
void StudentDB::sort(bool (*comp_func)(const void*, const void*)) {
	std::sort(studentV.begin(), studentV.end(), comp_func);
}

bool sort_by_name(const void* a, const void* b) {
	Student* pa = (Student*)a;
	Student* pb = (Student*)b;
	return pa->getName() < pb->getName();
}

void StudentDB::sort() {
	StudentDB::sort(sort_by_name);
}

bool StudentDB::readFromFile() {
	char line[60] = { 0 };
	Student* student;
	if (canWriteOnFile) {
		ifstream ifs;
		ifs.open(filename.c_str(), ios::in | ios::binary);
		if (!ifs.is_open()) {
			return false;
		}
		while (!ifs.eof()) {
			ifs.read(line, 60);
			student = new Student();
			if (student->init(line) == true) {//data is valid
				StudentDB::insert(student);
			}
			else {
				delete student;
				ifs.close();
				return false;
			}
		}
	}
	return true;
}

bool StudentDB::writeToFile() {
	size_t len = length();
	ofstream ofs;
	char* bytes;
	ofs.open(filename.c_str(), ios::out | ios::binary);
	if (!ofs.is_open())
		return false;
	for (int i = 0; i < len; i++) {
		bytes = studentV[i]->toBytes();
		ofs.write(bytes, 60);
		delete[] bytes;
	}
	return true;
}

void StudentDB::print(){
	size_t len = length();
	StudentDB::sort();
	for (int i = 0; i < len; i++) {
		std::cout << studentV[i]->getName() << studentV[i]->getID() << studentV[i]->getDepartment() << studentV[i]->getAge() << studentV[i]->getTel() << endl;
	}
}
