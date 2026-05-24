#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> eraseOverlapIntervals (vector<vector<int>>& intervals) {
    if (intervals.empty()) 
        return {};
    
    // 1. Sort by END
    sort (intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    });
    
    vector<vector<int>> result;
    
    // 2. Pick first
    result.push_back (intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        // no overlap -> add
        if (result.back()[1] <= intervals[i][0])
            result.push_back (intervals[i]);
    }
    
    return result;
}

int main () {
    vector<vector<int>> intervals = {
        {1, 2},
		{2, 3},
		{3, 4},
		{1, 3}
    };
    
    vector<int> newInterval = {4,8};
    
    vector<vector<int>> res = eraseOverlapIntervals (intervals);
    
    for (auto &row : res) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}