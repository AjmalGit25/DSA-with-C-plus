#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findCoverage (vector<vector<int>>& mat) {

	int rows = mat.size();
	int cols = mat[0].size();

	int totalCoverage = 0;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (mat[i][j] == 0) {
				int coverage = 0;

				// Check upwards
				bool upHasOne = false;
				for (int r = i - 1; r >= 0; --r) {
					if (mat[r][j] == 1) {
						upHasOne = true;
						break;
					}
				}
				if (upHasOne)
					coverage++;

				// Check downwards
				bool downHasOne = false;
				for (int r = i + 1; r < rows; ++r) { 
					if (mat[r][j] == 1) {
						downHasOne = true;
						break;
					} 
				} 
				if (downHasOne)
					coverage++;

				// Check left
				bool leftHasOne = false;
				for (int c = j - 1; c >= 0; --c) {
					if (mat[i][c] == 1) {
						leftHasOne = true;
						break;
					}
				}
				if (leftHasOne)
					coverage++;

				// Check right
				bool rightHasOne = false;
				for (int c = j + 1; c < cols; ++c) {
					if (mat[i][c] == 1) {
						rightHasOne = true;
						break;
					}
				}
				if (rightHasOne)
					coverage++;

				totalCoverage += coverage;
			}
		}
	}

	return totalCoverage;
}


int main () {
	vector<vector<int>> mat = {
                                    {1, 1, 1, 0},
                                    {1, 0, 0, 1}
	};

	int res = findCoverage (mat);

	cout << res << endl;

	return 0;
}