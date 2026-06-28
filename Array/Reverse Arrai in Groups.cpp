#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void reverseInGroups (vector<int>& arr, int k) {
	int n = arr.size();

	for (int i = 0; i < n; i += k) {
		int left = i;
		int right = min(i + k - 1, n - 1);

		while (left < right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
}


int main () {
	vector<int> arr = {1, 4, 3, 2, 6, 5, 6, 1};
	
	int k = 3;

	reverseInGroups (arr, k);

	for (int val : arr) {
		cout << val << " ";
	}

	return 0;
}