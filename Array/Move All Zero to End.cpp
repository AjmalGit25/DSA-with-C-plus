#include <iostream>
#include <vector>
using namespace std;

// Naive Approach - using Temporary Array - O(n) Time and O(n) Space
vector<int> moveZeroes (vector<int>& nums) {
    int n = nums.size();
    
    vector<int> temp(n);        // n elements, all initialized to 0
    
    // to keep track of the index in temp[]
    int j = 0;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            temp[j++] = nums[i];
        }
    }
    
    return temp;
}

// Better Approach - Two Traversals-O(n) Time and O(1) space
void moveZeroes (vector<int>& nums) {
    int n = nums.size();
   
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[count++] = nums[i];
        }
    }
    
    // fill remaining elements with 0
    while (count < n) {
        nums[count++] = 0;
    }
}

// Expected Approach - One Traversal - O(n) Time 
void moveZeroes (vector<int>& nums) {
    int n = nums.size();
   
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            swap (nums[count++], nums[i]);
        }
    }
}

int main () {
    vector<int> nums = {1, 2, 0, 4, 3, 0, 5, 0};
    
    vector<int> result = moveZeroes (nums);
    
    cout << "Result: \n";
    
    for (const auto& val : result) {
        cout << val << " ";
    }
    
    return 0;
}