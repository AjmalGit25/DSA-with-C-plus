#include<iostream>
#include<vector>
using namespace std;

// [Naive Approach] Using Nested Loops - O(n^2) Time and O(1) Space

int majorityElement (vector<int> nums) {
    int n = nums.size();
    
    for (int val : nums) {
        int freq = 0;
        
        for (int x : nums) {
            
            if (val == x) {
                freq++;
            }
        }

        if (freq > n / 2) {			// freq more than half (n/2)
            return val;
        }
    }
    return -1;
}

int majorityElement (vector<int>& nums) {		// same naive approach, using nested for loops
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        int freq = 0;
        
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j])
                freq++;
        }
        
        if (freq > n / 2) 
            return nums[i];
    }
    
    return -1;
}


// [Optimal Approach] using Sorting - Time Complexity: O(nlogn)

int majorityElement (vector<int>& nums) {
    int n = nums.size();
    
    sort (nums.begin(), nums.end());
    
    int freq = 0;
    int cand = nums[0];
    
    for (int i = 0; i < n; i++) {
        
        if (cand = nums[i]) 
            freq++;
        
        else {
            cand = nums[i];
            freq = 1;
        }
        
        if (freq > n / 2) 
            return nums[i];
    }
    
    return -1;
}


// [Best Approach] Boyer-Moore’s Voting Algorithm - O(n) Time and O(1) Space
int majorityElement (vector<int>& nums) {
	int n = nums.size ();
	
	int ans = nums[0];
	int freq = 1;
	
	// 1. Find a candidate
	for (int i = 1; i < n; i++) {
	    
	    // 2. Increase count if same OR Decrease count if different
		if (ans == nums[i])
			freq++;
		else 
			freq--;
		
		// 3. Change candidate, when count becomes 0
		if (freq == 0) {
			ans = nums[i];
			freq = 1;
		}
	}
	
	freq = 0;
	
	// 4. Find the actual count of survived candidate
	for (int i = 0; i < n; i++) {
		if (ans == nums[i])
			freq++;
	} 
	
	if (freq > n / 2)
		return ans;
	else 
		return -1;
}

// [Expected Approach] Hashing - O(n) Time and O(n) Space
int majorityElement (vector<int>& nums) {
    int n = nums.size();
    
    unordered_map<int, int> freqMap;

    for (const auto& x : nums) {
        
        freqMap[x]++;
        
        if (freqMap[x] > n / 2)
            return x; 
    }
    
    return -1;
}


int main () {
    
    vector<int> nums = {3, 2, 3, 1, 1, 3, 3, 3};
    
    int result = majorityElement (nums);
    
    cout << "Majority element = " << result << endl;
    
    return 0;
}

/* 

Majority Element:
    A majority element is an element that appears more than ⌊n/2⌋ times in an array of n size. (By the standard definition)


What about n/3, n/4, etc.?
    These are different problem variants, not the standard majority element definition.
    Example: Majority Element II (LeetCode 229) | Find all elements appearing more than n/3 times.
    
Generalized Majority Element:
    Find elements appearing more than n/k times. At most k - 1 such elements can exist.


*/	