#include <iostream>
#include <vector>
using namespace std;

// [Naive Approach] Using Two Auxiliary Arrays - O(n*m) Time and O(n+m) Space 	| 		(Best approach)
void setMatrixZeroes (vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    vector<bool> zero_rows(row, false);
    vector<bool> zero_cols(col, false);

    // First pass: record the rows and columns that contain zeros
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                zero_rows[i] = true;
                zero_cols[j] = true;
            }
        }
    }

    // Second pass: set zeros for recorded rows
    for (int i = 0; i < row; i++) {
        if (zero_rows[i]) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Third pass: set zeros for recorded columns
    for (int j = 0; j < col; j++) {
        if (zero_cols[j]) {
            for (int i = 0; i < row; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

// Expected Approach] Using First Row and Column - O(n*m) Time and O(1) Space
void setMatrixZeroes (vector<vector<int>> &mat) {
    int rows = mat.size(); 
	int cols = mat[0].size();

    int c = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 0) {

                // mark i-th row
                mat[i][0] = 0;

                // mark j-th column
                if (j == 0)
                    c0 = 0;
                else
                    mat[0][j] = 0;
            }
        }
    }

    // Traverse and mark the matrix from 
    // (1, 1) to (n - 1, m - 1)
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {

            // Check for col & row
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // Mark the first row
    if (mat[0][0] == 0) {
        for (int j = 0; j < cols; j++)
            mat[0][j] = 0;
    }
  
    // Mark the first column
    if (c0 == 0) {
        for (int i = 0; i < rows; i++)
            mat[i][0] = 0;
    }
}


int main () {
    vector<vector<int>> mat = { { 0, 1, 2, 0 },
                                { 3, 4, 0, 2 },
                                { 1, 3, 1, 5 } };

    setMatrixZeroes (mat);
    
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/* 

Set Matrix Zeroes :





*/