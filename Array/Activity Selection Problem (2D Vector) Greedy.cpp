#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge (vector<vector<int>>& intervals) {
    if (intervals.empty()) 
        return {};
    
    // 1. sort (END)
    sort (intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
    
    vector<vector<int>> result;
    
    // 2. pick First
    result.push_back (intervals[0]);
    
    // 3. Compare & select
    for (int i = 1; i < intervals.size(); i++) {
        // no overlap -> select (add)
        if (result.back()[1] < intervals[i][0]) {
            result.push_back (intervals[i]);
        }
    }
    
    return result;
}

int main () {
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 5},
        {3, 7},
        {4, 6},
        {11, 13},
        {9, 15},
    };
    
    
    vector<vector<int>> res = merge (intervals);
    
    for (auto &row : res) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}


/*
Activity Selection:

Goal:
	Select maximum non-overlapping intervals

Pure Greedy problem

-------------------------------------------------
Overlap logic:

start1 <= end2
AND
start2 <= end1

*/