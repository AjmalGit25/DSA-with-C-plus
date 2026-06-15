#include <iostream>
#include <vector>
using namespace std;

// [Naive Approach] Brute-Force approach - O(n^2) Time and O(1) Space
int maxSubarraySum (vector<int> &arr) {
    int n = arr.size();
    
    int maxSum = arr[0];
    
    for (int i = 0; i < n; i++) {					// Starting point of subarray
        
        int currSum = 0;
        
        for (int j = i; j < n; j++) {				// Ending point of subarray
            currSum += arr[j];
            
            // Update global maximum
            maxSum = max (maxSum, currSum);
        }
    }
    
    return maxSum;
}

// [Expected Approach] Kadane's Algorithm - O(n) Time and O(1) Space
int maxSubarraySum (vector<int> &arr) {
    int n = arr.size();
    
    int maxSum = arr[0];                // Global maximum sum found so far
    
    int maxEnd = arr[0];
    
    for (int i = 1; i < n; i++) {
        
        maxEnd = max (arr[i], arr[i] + maxEnd);     // Extend previous subarray OR start new one
        
        // Update global maximum
        maxSum = max (maxSum, maxEnd);
    }
    
    return maxSum;
}

int main () {
	
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    
    int res = maxSubarraySum (arr);
    
    cout << res;
    
    return 0;
}

/*


Kadane's Algorithm:
	-> Idea: Should I start a new subarray from here, or continue the previous subarray?

	-> maxEnd = max (arr[i], maxEnd + arr[i]);
		arr[i] -> Start a new subarray from the current element.
		maxEnd + arr[i] -> Extend the previous subarray.

------------------------------------------------------------------
Principle:
	i) Extend previous subarray OR start a new subarray from the current index
	ii) Update global maximum sum found so far.


*/