#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> majorityElement (vector<int>& nums) {
	int n = nums.size();

	int ele1 = -1, ele2 = -1;
	int cnt1 = 0, cnt2 = 0;

	for (const auto& val : nums) {

		// Increment count for candidate 1
		if (ele1 == val)
			cnt1++;

		// Increment count for candidate 2
		else if (ele2 == val)
			cnt2++;

		// New candidate 1 if count is zero
		else if (cnt1 == 0) {
			ele1 = val;
			cnt1++;
		}

		// New candidate 2 if count is zero
		else if (cnt2 == 0) {
			ele2 = val;
			cnt2++;
		}

		// Decrease counts if neither candidate
		else {
			cnt1--;
			cnt2--;
		}
	}

	vector<int> result;
	cnt1 = 0;
	cnt2 = 0;

	// Traverse the array again to update their count
	for (int val : nums) {
		if (ele1 == val) cnt1++;
		if (ele2 == val) cnt2++;
	}

	// Add to result if they are majority elements
	if (cnt1 > n / 3) result.push_back(ele1);
	if (cnt2 > n / 3 && ele1 != ele2) result.push_back (ele2);
	
	
	if (result.size() == 2 && result[0] > result[1])
        swap (result[0], result[1]);

	return result;
}



int main () {

	vector<int> nums = {2, 2, 3, 1, 3, 2, 1, 1};

	vector<int> result = majorityElement (nums);

	cout << "Majority element = ";

	for (const auto& x : result) cout << x << " ";

	return 0;
}

/*

Majority Element:
    A majority element is an element that appears more than ?n/2? times in an array of n size. (By the standard definition)


What about n/3, n/4, etc.?
    These are different problem variants, not the standard majority element definition.
    Example: Majority Element II (LeetCode 229) | Find all elements appearing more than n/3 times.

Generalized Majority Element:
    Find elements appearing more than n/k times. At most k - 1 such elements can exist.


*/