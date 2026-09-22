#include <iostream>
using namespace std;

string revStr (string s) {
    // base case
    if (s.empty()) return "";
    
    return revStr (s.substr (1)) + s[0];
}

int main () {
	string res;
	cout << rev_str ("ABC");
	
	
	return 0;
}

/*

substr (0) means Remove substring from index 0 to 0		| "ABC".substr (0) = ABC
substr (1) means Remove substring from index 0 to 1 	| "ABC".substr (1) = BC
substr (2) means Remove substring from index 0 to 2 	| "ABC".substr (2) = C
substr (3) means Remove substring from index 0 to 3 	| "ABC".substr (3) = ""

*/