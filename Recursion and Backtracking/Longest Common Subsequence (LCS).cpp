#include <iostream>
#include <string>
using namespace std;

int LCS(const string &X, const string &Y, int m, int n) {
    // Base case: if either string is empty
    if (m == 0 || n == 0)
        return 0;
    
    // If last characters match
    if (X[m - 1] == Y[n - 1])
        return 1 + LCS(X, Y, m - 1, n - 1);	// If last characters match, you take that step and move both pointers back (m-1, n-1).
    else
        // If last characters don't match
        return max(LCS(X, Y, m - 1, n), LCS(X, Y, m, n - 1));	// If they don't match, you try excluding the last character from X (call LCS(m-1, n)), or excluding the last character from Y (call LCS(m, n-1)), and take the maximum.
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int m = X.length();
    int n = Y.length();

    cout << "Length of LCS: " << LCS(X, Y, m, n) << endl;

    return 0;
} 

/*
LCS(X, Y, m - 1, n): Exclude last character of X
LCS(X, Y, m, n - 1): Exclude last character of Y

*/
