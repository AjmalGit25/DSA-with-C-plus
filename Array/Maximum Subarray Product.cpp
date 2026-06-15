#include <iostream>
#include <vector>
using namespace std;

int maxSubarrayProd (vector<int> &arr) {
	int n = arr.size();

	int maxProd = arr[0];                // Global maximum product found so far

	int maxEnd = arr[0];
	int minEnd = arr[0];

	for (int i = 1; i < n; i++) {

		if (arr[i] < 0)
			swap (maxEnd, minEnd);

		maxEnd = max (arr[i], arr[i] * maxEnd);
		minEnd = min (arr[i], arr[i] * minEnd);

		maxProd = max (maxProd, maxEnd);
	}

	return maxProd;
}

int main () {

	vector<int> arr = {-2, 6, -3, -10, 0, 2};

	int res = maxSubarrayProd (arr);

	cout << res;

	return 0;
}

/*

Principle for Maximum Product Subarray
i) Track both maximum and minimum products ending at current index.
ii) Negative numbers can swap maximum and minimum.
iii) Update global maximum product.


negative × negative = positive

A very small (negative) product can suddenly become the largest positive product after multiplying by another negative number.

Therefore we must track both:

	maxEnd = maximum product ending here
	minEnd = minimum product ending here


*/