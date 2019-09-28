#pragma once
#include <string>
using namespace std;


//Student class manage for single Student.
class Student {

	string name; // up to 15 english characters.
	int64_t studentID; // exactly 10 digits. Interpret 3 as 0000000003
	int32_t age; //up to 3 digits
	string department; // up to 20 english characters
	int64_t tel; // up to 12 digits
	bool valid = false;
	bool validCheck(string name, long long studentID, int age, string department, long long tel);
public:
	Student();
	~Student();

	//string name(len<=15), long long studentID(len=10), int age(len<=3), string department(len<=20), long long tel(len<=12)
	//if the data are not valid, the data won't be changed and it will return false
	bool init(string name, long long studentID, int age, string department, long long tel);
	bool init(char* bytes);
	bool isValid() { return valid; };
	string getName();
	long long getID();
	int getAge();
	string getDepartment();
	long long getTel();
	char* toBytes();
};