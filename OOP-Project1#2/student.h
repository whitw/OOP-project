#pragma once
#include <string>
using namespace std;


//Student class manage for single Student.
class Student {

	string name; // up to 15 english characters.
	int64_t studentID; // exactly 10 digits. Interpret 3 as 0000000003
	int32_t age; //up to 3 digits
	string department; // up to 20 english characters
	string tel; // up to 12 digits. it is string, not int64_t. I WANT to distinguish 001 and 01 and 1.

public:
	Student();
	~Student();
	
	//string name(len<=15), long long studentID(len=10), int age(len<=3), string department(len<=20), long long tel(len<=12)
	//if the data are not valid, the data won't be changed and it will return false
	bool init(string name, int64_t studentID, int age, string department, string tel);

	//it takes data from file. bytes are Student::blockSize long.
	bool init(char* bytes);

	//copy data from another student.
	bool init(Student* student);
	//check if these data are valid. false if not.
	//they are static, which means it can be used without creating instances.
	//can be used as someting like Student::validName("some name").
	static bool validName(string name);
	static bool validID(int64_t id);
	static bool validAge(int age);
	static bool validDepartment(string department);
	static bool validTel(string tel);
	static bool validCheck(string name, int64_t studentID, int age, string department, string tel);
	bool isValid() { return validCheck(name,studentID,age,department,tel); }

	//getter.
	string getName();
	long long getID();
	int getAge();
	string getDepartment();
	string getTel();
	
	//No modifiy, No delete.
	//No setter thus.

	//convert student data to 64bytes block.
	const static int blockSize = 64;
	//convert student data to bytes. It return new char[64], so the return value MUST be deleted after use.
	char* toBytes();
};