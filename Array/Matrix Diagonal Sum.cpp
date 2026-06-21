#include <iostream>
#include <vector>
using namespace std;

int diagonalSum (vector<vector<int>>& matrix) {
	int n = matrix.size();
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		sum += matrix[i][i];           // main diagonal
		sum += matrix[i][n - i - 1];   // secondary diagonal
	}

	// If n is odd, subtract the middle element once because it was added twice
	if (n % 2 == 1) 
		sum -= matrix[n / 2][n / 2];

	return sum;
}


int main () {
	vector<vector<int>> matrix = { 
	                                {1, 2, 3},
	                                {4, 5, 6},
	                                {7, 8, 9},
	                           };

	cout << diagonalSum (matrix);

	return 0;
}

/*

Primary (Main) diagonal elements 	= matrix[i][i] 
Secondary diagonal elements 		= matrix[i][n - 1 - i]


*/