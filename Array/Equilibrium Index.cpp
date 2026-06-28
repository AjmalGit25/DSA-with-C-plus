#include <iostream>
#include <vector>
using namespace std;

//  Best Approach - Prefix Sum and Suffix Sum - O(n) Time and O(1) Space
int equilibriumIndex (vector<int>& arr) {
    int n = arr.size();
    
	int totalSum = 0;

	for (int num : arr)
		totalSum += num;

	int leftSum = 0;

	for (int i = 0; i < n; i++) {
		int rightSum = totalSum - leftSum - arr[i];

		if (leftSum == rightSum)
			return i;

		leftSum += arr[i];
	}

	return -1; 			// No equilibrium index
}

int main () {
	vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};

    cout << equilibriumIndex (arr);
}



/*

Equilibrium Index:
	Sum of elements on the left of i = Sum of elements on the right of i

	Note: The element at index i itself is not included in either sum.

Example

	Array: [1, 3, 5, 2, 2]
	For index 2 (value = 5):

	Left sum  = 1 + 3 = 4
	Right sum = 2 + 2 = 4

	Since Left sum = Right sum, 2 is an equilibrium index.

=======================================================================

Principle:
	1. Find totalSum
	2. Keep track of leftSum
	3. Calculate:	rightSum = totalSum - leftSum - arr[i]
	5. If leftSum == rightSum, return i

*/