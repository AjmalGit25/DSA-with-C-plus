
bool isValid (vector<vector<int>>& grid, int r, int c, int expVal) {
	int n = grid.size();
	
	if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
	    return false;
	}
	
	if (expVal == n * n - 1) {
	    return true;
	}

	// 8 possible moves
	bool ans1 = isValid(grid, r - 2, c + 1, expVal + 1);
	bool ans2 = isValid(grid, r - 1, c + 2, expVal + 1);
	bool ans3 = isValid(grid, r + 1, c + 2, expVal + 1);
	bool ans4 = isValid(grid, r + 2, c + 1, expVal + 1);
	bool ans5 = isValid(grid, r + 2, c - 1, expVal + 1);
	bool ans6 = isValid(grid, r + 1, c - 2, expVal + 1);
	bool ans7 = isValid(grid, r - 1, c - 2, expVal + 1);
	bool ans8 = isValid(grid, r - 2, c - 1, expVal + 1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool checkValidGrid (vector<vector<int>>& grid) {
	return isValid (grid, 0, 0, 0);
}

/*

Time Complexity (TC): O(n^2)
This function tries 8 possible knight moves at every recursive call, and each call increases expVal by 1.

Space Complexity (SC): O(n^2)
Recursion follows the sequence of expected values. Each successful recursive call moves to the next value.
The maximum recursion depth is (n^2), because the board contains (n^2) cells.


*/