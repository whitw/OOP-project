#include "inf_int.h"
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	srand(unsigned int(time(NULL)));
	inf_int a;
	inf_int b(100);
	inf_int c(-273);
	inf_int d(INT_MAX);
	inf_int e(INT_MIN);
	//inf_int f("9321111111111122222822222223333333333NOTANUMBER34444444444455555555559"); //error
	inf_int f("899999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998");
	inf_int g("-899999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998");
	inf_int h = inf_int("+32768");
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	cout << g << endl;
	cout << h << endl;
	cout << inf_int(345) - inf_int(678) << endl;
	cout << inf_int(INT_MIN) - inf_int(INT_MIN) << endl;
	cout << inf_int(INT_MIN) - inf_int(INT_MIN + 1) << endl;

	cout << inf_int("123456789") + inf_int("9876543210") << endl;
	bool fail = false;
	cout << "===================== addition test =======================================" << endl;
	for (int i = 0; i < 1000000; i++) {
		int a = rand() + (rand() << 15), b = rand() + (rand() << 15);
		string temp;
		if (inf_int(to_string(long long(a) + long long(b)).c_str()) != inf_int(a) + inf_int(b)) { // a + b overflows often.
			fail = true;
			cout << a << " + " << b << " is " << (a) + long long(b) << ", not " << inf_int(a) + inf_int(b) << endl;
			cin >> temp;
		}
	}
	if (!fail) cout << "success." << endl;
	fail = false;
	cout << "===================== subtraction test =======================================" << endl;
	for (int i = 0; i < 1000000; i++) {
		string temp;
		int a = rand() + (rand() << 15), b = rand() + (rand() << 15);
		if (inf_int(a - b) != inf_int(a) - inf_int(b)) {
			fail = true;
			cout << a << " - " << b << " is " << a - b << ", not " << inf_int(a) - inf_int(b) << endl;
			cin >> temp;
		}
	}
	if (!fail) cout << "success." << endl;
	fail = false;
	cout << "===================== compare test =======================================" << endl;
	for (int i = 0; i < 1000000; i++) {
		string temp;
		int a = rand() + (rand() << 15), b = rand() + (rand() << 15);
		if ((inf_int(a) > inf_int(b)) != (a > b)) {
			fail = true;
			cout << a << " > " << b << " is " << (a > b) << ", not " << (inf_int(a) > inf_int(b)) << endl;
			cin >> temp;
		}
	}
	if (!fail) cout << "success." << endl;
	fail = false;
	cout << "===================== multiplication test =======================================" << endl;
	for (int i = 0; i < 1000000; i++) {
		string temp;
		int a = rand() + (rand() << 15), b = rand() + (rand() << 15);
		if ((inf_int(a) * inf_int(b)) != (long long(a) * long long(b))) {
			fail = true;
			cout << a << " * " << b << " is " << (a * b) << ", not " << (inf_int(a) * inf_int(b)) << endl;
			cin >> temp;
		}
	}
	if (!fail) cout << "not tested yet." << endl;
	fail = false;
	// cin >> g ;   // not required

	//a = b * c;
	// e=g/f;       // not required

	//b = c - d;


	//if (f == d) {
		//cout << "a : " << a << endl;
		//cout << "b : " << b << endl;
		//cout << "c : " << c << endl;
		//cout << "d : " << d << endl;
		// cout << "e : " << e << endl;
		//cout << "f : " << f << endl;
		// cout << "g : " << g << endl;
	//}

	return 0;
}
