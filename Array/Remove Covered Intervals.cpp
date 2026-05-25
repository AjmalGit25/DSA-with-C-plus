#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> removeCoveredIntervals(vector<vector<int>>& intervals) {
	if (intervals.empty())
		return {};

	// 1. Sort by (START ascending, END descending)
	sort(intervals.begin(), intervals.end(),
	[](vector<int>& a, vector<int>& b) {
		if (a[0] == b[0])
			return a[1] > b[1];

		return a[0] < b[0];
	}
	    );

	vector<vector<int>> result;
	int prev_end = 0;

	for (int i = 0; i < intervals.size(); i++) {
	    if (intervals[i][1] > prev_end) {
	        result.push_back (intervals[i]);
	        prev_end = intervals[i][1];
	    }
	}

	return result;
}

int main () {
	vector<vector<int>> intervals = {
		{0, 2},
		{3, 5},
		{5, 6},
		{1, 3},
		{1, 6}
	};

	vector<vector<int>> result = removeCoveredIntervals (intervals);

	for (auto& row : result) {
		for (auto& val : row) {
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;
}

/*

Remove Covered Intervals:

if same START
    sort by END descending
else
    sort by START ascending

Final sort result:
{
    {0,2},
    {1,6},
    {1,3},
    {3,5},
    {5,6}
}

Why This Special Sorting?
    For covered intervals: larger interval should appear first

-----------------------------------
Why "int prev_end = 0;" makes it so simple to remove covered intervals?
    -> maximum END seen so far
    -> No interval has been accepted yet.
    -> prev_end = largest END among accepted intervals

*/