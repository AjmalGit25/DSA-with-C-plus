#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Simulation by Visited Matrix - O(m*n) Time and O(m*n) Space
vector<int> spirallyTraverse (vector<vector<int>>& mat) {
	int rows = mat.size();
	int cols = mat[0].size();

	vector<int> res;
	vector<vector<bool>> visited (rows, vector<bool>(cols, false));

	// Change in row index for each direction
	vector<int> dr = { 0, 1, 0, -1 };

	// Change in column index for each direction
	vector<int> dc = { 1, 0, -1, 0 };

	// Initial position in the matrix
	int r = 0, c = 0;

	// Initial direction index for dr and dc array
	int idx = 0;

	for (int i = 0; i < rows * cols; ++i) {
		res.push_back (mat[r][c]);
		visited[r][c] = true;

		// Current direction
		int newR = r + dr[idx];
		int newC = c + dc[idx];

		// Check if the next cell is within bounds and not
		// visited
		if (0 <= newR && newR < rows &&
			0 <= newC && newC < cols &&
			!visited[newR][newC]) {

			// Move to the next row
			r = newR;

			// Move to the next column
			c = newC;
		}
		else {

			// Change direction (turn clockwise)
			idx = (idx + 1) % 4;

			// Move to the next row according to new direction
			r += dr[idx];

			// Move to the next column according to new direction
			c += dc[idx];
		}
	}

	return res;
}

// Using Boundary Traversal - O(m*n) Time and O(1) Space
vector<int> spirallyTraverse (vector<vector<int>>& mat) {
	int rows = mat.size();
	int cols = mat[0].size();


	vector<int> res;

	// Initialize boundaries
	int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

	// Iterate until all elements are stored
	while (top <= bottom && left <= right) {

		// store top row from left to right
		for (int i = left; i <= right; ++i) {
			res.push_back (mat[top][i]);
		}
		top++;

		// store right column from top to bottom
		for (int i = top; i <= bottom; ++i) {
			res.push_back (mat[i][right]);
		}
		right--;

		// store bottom row from right to left (if exists)
		if (top <= bottom) {
			for (int i = right; i >= left; --i) {
				res.push_back (mat[bottom][i]);
			}
			bottom--;
		}

		// store left column from bottom to top (if exists)
		if (left <= right) {
			for (int i = bottom; i >= top; --i) {
				res.push_back (mat[i][left]);
			}
			left++;
		}
	}
	return res;
}


int main () {
	vector<vector<int>> mat = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},

	};

    vector<int> res = spirallyTraverse (mat);
    
    for (int x : res) 
        cout << x << " ";

	return 0;
}

/*

1. Simulation by Visited Matrix - O(m*n) Time and O(m*n) Space

    Initialize a 2D array vis[][] to keep track of visited cells.
    Use direction arrays dr and dc to represent right, down, left, and up movements.
    Start from the top-left cell and follow the direction arrays to visit each cell.
    Change direction when encountering a boundary or a visited cell.
    Continue until all cells are visited.

---------------------------------------------------------------

2. Using Boundary Traversal - O(m*n) Time and O(1) Space

	Define the boundaries of the matrix with variables top, bottom, left, and right.
	Print the top row from left to right and increment top.
	Print the right column from top to bottom and decrement right.
	Check if boundaries have crossed; if not, print the bottom row from right to left and decrement bottom.
	Print the left column from bottom to top and increment left.
	Repeat until all boundaries are crossed.

---------------------------------------------------------------

move right(0, +1), move down(+1, 0),
move left(0, -1), move  up(-1, 0)



*/