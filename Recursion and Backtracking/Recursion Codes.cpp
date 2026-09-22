#include <iostream>
using namespace std;

void greet (int n) {
    // base case
    if (n == 0) return;
    
    cout << "Hello ";
    greet (n - 1);
}


int n_sum(int n) {
    // base case
    if (n == 0) return 0;

    // recursive case
    return n + n_sum(n - 1);
}

int fact (int n) {
    // base case
    if (n == 0 || n == 1) return 1;
    
    return n * fact (n - 1);
}

int fib (int n) {
    // base case
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    return fib (n - 1) + fib (n - 2);
}

string rev_str (string str) {
    // base case
    if (str.empty()) return ""; 
    
    return rev_str (str.substr (1)) + str[0];
}

int main () {
	
    cout << n_sum (20) << endl;
    
    cout << fact (10) << endl;
    
    cout << fib (7) << endl;
    
    cout << rev_str ("xavier") << endl;
	
	string str = "xavier";
	cout << str.substr (2) << endl;
	
	cout << str.substr (5) + str[0] << endl;
	
	
	return 0;
}