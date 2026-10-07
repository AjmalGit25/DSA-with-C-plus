#include <iostream>
using namespace std;

bool helper (vector<vector<char>>& mat, string& word, int r, int c, int idx, vector<vector<bool>>& vis) {

    int rows = mat.size();
    int cols = mat[0].size();

    // Entire word matched
    if (idx == word.size())
        return true;

    // Invalid cell
    if (r < 0 || c < 0 || r >= rows || c >= cols || mat[r][c] != word[idx] || vis[r][c])
        return false;

    // Choose
    vis[r][c] = true;

    // Explore
    bool found =
        helper (mat, word, r - 1, c, idx + 1, vis) ||
        helper (mat, word, r + 1, c, idx + 1, vis) ||
        helper (mat, word, r, c - 1, idx + 1, vis) ||
        helper (mat, word, r, c + 1, idx + 1, vis);

    // Undo
    vis[r][c] = false;

    return found;
}

bool wordSearch (vector<vector<char>>& mat, string word) {

    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<bool>> vis (rows, vector<bool> (cols, false));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            if (mat[r][c] == word[0]) {

                if (helper (mat, word, r, c, 0, vis))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    
    
    return 0;
}