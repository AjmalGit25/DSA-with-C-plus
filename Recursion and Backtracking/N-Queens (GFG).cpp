#include <iostream>
#include <vector>
using namespace std;

bool isSafe (vector<int>& board, int row, int col, int n) {
	for (int prevRow = 0; prevRow < row; prevRow++) {
		int prevCol = board[prevRow];

		if (prevCol == col)
			return false;

		if (abs(prevRow - row) == abs(prevCol - col))
			return false;
	}

	return true;
}

void nQueens (vector<int>& board, vector<vector<int>>& res, int row, int n) {
	if (row == n) {
		vector<int> solution;

		for (int col : board)
			solution.push_back(col + 1);

		res.push_back(solution);
		return;
	}

	for (int col = 0; col < n; col++) {
		if (isSafe (board, row, col, n)) {
			board.push_back (col);
			nQueens (board, res, row + 1, n);
			board.pop_back();
		}
	}
}

vector<vector<int>> nQueen(int n) {
	vector<int> board;
	vector<vector<int>> res;

	nQueens (board, res, 0, n);
	return res;
}

int main () {

	return 0;
}