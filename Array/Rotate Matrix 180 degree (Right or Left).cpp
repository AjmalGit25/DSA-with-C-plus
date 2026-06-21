#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Using Auxiliary Matrix - Time: O(n²) Space: O(n²) (extra matrix)
void rotateMatrix (vector<vector<int>>& mat) { 
    int n = mat.size();
  
    // 1. Create an auxiliary matrix
    vector<vector<int>> res(n, vector<int>(n));
  
    // 2. Move mat[i][j] to mat[n-i-1][n-j-1]
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            res[i][j] = mat[n - i - 1][n - j - 1];
        } 
    } 
    
    mat = res;
} 


void rotateMatrix (vector<vector<int>>& mat) {
    reverse (mat.begin(), mat.end());           // 1. Reverse all rows (top <-> bottom)

    for (auto& row : mat) {
        reverse (row.begin(), row.end());       // 2. Reverse each row (left <-> right)
    }
}

int main () {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    rotateMatrix (mat);
    
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*

Rotating 180° clockwise or anticlockwise gives the same result.

*/