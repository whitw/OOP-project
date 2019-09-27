#pragma once
#include <vector>
#include <string>
using namespace std;

class Student {
	string name;
	int studentID;
	int age;
	string department;
	string tel;
public:
	Student();
	
};


class StudentDB {
	vector<Student> studentV;
public:
	StudentDB() {

	}
	void insert(Student student);
	StudentDB searchname(string name);
	StudentDB searchID(int id);
	StudentDB searchDepart(string department);
	StudentDB searchAge(int age);
	void print();
};