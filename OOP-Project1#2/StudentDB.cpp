#include "studentDB.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <iomanip>

StudentDB::StudentDB() {
	filename = string("");
	canWriteOnFile = false;
}

StudentDB::StudentDB(string filename) {
	this->filename = filename;
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
		readFromFile();
	}
}

StudentDB::~StudentDB(){
	deleteDB();
}

void StudentDB::deleteDB() {
	size_t len = length();
	for (int i = 0; i < len; i++) {
		delete studentV[i];
	}
	studentV.clear();
}

void StudentDB::insert(Student* student){
	if (!student->isValid()) {
		delete student;
		return;
	}
	StudentDB* IDdata;
	IDdata = searchID(student->getID());
	if (IDdata->length() == 0)
		studentV.push_back(student);
	else cout << "Error: Already inserted" << endl;
}

StudentDB* StudentDB::searchName(string name){
	StudentDB* ret = new StudentDB();
	Student* each;
	size_t len = length();
	for (int i = 0; i < len; i++) {
		if (studentV[i]->getName() == name) {
			each = new Student();
			each->init(studentV[i]);
			ret->insert(each);
		}
	}
	return ret;
}

StudentDB* StudentDB::searchID(long long id){
	StudentDB* ret = new StudentDB();
	Student* each;
	size_t len = length();
	for (int i = 0; i < len; i++) {
		if (studentV[i]->getID() == id) {
			each = new Student();
			each->init(studentV[i]);
			ret->insert(each);
		}
	}
	return ret;
}

StudentDB* StudentDB::searchDepart(string department){
	StudentDB* ret = new StudentDB();
	Student* each;
	size_t len = length();
	for (int i = 0; i < len; i++) {
		if (studentV[i]->getDepartment() == department) {
			each = new Student();
			each->init(studentV[i]);
			ret->insert(each);
		}
	}
	return ret;
}

StudentDB* StudentDB::searchAge(int age){
	StudentDB* ret = new StudentDB();
	Student* each;
	size_t len = length();
	for (int i = 0; i < len; i++) {
		if (studentV[i]->getAge() == age) {
			each = new Student();
			each->init(studentV[i]);
			ret->insert(each);
		}
	}
	return ret;
}

void StudentDB::sort(bool (*comp_func)(const void*, const void*)) {
	std::sort(studentV.begin(), studentV.end(), comp_func);
}

bool sort_by_name(const void* a, const void* b) {
	Student* pa = (Student*)a;
	Student* pb = (Student*)b;
	string sa = pa->getName();
	string sb = pb->getName();
	//if sa == sb then compare with ID, if not, compare with just names.
	return sa == sb ? pa->getID() < pb->getID() : sa < sb;
}

void StudentDB::sort() {
	this->sort(sort_by_name);
}

bool StudentDB::readFromFile() {
	Student* student;
	if (canWriteOnFile) {
		ifstream ifs;
		ifs.open(filename.c_str(), ios::in | ios::binary);
		if (!ifs.is_open()) {
			return false;
		}
		while (!ifs.eof()) {
			char* line = new char[Student::blockSize];
			ifs.read(line, Student::blockSize);
			student = new Student();
			if (student->init(line) == true) {//data is valid
				this->insert(student);
				delete[] line;
			}
			else {
				delete student;
				ifs.close();
				delete[] line;
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
		ofs.write(bytes, Student::blockSize);
		delete[] bytes;
	}
	return true;
}

void StudentDB::print(){
	size_t len = length();
	sort();

	cout << std::left << setw(17) << "Name";
	cout << std::left << setw(12) << "Student ID";
	cout << std::left << setw(22) << "Department";
	cout << std::left << setw( 5) << "Age";
	cout << std::left << setw(12) << "tel" << endl;

	for (int i = 0; i < len; i++) {
		cout << std::left  << setw(17) << studentV[i]->getName();
		cout << std::right << setw(10) << setfill('0') << studentV[i]->getID() << setfill(' ') << "  ";
		cout << std::left  << setw(22) << studentV[i]->getDepartment();
		cout << std::left  << setw( 5) << studentV[i]->getAge();
		cout << std::left  << setw(12) << studentV[i]->getTel() << endl;
	}
	cout << endl;
}
