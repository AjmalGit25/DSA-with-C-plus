#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* Traversal of 2D Vector */


int main () {
	vector<vector<int>> matrix  = {
		{1, 2, 1},
		{2, 3, 5},
		{1, 0, 2},
	};

	int r = matrix.size();
	int c = matrix[0].size();

	// Row-wise Traversal
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n";

	// Column-wise Traversal
	for (int j = 0; j < c; j++) {
		for (int i = 0; i < r; i++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "\n";

	// Better (Modern C++ Range Based Loop)
	for (auto &row : matrix) {
		for (auto &val : row) {
			cout << val << " ";
		}
		cout << endl;
	}

	cout << "\n";
    

	bool found = false;
	// Stop entire traversal
	for (int i = 0; i < r && !found; i++) {
		for (int j = 0; j < c; j++) {
			if (matrix[i][j] == 0) {
				found = true;
				break;
			}
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

/*



*/