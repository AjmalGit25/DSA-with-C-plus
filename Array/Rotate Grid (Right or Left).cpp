#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Rotate grid (90 degree clockwise):
void rotateGrid (vector<vector<int>>& matrix) {
	int n = matrix.size();

	// Step 1: Transpose (Swap across the main diagonal)
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			swap (matrix[i][j], matrix[j][i]);
		}
	}

	// Step 2: Reverse each row
	for (int i = 0; i < n; i++) {
		reverse (matrix[i].begin(), matrix[i].end());
	}
}

// left rotate (90 degree anti-clockwise)
void rotateGrid (vector<vector<int>>& matrix) {
	int n = matrix.size();

	// Step 1: Transpose (Swap across the main diagonal)
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			swap (matrix[i][j], matrix[j][i]);
		}
	}

	// Step 2: Reverse each column
	for (int col = 0; col < n; col++) {
		int top = 0, bottom = n - 1;

		while (top < bottom) {
			swap (matrix[top][col], matrix[bottom][col]);
			top++;
			bottom--;
		}
	}
}

int main () {
	vector<vector<int>> grid = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	
	rotateGrid (grid);
	
	cout << "Rotate grid (90 degree clockwise): \n";
	
	for (const auto& rows : grid) {
	    for (const auto& val : rows) {
	        cout << val << " ";
	    }
	    cout << endl;
	}

	return 0;
}

/*

Rotate Grid Right (clockwise 90 deg):
	i) 	Transpose the grid
	ii) Reverse each row


Rotate Grid Left (anti-clockwise 90 deg):
	i) 	Transpose the grid
	ii) Reverse each column

-> We cand rotate in-place only if square matrix (n × n).

What if the matrix is not square?
	Example:
			2 x 3 becomes	3 x 2

			1 2 3			4 1
			4 5 6			5 2
							6 3

	For rectangular matrices, you typically create a new matrix:	vector<vector<int>> rotated (cols, vector<int>(rows));


*/