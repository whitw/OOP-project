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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
}



bool operator==(const inf_int_b& a, const inf_int_b& b) {
	return false;
}

bool operator!=(const inf_int_b& a, const inf_int_b& b) {
	return !(a == b);
}

bool operator>(const inf_int_b&, const inf_int_b&) {
	//length��.
	//������ return a[0]-b[0]>0
	//�ٸ��� ��ȣ ���� +�ΰ�, �Ѵ� +�� �� ��. �� �� -�� ª����.
	return false;
}

bool operator<(const inf_int_b& a, const inf_int_b& b) {
	return (b > a);
}

inf_int_b operator+(const inf_int_b&, const inf_int_b&)
{
	//�ٸ� ��� ���� �׳� ������ ���Ѵ�.
	//�����÷ο쳪 ����÷ο찡 �� ��� ũ�⸦ Ű���� ��Ʈ�� ä���.

	return inf_int_b();
}

inf_int_b operator-(const inf_int_b&, const inf_int_b&)
{
	//+�� �θ���.
	return inf_int_b();
}

inf_int_b operator*(const inf_int_b&, const inf_int_b&)
{
	return inf_int_b();
}

ostream& operator<<(ostream&, const inf_int_b&)
{
	// ������ ��쿡�� -�� ����ϰ� ���� ���ϱ� 
	// �Ź� 10���� ������ �������� �������� ���.
}

istream& operator>>(istream&, inf_int_b&)
{
	// string �޾Ƽ� ������ ȣ��.
}