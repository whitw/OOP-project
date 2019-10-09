#pragma once
#ifndef _INF_INT_B_H_
#define _INF_INT_B_H_

#include <iostream>

using namespace std;
class inf_int_b
{
private:
	int* digits;
	unsigned int length;

public:
	inf_int_b();               // assign 0 as a default value
	inf_int_b(int);
	inf_int_b(const char*);
	inf_int_b(const inf_int_b&); // copy constructor
	~inf_int_b(); // destructor

	inf_int_b& operator=(const inf_int_b&); // assignment operator

	friend bool operator==(const inf_int_b&, const inf_int_b&);
	friend bool operator!=(const inf_int_b&, const inf_int_b&);
	friend bool operator>(const inf_int_b&, const inf_int_b&);
	friend bool operator<(const inf_int_b&, const inf_int_b&);

	friend inf_int_b operator+(const inf_int_b&, const inf_int_b&);
	friend inf_int_b operator-(const inf_int_b&, const inf_int_b&);
	friend inf_int_b operator*(const inf_int_b&, const inf_int_b&);
	// friend inf_int_b operator/(const inf_int_b& , const inf_int_b&); // not required

	friend ostream& operator<<(ostream&, const inf_int_b&);
	friend istream& operator>>(istream&, inf_int_b&);    // not required
};

#endif