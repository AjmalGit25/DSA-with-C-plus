#include <iostream>
#include <vector>
using namespace std;

void backtrack (vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] > target)
            continue;
        
        current.push_back (candidates[i]); 
        
        backtrack (candidates, target - candidates[i], i, current, result);
        
        current.pop_back(); 
    }
}

vector<vector<int>> combinationSum (vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    
    backtrack (candidates, target, 0, current, result);
    
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> result = combinationSum (candidates, target);
    
    for (const auto& rows : result) {
        for (const auto& x : rows) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*

Examples:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []

*/