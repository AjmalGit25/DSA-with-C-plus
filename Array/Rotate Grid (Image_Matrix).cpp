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

Rotate Grid (Image/Matrix):
	i) 	Transpose the grid
	ii) Reverse each row

-> We cand rotate in-place only if square matrix (n × n).

*/