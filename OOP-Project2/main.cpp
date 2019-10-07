#include "inf_int.h"
#include <iostream>
#include <limits>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

using namespace std;

int main()
{
	inf_int a;
	inf_int b(100);
	inf_int c(-273);
	inf_int d(INT_MAX);
	inf_int e(INT_MIN);
	//inf_int f("9321111111111122222822222223333333333NOTANUMBER34444444444455555555559"); //error
	inf_int f("899999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998");
	inf_int g("-899999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998");
	inf_int h("+32768");
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	cout << g << endl;
	cout << h << endl;
	cout << "input any integer: ";
	cin >> g;
	if (cin.fail()) {
		cout << "seems like it is not a proper integer." << endl;
	}
	cout << g << endl;
	g = b;
	cout << g << endl;
	//inf_int c("321111111111122222222222233333333333444444444445555555555");
	//inf_int d("123451987651234572749499923455022211");
	//inf_int f = d;
	//inf_int g(f);

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
