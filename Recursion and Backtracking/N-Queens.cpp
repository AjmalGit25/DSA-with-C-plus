#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
	// horizontal
	for (int j = 0; j < n; j++) {
		if (board[row][j] == 'Q')
			return false;
	}

	// vertical
	for (int i = 0; i < n; i++) {
		if (board[i][col] == 'Q')
			return false;
	}

	// left diagonal
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 'Q')
			return false;
	}

	// right diagonal
	for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
		if (board[i][j] == 'Q')
			return false;
	}

	return true;
}

void nQueens (vector<string>& board, vector<vector<string>>& result, int row, int n) {
	if (row == n) {
		result.push_back({board});
		return;
	}

	for (int j = 0; j < n; j++) {
		if (isSafe(board, row, j, n)) {
			board[row][j] = 'Q';
			nQueens (board, result, row + 1, n);
			board[row][j] = '.';
		}
	}
}

vector<vector<string>> solveNQueens (int n) {
	vector<string> board(n, string(n, '.'));
	vector<vector<string>> result;

	nQueens (board, result, 0, n);

	return result;
}


int main () {
	vector<vector<string>> result = solveNQueens(4);

	for (const auto& rows : result) {
		for (const auto& c : rows) {
			cout << c << " ";
		}
		cout << "\n";
	}
	
	return 0;
}