#include <iostream>
#include <vector>
using namespace std;

/* Better Brute Force (O(n²)) Solution */
bool checkSubarraySum (vector<int>& nums, int k) {
	int n = nums.size();

	for (int i = 0; i < n; i++) { 

		int currSum = 0;

		for (int j = i; j < n; j++) { 
			currSum += nums[j];

			// Checking multiple: x = n * k. 0 is always a multiple of k.
			if (j - i + 1 >= 2 && currSum % k == 0)
				return true;
		}
	}

	return false;
}


/* Optimal O(n) Solution */
bool checkSubarraySum (vector<int>& nums, int k) {

    unordered_map<int, int> firstIndex;
    firstIndex[0] = -1;

    int prefixSum = 0;

    for (int i = 0; i < nums.size(); i++) {

        prefixSum += nums[i];

        int rem = prefixSum % k;

        if (firstIndex.count(rem)) {			// count checks if the key exists

            if (i - firstIndex[rem] >= 2)
                return true;
        }
        else {
            firstIndex[rem] = i;
        }
    }

    return false;
}


int main () {

	vector<int> nums = {23, 2, 4, 6, 7};

	bool res = checkSubarraySum (nums, 6);

	cout << res;

	return 0;
}


/*

Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
A good subarray is a subarray where:

	its length is at least two, and
	the sum of the elements of the subarray is a multiple of k.

------------------------------------------------------------------------------
Optimal O(n) Solution:

unordered_map<int, int> firstIndex:
	remainder  as a key			key: (remainder)
	index as a value			value: (index)
	
	{
		0 : -1,
		5 : 0,
		1 : 1
	}


Why: firstIndex[0] = -1; ?

Suppose:
	nums = {6, 0}
	k = 6

At index 1:
	prefixSum = 6
	rem = 0

We want to recognize:

	subarray [0...1]

as valid.

*/