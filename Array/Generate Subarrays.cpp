#include <iostream>
#include <vector>
using namespace std;

// Time O(n^3)
vector<vector<int>> generateSubarrays (vector<int>& arr) {

	int n = arr.size();

	vector<vector<int>> result;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			vector<int> subarray;

			for (int k = i; k <= j; k++) {
				subarray.push_back (arr[k]);
			}

			result.push_back (subarray);
		}
	}

	return result;
}

// Time O(n^2)
vector<vector<int>> generateSubarrays (vector<int>& arr) {
    int n = arr.size();

    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
        vector<int> subarray;

        for (int j = i; j < n; j++) {
            subarray.push_back (arr[j]);
            result.push_back (subarray);
        }
    }

    return result;
}

int main () {

	vector<int> arr = {1, 2, 3, 4, 5};

	vector<vector<int>> result = generateSubarrays (arr);

	for (const auto& rows : result) {
		for (const auto& x : rows) {
			cout << x << " ";
		}

		cout << endl;
	}

	return 0;
};