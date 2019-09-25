#pragma once
#include <vector>
#include <string>
using namespace std;

class student {
	string name;
	int studentID;
	int age;
	string department;
	string tel;
public:
	student();
	
};


class studentDB {
	vector<student> studentV;
public:
	studentDB() {

	}
	void insert(student student);
	studentDB searchname(string name);
	studentDB searchID(int id);
	studentDB searchDepart(string department);
	studentDB searchAge(int age);
	void print();
};