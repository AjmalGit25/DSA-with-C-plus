#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// [Approach] Using Sorting - O(n logn) Time and O(1) Space
int getMinDiff (vector<int> &arr, int k) {
	int n = arr.size();

	sort (arr.begin(), arr.end());

	int res = arr[n - 1] - arr[0];

	for (int i = 1; i < n; i++) {

		if (arr[i] - k < 0)
			continue;

		int minH = min (arr[0] + k, arr[i] - k);
		int maxH = max (arr[i - 1] + k, arr[n - 1] - k);

		res = min (res, maxH - minH);
	}

	return res;
}

int main () {
	vector<int> nums = {1, 5, 8, 10};

	int result = getMinDiff (nums, 2);

	cout << "Minimized difference = " << result;

	return 0;
}