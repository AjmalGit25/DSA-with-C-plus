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