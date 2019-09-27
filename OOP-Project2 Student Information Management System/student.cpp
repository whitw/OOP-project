#include "student.h"
#include <algorithm>


Student::Student() {
	Student::name = "Wrong Name";
	Student::studentID = 9999999999;
	Student::age = 999;
	Student::department = "Wrong Department";
	Student::tel = 999999999999;
}

Student::~Student() {
}

bool Student::init(string name, long long studentID, int age, string department, long long tel)
{
	//valid check
	if (name.length() > 15)
		return false;
	if (studentID < 1000000000 || studentID > 9999999999)
		return false;
	if (age > 999)
		return false;
	if (department.length() > 20)
		return false;
	if (tel > 999999999999)
		return false;

	Student::name = name;
	Student::studentID = studentID;
	Student::age = age;
	Student::department = department; 
	Student::tel = tel;
	return true;
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

long long Student::getTel() {
	return tel;
}
