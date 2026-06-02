#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> intervalIntersection (vector<vector<int>>& firstList,
vector<vector<int>>& secondList) {
	if (firstList.empty() || secondList.empty())
		return {};

	int n1 = firstList.size();
	int n2 = secondList.size();

	vector<vector<int>> result;

	int i = 0;
	int j = 0;

	while (i < n1 && j < n2) {
		int start = max(firstList[i][0], secondList[j][0]);
		int end = min(firstList[i][1], secondList[j][1]);

		if (start <= end) {
			result.push_back({start, end});
		}


		if (firstList[i][1] < secondList[j][1])
			i++;
		else
			j++;
	}

	return result;
}


int main () {
	vector<vector<int>> firstList = { {0, 2}, {4, 6}, {8, 10} };
	vector<vector<int>> secondList = { {1, 3}, {4, 5}, {7, 8}, {9, 10} };
	
	vector<vector<int>> result = intervalIntersection (firstList, secondList);
	
	for (const auto& row : result) {
	    for (const auto& val : row) {
	        cout << val << " ";
	    }
	    cout << endl;
	}

	return 0;
}

/*

986. Interval List Intersections:

The standard condition for Intersection:
	max(start1, start2) <= min(end1, end2)

This problem is usually solved using: Two Pointers
because both interval lists are already sorted.


*/