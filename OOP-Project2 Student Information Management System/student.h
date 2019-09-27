#pragma once
#include <string>
using namespace std;


//Student class manage for single Student.
class Student {

	string name; // up to 15 english characters.
	long long studentID; // exactly 10 digits.
	int age; //up to 3 digits
	string department; // up to 20 english characters
	long long tel; // up to 12 digits
public:
	Student();
	~Student();

	//string name(len<=15), long long studentID(len=10), int age(len<=3), string department(len<=20), long long tel(len<=12)
	//if the data are not valid, the data won't be changed and it will return false
	bool init(string name, long long studentID, int age, string department, long long tel);

	string getName();
	long long getID();
	int getAge();
	string getDepartment();
	long long getTel();

};

