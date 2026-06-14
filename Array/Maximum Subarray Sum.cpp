#include <iostream>
#include <vector>
using namespace std;

// [Naive Approach] Brute-Force approach - O(n^2) Time and O(1) Space
int maxSubarraySum (vector<int> &arr) {
    int res = arr[0];
  
    // Outer loop for starting point of subarray
  	for (int i = 0; i < arr.size(); i++) {
    	int currSum = 0;
      
        // Inner loop for ending point of subarray
        for (int j = i; j < arr.size(); j++) {
        	currSum = currSum + arr[j];
          
            // Update res if currSum is greater than res
            res = max (res, currSum);
        }
    }
    
    return res;
}

// [Expected Approach] Kadane's Algorithm - O(n) Time and O(1) Space
int maxSubarraySum (vector<int>& arr) {

    int res = arr[0];      // Best answer so far
    int maxEnd = arr[0];   // Best subarray ending here

    for (int i = 1; i < arr.size(); i++) {

        // Extend previous subarray OR start new one
        maxEnd = max (arr[i], maxEnd + arr[i]);

        // Update global maximum
        res = max (res, maxEnd);
    }

    return res;
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