#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert (vector<vector<int>>& intervals, vector<int>& newInterval) {
    // sort (START)
//    sort (intervals.begin(), intervals.end()); // This problem already guarantees intervals are sorted.
    
    vector<vector<int>> result;
    
    int i = 0;
    int n = intervals.size();
    
    // 1. Add intervals before Overlap
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back (intervals[i]);
        i++;
    }
    
    // 2. Merge Overlaps
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min (newInterval[0], intervals[i][0]);
        newInterval[1] = max (newInterval[1], intervals[i][1]);
        i++;
    }
    
    result.push_back (newInterval);
    
    // 3. Add remaining intervals
    while (i < n) {
        result.push_back (intervals[i]);
        i++;
    }
    
    return result;
}

int main () {
    vector<vector<int>> intervals = {
        {1, 2},
        {3, 5},
        {6, 7},
        {8, 10},
        {12, 16},
    };
    
    vector<int> newInterval = {4,8};
    
    vector<vector<int>> res = insert (intervals, newInterval);
    
    for (auto &row : res) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}