#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> makeTranspose (vector<vector<int>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	vector<vector<int>> transpose (cols, vector<int> (rows)); // Dimensions swapped

	// row-by-row
	for (int i = 0; i < rows; i++) {
		// col-by-col
		for (int j = 0; j < cols; j++) {
			transpose[j][i] = matrix[i][j];
		}
	}

	return transpose;
}

int main () {
	vector<vector<int>> matrix = {
		{1, 2, 3},
		{4, 5, 6}
	};

	vector<vector<int>> transpose = makeTranspose (matrix);

	cout << "Transpose:\n";
	for (const auto& rows : transpose) {
	    for (const auto& val : rows) {
	        cout << val << " ";
	    }
	    cout << endl;
	}

	return 0;
}

/*

In C++, functions cannot return arrays directly.
So, we cannot write like 'int makeTranspose[][]' which is invalid in C++

Transpose process: when use another matrix:
	row-by-row traverse in original
	col-by-col fill in new matrix
				OR
	col-by-col traverse in original
	row-by-row fill in new matrix

*/