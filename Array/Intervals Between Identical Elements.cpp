#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> getDistances (vector<int>& arr) {
	int n = arr.size();
	vector<long long> result;
	
	unordered_map<int, vector<int>> data;
	
	for (int i = 0; i < n; i++) {
	    // Push the index i into the vector for the value arr[i]
        data[arr[i]].push_back(i);
	}

	for (int i = 0; i < n; i++) {
	    int sum = 0;
	    vector<int> temp = data[arr[i]];
	    
	    for (auto& x : temp) {
	        sum += abs (i - x);
	    }
	    
		result.push_back (sum);
	}

	return result;
}

int main () {
	vector<int> arr = {2,1,3,1,2,3,3};
	
	vector<long long> result = getDistances (arr);
	
	for (const auto& x : result) {
	    cout << x << " ";
	}

	return 0;
}

/*

Main Optimization Idea

Instead of searching whole array repeatedly:

store positions of identical elements together

unordered_map<int, vector<int>>

Store indices:

2 -> [0,4]
1 -> [1,3]
3 -> [2,5,6]

Now for each group, compute distances smartly.

Efficient Formula

For current position pos[i]:

Left contribution:
pos[i] * i - leftSum

Right contribution:
rightSum - pos[i] * (remainingCount)


*/