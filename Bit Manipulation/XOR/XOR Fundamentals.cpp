#include <iostream>
using namespace std;

int main () {
		
	cout << (7 ^ 7);				// 0
	cout << (11 ^ 11);				// 0
	cout << (2 ^ 2);				// 0
	
	vector<int> arr = {2, 5, 3, 5, 2};
	
	int res = 2 ^ 5 ^ 3 ^ 5 ^ 2;
	
	cout << res;

	return 0;
}

/*

XOR
	-> Same bits		= 0
	-> Different bits	= 1
	-> Same numbers XOR gives 0
	-> XOR gives 1 only when the bits are different.
	-> XOR is Commutative & Associative
	
		a ^ a = 0
		a ^ 0 = a
		a ^ b = b ^ a          		// Commutative
		(a ^ b) ^ c = a ^ (b ^ c)  	// Associative


		x ^ x = 0
		x ^ y = z then x ^ z = y

--------------------------------------------------------
Exanple: 5 ^ 5 = 0
	0101
	0101
	----
	0000




*/