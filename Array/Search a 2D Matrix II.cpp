#include <iostream>
#include <vector>

using namespace std;

/* [Naive Approach] Comparing with all elements - O(n*m) Time and O(1) Space */
bool searchMatrix (vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
  
    // Iterate over all the elements to find x
	for (int i = 0; i < rows; i++) {
    	for (int j = 0; j < cols; j++) {
    	    
        	if (matrix[i][j] == target)
                return true;
        }
    }
  
    return false;
}

/* Using Binary Search - O(n*logm) Time and O(1) Space */
// Standard binary search algorithm
bool binarySearch (vector<int>& row, int target) {
    int n = row.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (row[mid] == target) 
            return true;            // Element found
        else if (target > row[mid]) 
            low = mid + 1;          // Search in the right half
        else 
            high = mid - 1;         // Search in the left half
    }
    
    return false;
}

bool searchMatrix (vector<vector<int>>& matrix, int target) {
    int n = matrix.size();

    // Iterate over each row and perform Binary search
    for (int i = 0; i < n; i++) {
        if (binarySearch (matrix[i], target)) 
            return true;  
    }
    
    return false;
}

int main () {
    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    
    if (searchMatrix (mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}