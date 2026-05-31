#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> removeInterval (vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
	vector<vector<int>> result;

	for (auto& interval : intervals) {

		int start = interval[0];
		int end = interval[1];

		// left survives
		if (start < toBeRemoved[0]) {
			result.push_back({
				start,
				min(end, toBeRemoved[0])
			});
		}

		// right survives
		if (end > toBeRemoved[1]) {
			result.push_back({
				max(start, toBeRemoved[1]),
				end
			});
		}
	}

	return result;
}

int main () {
	vector<vector<int>> intervals = {
		{0, 2},
		{3, 4},
		{5, 7}
	};

	vector<int> toBeRemoved = {1, 6};

	vector<vector<int>> res = removeInterval (intervals, toBeRemoved);

	for (auto& row : res) {
	    for (auto& val : row) {
	        cout << val << " ";
	    }
	    cout << endl;
	}

	return 0;
}

/*

1272. Remove Interval:

Goal:
	Remove a specific interval portion from existing intervals.

Core Logic:
	For every interval:
		Case 1: No overlap
			-> Keep whole interval.

			Example:
				[1,2]
			remove = [5,6]
			No overlap.

		Case 2: Left part survives
		Example:
		interval = [0,5]
		remove   = [2,4]

		Left survives:
		
		[0,2]
		Case 3: Right part survives
		
		Same example:
		
		[4,5]
		also survives.

		Case 4: Interval fully removed

Example:

[3,4]
remove = [1,6]

Nothing survives.

*/