#include <iostream>
using namespace std;

int add (int a, int b) {
	while (b != 0) {
		int carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}

	return a;
}

int main () {
	int a = 3;
	int b = 5;
	
	cout << getSum (a, b);

	return 0;
}

/*

Add two integers without using the + operator

	a ^ b 		 = adds bits without carry
	(a & b)		 = finds where a carry is generated
	carry << 1 	 = moves the carry to the next position


Repeat until there is no carry.

*/