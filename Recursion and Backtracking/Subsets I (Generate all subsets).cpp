#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generate (vector<int>& nums, int idx, vector<int>& current, vector<vector<int>>& result) {

	// Base case:
	if (idx == nums.size()) {
		result.push_back(current);
		return;
	}

	// Choice 1: INCLUDE set[index]
	current.push_back(nums[idx]);

	generate (nums, idx + 1, current, result);

	// Undo the choice
	current.pop_back();

	// Choice 2: EXCLUDE set[index]
	generate (nums, idx + 1, current, result);
}

vector<vector<int>> genSubsets (vector<int>& nums) {
	vector<vector<int>> result;
	vector<int> current;

	generate (nums, 0, current, result);

	return result;
}


int main () {
	vector<int> nums = {1, 2, 2};

	vector<vector<int>> subsets = genSubsets (nums);

	for (const auto& subset : subsets) {
		cout << "{ ";

		for (const auto& x : subset) {
			cout << x << " ";
		}

		cout << "}\n";
	}

	return 0;
}