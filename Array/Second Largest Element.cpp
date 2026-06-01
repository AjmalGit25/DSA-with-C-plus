#include <iostream>
#include <climits>
using namespace std;

// Naive Approach using Sorting
int secondLargest (vector<int>& nums) {
    int n = nums.size();
    
    // sort Ascending
    sort (nums.begin(), nums.end());						// O(n*log(n))
    
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] != nums[n-1]) {
            return nums[i];
        }
    }
    
    return -1;
}

// Two Pass Search
int secondLargest (vector<int>& nums) {
    int n = nums.size();
    
    int largest = -1;
    int secondLargest = -1;
    
    // 1st Pass	-> find largest element
    for (int i = 0; i < n; i++) {
        largest = max (largest, nums[i]);
    }
    
    // 2nd Pass -> find secondLargest element
    for (int i = 0; i < n; i++) {
        if (nums[i] > secondLargest && nums[i] != largest) 
            secondLargest = nums[i];
    }
    
    return secondLargest;
}

// Expected Approach -> One Pass Search
int secondLargest (vector<int>& nums) {
    int n = nums.size();
    
    int largest = -1;
    int secondLargest = -1;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] > largest) {
            secondLargest = largest;
            largest = nums[i];
        }
        else if (nums[i] < largest && nums[i] > secondLargest) {
            secondLargest = nums[i];
        }
    }
    
    return secondLargest;
}

int main () {
    vector<int> nums = {12, 35, 1, 10, 34, 1};
    
    int result = secondLargest (nums);
    
    cout << "Second Largest element = " << result;
    
    return 0;
}