#include <iostream>
#include <vector>
using namespace std;

// [Naive Approach] Using Nested Loop - O(n^2) Time and O(1) Space
int longestSubarray (vector<int>& arr, int k) {
    int n = arr.size();
    
    int longest = 0;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        
        for (int j = i; j< n; j++) {
            sum += arr[j];
            
            if (sum == k)
                longest = max (longest, j + 1);
        }
    }
    
    return longest;
}

// [Expected Approach] Using Hash Map and Prefix Sum - O(n) Time, O(n) Space
int longestSubarray (vector<int>& arr, int k) {
	int n = arr.size();

	unordered_map<int, int> mp;
	int prefSum = 0;
	int longest = 0;

	for (int i = 0; i < n; i++) {
		prefSum += arr[i];

		// Case 1: Subarray from index 0 to i
		if (prefSum == k)
			longest = max(longest, i + 1);

		// Case 2: Subarray ending at i with sum k
		if (mp.find(prefSum - k) != mp.end()) {
			longest = max(longest, i - mp[prefSum - k]);
		}

		// Store FIRST occurrence only
		if (mp.find(prefSum) == mp.end()) {
			mp[prefSum] = i;
		}
	}

	return longest;
}

int main () {
	vector<int> arr = {-5, 8, -14, 2, 4, 12};
	int k = -5;

    cout << longestSubarray (arr, k);
}