#include <iostream>
using namespace std;


int gcd (int a, int b) {
    if (b == 0)
        return a;

    return gcd (b, a % b);
}

int main () {
    
    cout << gcd(20, 28);
    
    return 0;
}

/*

GCD using Recursion:
	The standard recursive solution uses the Euclidean Algorithm.
	
	Idea:
		-> GCD(a, b) = GCD(b, a % b)
		-> Repeat until b becomes 0.


*/