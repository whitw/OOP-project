#include <iostream>
#include "inf_int_b.h"
using namespace std;


inf_int_b::inf_int_b() : inf_int_b::inf_int_b(0) {
}

inf_int_b::inf_int_b(int n) {
	digits = new int[1];
	digits[0] = n;
	length = 1; //length stands for size of digits
}

inf_int_b::inf_int_b(const char* s) {//dec to bytes

}

inf_int_b::inf_int_b(const inf_int_b& other) {
	digits = new int[other.length];
	length = other.length;
	memcpy(digits, other.digits, sizeof(int) * length);
}

inf_int_b::~inf_int_b() {
	delete digits;
}

inf_int_b& inf_int_b::operator=(const inf_int_b&) {
	// TODO: 여기에 반환 구문을 삽입합니다.
}



bool operator==(const inf_int_b& a, const inf_int_b& b) {
	return false;
}

bool operator!=(const inf_int_b& a, const inf_int_b& b) {
	return !(a == b);
}

bool operator>(const inf_int_b&, const inf_int_b&) {
	//length비교.
	//같으면 return a[0]-b[0]>0
	//다르면 부호 비교후 +인거, 둘다 +면 긴 거. 둘 다 -면 짧은거.
	return false;
}

bool operator<(const inf_int_b& a, const inf_int_b& b) {
	return (b > a);
}

inf_int_b operator+(const inf_int_b&, const inf_int_b&)
{
	//다른 계산 없이 그냥 무작정 더한다.
	//오버플로우나 언더플로우가 날 경우 크기를 키워서 비트를 채운다.

	return inf_int_b();
}

inf_int_b operator-(const inf_int_b&, const inf_int_b&)
{
	//+를 부른다.
	return inf_int_b();
}

inf_int_b operator*(const inf_int_b&, const inf_int_b&)
{
	return inf_int_b();
}

ostream& operator<<(ostream&, const inf_int_b&)
{
	// 음수일 경우에는 -를 출력하고 역수 취하기 
	// 매번 10으로 나누고 나머지를 역순으로 출력.
}

istream& operator>>(istream&, inf_int_b&)
{
	// string 받아서 생성자 호출.
}