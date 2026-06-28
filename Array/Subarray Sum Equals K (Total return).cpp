#include <iostream>
#include <vector>
using namespace std;

int subarraySum (vector<int>& nums, int k) {
	int n = nums.size();

	int count = 0;

	for (int i = 0; i < n; i++) {
		int totalSum = 0;
		
		for (int j = i; j < n; j++) {
			totalSum += nums[j];

			if (totalSum == k)
				count++;
		}
	}

	return count;
}

int main () {
	vector<int> arr = {-5, 8, -14, 2, 4, 12};
	int k = -5;

	cout << subarraySum (arr, k);
}