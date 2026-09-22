#include <iostream>
using namespace std;

int power (int base, int exponent) {
	if (exponent == 0) return 1;
	if (exponent == base) return base;
	
	return base * power (base, exponent - 1);
}

int main () {
	cout << power (4, 3) << endl;
	
	return 0;
} 