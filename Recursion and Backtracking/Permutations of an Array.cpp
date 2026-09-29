#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void genPermutations (vector<int> nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& result) {
    if (curr.size() == nums.size()) {
        result.push_back (curr);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {

        // Already used
        if (used[i])
            continue;

        // Choose
        used[i] = true;
        curr.push_back (nums[i]);

        // Explore
        genPermutations (nums, used, curr, result);

        // Undo
        curr.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute (vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> curr;
    vector<bool> used(nums.size(), false);

    genPermutations (nums, used, curr, result);

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permute (nums);

    for (const auto& ans : res) {
        for (const auto& x : ans) {
            cout << x;
        }
        cout << " ";
    }

    return 0;
}