#include <iostream>
using namespace std;

// --------- Print N numbers ----------
void print(int n) {
    if (n == 0)
        return;

    cout << n << " ";        // before recursive call
    print(n - 1);            // go deeper
    cout << n << " ";        // after recursive call	(return/unwinding phase of recursion)
}

// ------------ Factorial -------------
int fact (int n){
    if (n == 0)
        return 1;
    
    return n * fact(n - 1);
}

// -------- Sum to N numbers ---------
int nSum (int n) {
    if (n == 1)
        return 1;
    
    return n + nSum(n - 1);
}

int main() {
	
	print(10);

	return 0;
}

/*

1. What is Recursion?

	-> Recursion is when a function calls itself.

	-> A recursive function has two important parts:

	Base case 		= when to stop
	Recursive case  = the function calls itself with a smaller/simpler input

	-> The function keeps going deeper until it reaches the base case, then comes back.


2. What is Backtracking?

	-> Backtracking is a problem-solving technique that usually uses recursion to explore different possibilities.

-----------------------------------------------------------------------------------------------------
do something
recursiveCall()
undo something


*/