#include "student.h"
#include <algorithm>


Student::Student() {
	Student::name = "Wrong Name";
	Student::studentID = 9999999999;
	Student::age = 999;
	Student::department = "Wrong Department";
	Student::tel = "999999999999";
}

Student::~Student() {
}

bool Student::init(string name, int64_t studentID, int age, string department, string tel)
{
	//valid check
	if (!isValid()) {
		return false;
	}

	Student::name = name;
	Student::studentID = studentID;
	Student::age = age;
	Student::department = department; 
	Student::tel = tel;
	return true;
}
bool Student::init(char* bytes) {
	char name[16];
	int64_t studentID;
	int32_t age;
	char department[24];
	char tel[12];
	memcpy(name, bytes, 16 - 1);
	name[15] = 0;
	memcpy(&studentID, bytes + 16, 8);
	memcpy(&age, bytes + 24, 4);
	memcpy(department, bytes + 28, 24 - 1);
	department[23] = 0;
	memcpy(&tel, bytes + 52, 12);
	tel[11] = 0;
	if (!validCheck(name, studentID, age, department, tel)) {
		return false;
	}

	Student::name = string(name);
	Student::studentID = studentID;
	Student::age = age;
	Student::department = string(department);
	Student::tel = string(tel);
	return true;
}
bool Student::validName(string name) {
	if (name.length() > 15)
		return false;
	if (name.length() == 0)
		return false;
	return true;
}
bool Student::validID(int64_t studentID) {
	if (studentID > 9999999999 || studentID < 0)
		return false;
	return true;
}
bool Student::validAge(int age) {
	if (age > 999 || age < 0)
		return false;
	return true;
}
bool Student::validDepartment(string department) {
	if (department.length() > 20)
		return false;
	if (department.length() == 0)
		return false;
	return true;
}
bool Student::validTel(string tel) {
	if (atoll(tel.c_str()) > 999999999999 || atoll(tel.c_str()) < 0)
		return false;
	return true;
}
bool Student::validCheck(string name, int64_t studentID, int age, string department, string tel) {
	if (!validName(name))
		return false;
	else if(!validID(studentID))
		return false;
	else if(!validAge(age))
		return false;
	else if (!validDepartment(department))
		return false;
	else if (!validTel(tel))
		return false;
	else return true;
}
string Student::getName() {
	return string(name);
}

long long Student::getID() {
	return studentID;
}

int Student::getAge() {
	return age;
}

string Student::getDepartment() {
	return string(department);
}

string Student::getTel() {
	return tel;
}

char* Student::toBytes() {
	if (!validCheck(name,studentID,age,department,tel)) {
		return NULL;
	}
	char* bytes = new char[blockSize];
	memcpy(bytes, name.c_str(), 16);
	memcpy(bytes + 16, &studentID, 8);
	memcpy(bytes + 24, &age, 4);
	memcpy(bytes + 28, department.c_str(), 24);
	memcpy(bytes + 52, tel.c_str(), 12);
	return bytes;
}