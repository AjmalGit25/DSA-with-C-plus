#include <iostream>
using namespace std;

void makeTranspose (int arr[][3], int transpose[][2], int row, int col) {
    // row-by-row
    for (int i = 0; i < row; i++) {
        // col-by-col
        for (int j = 0; j < col; j++) {
            transpose[j][i] = arr[i][j];
        }
    }
}


int main () {
    int row = 2, col = 3;
    
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    int transpose[3][2]; // Dimensions swapped

    makeTranspose (arr, transpose, row, col);

    cout << "Transpose:\n";
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << transpose[i][j] << " ";
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