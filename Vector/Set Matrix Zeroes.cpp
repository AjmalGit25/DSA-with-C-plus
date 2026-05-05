/* Set Matrix Zeroes */

void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    vector<bool> zero_rows(row, false);
    vector<bool> zero_cols(col, false);

    // First pass: record the rows and columns that contain zeros
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                zero_rows[i] = true;
                zero_cols[j] = true;
            }
        }
    }

    // Second pass: set zeros for recorded rows
    for (int i = 0; i < row; i++) {
        if (zero_rows[i]) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Third pass: set zeros for recorded columns
    for (int j = 0; j < col; j++) {
        if (zero_cols[j]) {
            for (int i = 0; i < row; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}