#include "inf_int.h"

using namespace std;

inf_int::inf_int() {
	length = 1;
	thesign = true; //consider 0 as positive
	digits = new char[1]{'0'}; //it's char*
							   //but it is NOT designed to be used as NULL-terminated string.
							   //inf_int::length is always same as length of digits
}

inf_int::inf_int(int dec){
	char data[20];
	if (dec == 0) {
		thesign = true;
		digits = new char[1]{'0'};
		length = 1;
	}
	else if (dec > 0) {
		int temp = dec;
		int i;
		thesign = true;
		for (i = 0;temp != 0; i++) {
			data[i] = temp % 10 + '0';
			temp /= 10;
		}
		digits = new char[i];
		memcpy(digits, data, i);
		length = i;
	}
	else {
		int temp = dec; //I won't use -dec, because it will cause error if dec is -2147483648
		int i;
		thesign = false;
		for (i = 0; temp != 0; i++) {
			data[i] = -(temp % 10) + '0';
			//(-16)-> (temp % 10 == -6)
			temp /= 10;
		}
		digits = new char[i];
		memcpy(digits, data, i);
		length = i;
	}
}
inf_int::inf_int(const char*) {

}
inf_int::inf_int(const inf_int&) { // copy constructor

}
inf_int::~inf_int() { delete digits; } // destructor

ostream& operator<<(ostream& out, const inf_int& data) {
	if (data.thesign) {
		for (int i = int(data.length - 1); i >= 0; i--) {
			out << data.digits[i];
		}
	}
	else {
		out << '-';
		for (int i = int(data.length - 1); i >= 0; i--) {
			out << data.digits[i];
		}
	}
	return out;
}