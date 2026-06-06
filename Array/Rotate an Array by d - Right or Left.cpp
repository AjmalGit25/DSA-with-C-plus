#include <iostream>
#include <vector>
using namespace std;

// [Naive Approach] Rotate One by One - O(n * d) Time and O(1) Space
// Left rotate
void rotateArr (vector<int>& nums, int d) {
    int n = nums.size();
    
    // Repeat the rotation d times
    for (int i = 0; i < d; i++) {
        
        int first = nums[0];                // to copy first element to the last index
        
        for (int j = 0; j < n - 1; j++) {	// shift elements to the left
            nums[j] = nums[j + 1];
        }
        
        nums[n - 1] = first;                // copy ...
    }
}

// Right rotate
void rotateArr (vector<int>& nums, int d) {
    int n = nums.size();
    
    // Repeat the rotation d times
    for (int i = 0; i < d; i++) {
        
        int last = nums[n - 1];                // last (right rotation)
        
        for (int j = n - 1; j >= 1; j--) {   // shift elements to the right
            nums[j] = nums[j - 1];
        }
        
        nums[0] = last;                // copy ...
    }
}

// [Better Approach] Using Temporary Array - O(n) Time and O(n) Space
void rotateArr (vector<int>& nums, int d) {
    int n = nums.size();
    
    // Handle case when d > n
    d %= n;
    
    vector<int> temp(n);
    
    // Copy last n - d elements from d
    for (int i = 0; i < n - d; i++) {
        temp[i] = nums[d + i];
    }
    
    // Copy the first d elements to the back of temp
    for (int i = 0; i < d; i++) {
        temp[n - d + i] = nums[i];
    }
    
    // Copy elements from temp to nums
    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

// Right rotate
void rotateArr (vector<int>& nums, int d) {
    int n = nums.size();
    
    // when d > n
    d %= n;
    
    vector<int> temp(n);
    
    // copy last d elements
    for (int i = 0; i < d; i++) 
        temp[i] = nums[n - d + i];
    
    // copy first n - d elements
    for (int i = 0; i < n - d; i++)
        temp[d + i] = nums[i];
    
    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
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