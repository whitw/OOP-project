#include "inf_int.h"

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
/****************************
        constructor
*****************************/
inf_int::inf_int() {
	*this = inf_int(0); //operator=(this, inf_int(0)). slower, but easy to modify.
}

inf_int::inf_int(int dec){
	char data[20] = {0};
	if (dec == 0) {
		thesign = true;
		digits = new char[2]{'0', 0};
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
		data[i] = 0;
		digits = new char[i + 1];
		memcpy(digits, data, i + 1);
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
		digits = new char[i + 1];
		memcpy(digits, data, i + 1);
		digits[i] = 0;
		length = i;
	}
}
inf_int::inf_int(const char* data) {
	int readfrom = 0;
	if (strlen(data) == 1 && data[0] == '0') { //data == "0"
		*this = inf_int(0);
		return;
	}
	if (data[0] > '0' && data[0] <= '9') { //data is positive
		thesign = true;
		length = strlen(data);
	}
	else if (data[0] == '+') {
		thesign = true;
		readfrom = 1;
	}
	else if (data[0] == '-') {
		thesign = false;
		readfrom = 1;
	}
	else throw -1;
	data += readfrom; // leave digits only. e.g. ['1','2','3','4','5','\0']
	length = strlen(data); //e.g. 5
	digits = new char[length + 1];
	for (unsigned int i = 0; i < length; i++) {
		digits[i] = data[length - 1 - i];
		if (data[length - 1 - i] < '0' || data[length - 1 - i] > '9')
			throw - 1;
	}
	digits[length] = 0;
}
inf_int::inf_int(const inf_int& from) { // copy constructor
	*this = from;
}
inf_int::~inf_int() { delete digits; } // destructor

/******************************
         operators
*******************************/
inf_int& inf_int::operator=(const inf_int& from) {
	length = from.length;
	thesign = from.thesign;
	digits = new char[length + 1];
	memcpy(digits, from.digits, length);
	digits[length] = 0;
	return *this;
}

bool operator==(const inf_int& a, const inf_int& b) {
	return (a.thesign == b.thesign && a.length == b.length && strncmp(a.digits, b.digits, a.length) == 0);
}
bool operator!=(const inf_int& a, const inf_int& b) {
	return !(a == b);
}
bool operator>(const inf_int& a, const inf_int& b) {
	if (a.thesign ^ b.thesign) { //sign is different
		return a.thesign;
	}
	else if(a.thesign) { //compare two positive numbers
		if (a.length != b.length) {
			return a.length > b.length;
		}
		else { //and length are same.
			for (int i = a.length - 1; i >= 0; i--) {
				if (a.digits[i] != b.digits[i])
					return a.digits[i] > b.digits[i];
			}
			//both are same number
			return false;
		}
	}
	else { //compare two negative numbers
		if (a.length != b.length) {
			return a.length < b.length;
		}
		else {//and length are same
			for (int i = a.length - 1; i >= 0; i--) {
				if (a.digits[i] != b.digits[i])
					return a.digits[i] < b.digits[i];
			}
			//both are same number
			return false;
		}

	}
}
bool operator<(const inf_int& a, const inf_int& b) {
	return (b > a);
}

inf_int operator+(const inf_int& a, const inf_int& b) {
	int carry = 0;
	int temp_sum = 0;
	inf_int result;
	if (a.thesign == b.thesign) {
		result.thesign = a.thesign;
		result.length = max(a.length, b.length);
		char* newdigits = (char*)realloc(result.digits, result.length + 1);
		if (newdigits == NULL) {
			cout << "Memory reallocation failed, the program will terminate." << endl;
			exit(0);
		}
		else result.digits = newdigits;
		for (unsigned int i = 0; i < result.length + 1; i++) {
			char adigit = i < a.length ? a.digits[i] : '0';
			char bdigit = i < b.length ? b.digits[i] : '0';

			temp_sum = adigit + bdigit + carry - '0' - '0';
			result.digits[i] = (temp_sum % 10) + '0';
			carry = temp_sum / 10;
		}
		if (carry) {
			result.digits[result.length] = carry + '0';
			result.length++;
			newdigits = (char*)realloc(result.digits, result.length + 1); //buffer is not big enough. size up by 1 byte.
			if (newdigits == NULL) {
				cout << "Memory reallocation failed, the program will terminate." << endl;
				exit(0);
			}
			else result.digits = newdigits;
		}
		result.digits[result.length] = 0;
	}
	else { // (+) + (-). result can be 0
		inf_int ua = a, ub = b;
		ua.thesign = true;
		ub.thesign = true;
		result.thesign = a.thesign;
		if (ua < ub) {
			inf_int utemp;
			utemp = ua;
			ua = ub;
			ub = utemp;
			result.thesign = b.thesign;
		}
		else if (ua == ub) {//sign is opposite, size is same.
			return inf_int(0);
		}
		//digits of ua is always bigger than those of ub
		result.length = ua.length;
		char* newdigits = (char*)realloc(result.digits, result.length + 1);
		if (newdigits == NULL) {
			cout << "Memory reallocation failed, the program will terminate." << endl;
			exit(0);
		}
		else result.digits = newdigits;
		int sub; //ua.digits[i] - ub.digits[i] (number form, not one digit char.)
		for (unsigned int i = 0; i < ua.length; i++) {
			sub = ua.digits[i] - (i < ub.length ? ub.digits[i] : '0');
			if (sub < 0) { //13 - 7, i = 0 ==>> 3 - 7 < 0
				sub += 10;
				ua.digits[i + 1] -= 1;
				//DON'T care if ua.digits[i+1] WAS 0.
				//it will become -1, and then fixed after next iteration.
				//ua will disappear after the addition.
			}
			result.digits[i] = sub + '0'; //num to digit
		}
		for (unsigned int i = ua.length - 1; i > 0 && result.digits[i] == '0'; i--) {
			result.length--;
		}
		newdigits = (char*)realloc(result.digits, result.length + 1);
		if (newdigits == 0) {
			cout << "Memory reallocation failed, the program will terminate." << endl;
			exit(0);
		}
		else result.digits = newdigits;
		result.digits[result.length] = 0;
	}
	return result;
}
inf_int operator-(const inf_int& a, const inf_int& b) {
	inf_int minusB = b;
	minusB.thesign = !minusB.thesign;
	return a + minusB;
}

inf_int operator*(const inf_int& a, const inf_int& b) {
	return inf_int(0);
}



ostream& operator<<(ostream& out, const inf_int& data) {
	if(!data.thesign)
		out << '-';
	for (int i = int(data.length - 1); i >= 0; i--) {
		out << data.digits[i];
	}
	return out;
}

istream& operator>>(istream& in, inf_int& data) {
	string str;
	in >> str;
	try {
		data = inf_int(str.c_str());
	}
	catch (int) { //not an integer. cin.fail() is now true.
		in.setstate(ios::failbit);
	}
	return in;
}
