#include <iostream>
#include <vector>
using namespace std;

void helper (vector<vector<int>>& mat, int r, int c, string path, vector<string>& ans, vector<vector<bool>>& visited) {
	int n = mat.size();

	if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || visited[r][c]) {
		return;
	}

	if (r == n - 1 && c == n - 1) {
		ans.push_back(path);
		return;
	}

	visited[r][c] = true;

	helper (mat, r + 1, c, path + "D", ans, visited);      // down
	helper (mat, r - 1, c, path + "U", ans, visited);      // up
	helper (mat, r, c - 1, path + "L", ans, visited);      // left
	helper (mat, r, c + 1, path + "R", ans, visited);      // right

	visited[r][c] = false;
}

vector<string> pathFind (vector<vector<int>>& mat) {
	int n = mat.size();

	vector<string> ans;
	string path = "";

	vector<vector<bool>> visited(n, vector<bool>(n, false));

	helper (mat, 0, 0, path, ans, visited);

	return ans;
}

int main () {
	vector<vector<int>> mat = {
		{1, 0, 0, 0},
		{1, 1, 0, 1},
		{1, 1, 0, 0},
		{0, 1, 1, 1},
	};

	vector<string> ans = pathFind(mat);

	for (string path : ans) {
		for (int i = 0; i < path.size(); i++) {
			
			if (i > 0) cout << "->";
			cout << path[i];
		}
		cout << endl;
	}

	return 0;
}
