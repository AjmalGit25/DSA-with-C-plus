#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool findSubarrays (vector<int>& nums) {
	unordered_set<int> seen;

	for (int i = 0; i < nums.size() - 1; i++) {
		int sum = nums[i] + nums[i + 1];

		if (seen.count(sum))
			return true;

		seen.insert(sum);
	}

	return false;
}

int main () {
	vector<int> arr = {4,2,4};

	cout << findSubarrays (arr);
}

/*

Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.

----------------------------------------------------------------------------------

Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.

----------------------------------------------------------------------------------

Input: nums = [0,0,0]
Output: true
Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 

*/