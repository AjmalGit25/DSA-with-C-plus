#include <iostream>
#include <vector>
using namespace std;

/* O(n) Time, O(n) Space -------------- */
vector<int> leftRotate (vector<int>& nums, int d) {
    int n = nums.size();
    
    // Handle case when d > n
    d %= n;
    
    vector<int> temp(n);
    
    // Copy first d elements to the back
    for (int i = 0; i < d; i++) 
        temp[n - d + i] = nums[i];
    
    // Copy last n - d elements to the front
    for (int i = 0; i < n - d; i++) 
        temp[i] = nums[d + i];
    
    return temp;
}

vector<int> rightRotate (vector<int>& nums, int d) {
    int n = nums.size();
    
    // Handle case when d > n
    d %= n;
    
    vector<int> temp(n);
    
    // Copy last d elements from n - d
    for (int i = 0; i < d; i++) 
        temp[i] = nums[n - d + i];
    
    // Copy first n - d elements to the back of temp
    for (int i = 0; i < n - d; i++) 
        temp[d + i] = nums[i];
    
    return temp;
}


/* O(n) Time, O(1) Space : Reversal Algorithm -------------- */
void leftRotate (vector<int>& arr, int d) {
	int n = arr.size();

	d %= n;										// Handle case when d > n

	reverse (arr.begin(), arr.begin() + d);

	reverse (arr.begin() + d, arr.end());

	reverse (arr.begin(), arr.end());
}


void rightRotate (vector<int>& arr, int d) {
	int n = arr.size();

	d %= n;										// Handle case when d > n

	reverse (arr.begin() + n - d, arr.end());		// reverse 
 
	reverse (arr.begin(), arr.begin() + n - d);

	reverse (arr.begin(), arr.end());
}

int main () {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int d = 2;
    
    rotateArr (nums, d);
    
    for (const auto& x : nums) {
        cout << x << " ";
    }

    return 0;
}

/*

Rotate the array elements to the left (or right) by k positions:

Left Rotate (Counter-clockwise):

	1. Copy the first d elements to the back
	2. Copy the last (n - d) elements to the front

Example1: 
	Input: {1, 2, 3, 4, 5}, k = 2
	Output: {3, 4, 5, 1, 2}

--------------------------------------------------------------------------------
Right Rotate (Clockwise):

	1. Copy the last d elements to the front
	2. Copy the first (n - d) elements elements to the back

Example1: 
	Input: {1, 2, 3, 4, 5, 6}, k = 2
	Output: {4, 5, 1, 2, 3}

*/