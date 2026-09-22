#include <iostream>
using namespace std;

int fib (int n) {
    if (n <= 0 || n == 1) return 0;
    if (n == 2) return 1;
    
	// ====== Recursive approach ======
    return fib (n - 1) + fib (n - 2);
    
    // ====== Iterative approach ======
    int prev1 = 0, prev2 = 1;
    int ans = 0;
    
    for (int i = 3; i <= n; i++) {
        ans = prev1 + prev2;
        
        prev1 = prev2;
        prev2 = ans;
    }
    
    return ans;
}

int main () {
	
	cout << fib (7);
	
	return 0;
} 