#include <iostream>
#include <vector>
using namespace std;

int findClosestNumber (vector<int>& nums) {
	int closest = nums[0];

	for (int num : nums) {
		if (abs(num) < abs(closest))
			closest = num;
			
        else if (abs(num) == abs(closest) && num > closest)
			// Tie in distance, pick the larger number
			closest = num;
	}

	return closest;
}

int main () {
	vector<int> nums = {-4, -2, 1, 4, 8};

	int result = findClosestNumber (nums);

	cout << "Closest number to zero = " << result;

	return 0;
}