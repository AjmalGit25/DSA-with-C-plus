#include <iostream>
using namespace std;


// Iterative approach: O(e) Time and O(1) Space
double power (double b, int e) {
  
    // Initialize result to 1
    double pow = 1;

    // Multiply x for n times
    for (int i = 0; i < abs(e); i++) 
        pow = pow * b;
  	
  	if (e < 0)
      	return 1/pow;

    return pow;
}

// Recursive approach: O(e) Time and O(e) Space
double power (double b, int e) {
    if (e == 0)
        return 1;
  
    if (e < 0)
        return 1 / power (b, -e);
  
    return b * power (b, e - 1);				// works for small e	(use Fast Power)
}

int main() {
    double b = 3.0;
    int e = 5;
    
    cout << power (b, e);
    
    return 0;
}