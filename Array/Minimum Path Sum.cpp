#include <iostream>
#include <vector>
using namespace std;

int minPathSum (vector<vector<int>>& grid) {
	int rows = grid.size();
	int cols = grid[0].size();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == 0 && j == 0)
				continue;

			else if (i == 0)
				grid[i][j] += grid[i][j - 1];

			else if (j == 0)
				grid[i][j] += grid[i - 1][j];

			else
				grid[i][j] += min (grid[i - 1][j], grid[i][j - 1]);
		}
	}

	return grid[rows - 1][cols - 1];
}

int main () {
	vector<vector<int>> grid = {
	    {1, 0, 2},
	    {5, 3, 1},
	    {0, 2, 7},
	    {1, 3, 2},
	};
	
	int result = minPathSum (grid);

	cout << "Minimum path sum = " << result << endl;

	return 0;
}