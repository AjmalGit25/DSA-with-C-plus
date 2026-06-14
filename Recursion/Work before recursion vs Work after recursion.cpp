#include <iostream>
using namespace std;


void printNumbers (int n) {
    if (n == 0)
        return;
    
    cout << n << " ";				// Work before recursion	Print result: n to 1 |	 	5 4 3 2 1

    printNumbers (n - 1);
    
    cout << n << " ";				// Work after recursion		Print result: 1 to n | 		1 2 3 4 5
}

int main () {
	
    printNumbers (5);
    
    return 0;
}


/*

Work before recursion vs Work after recursion:


*/