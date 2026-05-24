#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> merge (vector<vector<int>>& intervals) {
    if (intervals.empty()) 
        return {};
    
    // 1. Sort by START
    sort (intervals.begin(), intervals.end());
    
    vector<vector<int>> result;
    
    // 2. Pick first
    result.push_back (intervals[0]);
    
    // 3. Compare adjacent overlapping intervals & merge
    for (int i = 1; i < intervals.size(); i++) {
        if (result.back()[1] >= intervals[i][0]) 
        	// Overlapping -> merge
            result.back()[1] = max (result.back()[1], intervals[i][1]);
        else
        	// No overlapping -> add in result
            result.push_back (intervals[i]);
    }
    
    return result;
}

int main () {
	vector<vector<int>> intervals {
		{1, 3},
		{2, 6},
		{8, 10},
		{15, 18},
	};
	
	vector<vector<int>> res = merge (intervals);
	
	// See result:
	for (auto& row : res) {
	    for (auto& val : row) {
	        cout << val << " ";
	    }
	    cout << endl;
	}

	return 0;
}



/*

Merge Intervals Problem:
	1. Sort : Sort by START time
	2. Pick first activity
	3. Overlapping? Merge : Push in the result


Goal:
	-> Combine overlapping intervals

Why sort by START time?
	-> We need overlapping intervals to come together.
	-> Overlapping intervals become adjacent.
	-> All possible overlapping intervals appear continuously.
	-> So we can merge easily.

--------------------------------------------

Need earliest finishing? 	sort by END
Need overlap grouping? 		sort by START

-------------------------------------------------
Overlap logic:

start1 <= end2
AND
start2 <= end1

*/