#include <iostream>
#include <vector>
using namespace std;

// [Naive Approach] Using Nested Loops - O(n^2) Time, O(1) Space
vector<int> productExceptSelf (vector<int>& arr) {
    int n = arr.size();
    
    vector<int> res;
    
    for (int i = 0; i < n; i++) {
        int sum = 1;
        
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            
            sum *= arr[j];
        }
        
        res.push_back (sum);
    }
    
    return res;
}

// [Efficient Approach] Using Product Array - O(n) Time, O(1) Space
vector<int> productExceptSelf (vector<int>& arr) {
	int n = arr.size();
	
	vector<int> res (n, 0);

	int zeros = 0, idx = -1;
	int prod = 1;
	
	// Find zero & calculate product
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0) {
			zeros++;
			idx = i;
		} else {
			prod *= arr[i];
		}
	}
	
	if (zeros == 0) {
        for (int i = 0; i < n; i++)
            res[i] = prod / arr[i];
    }
    
    else if (zeros == 1)
        res[idx] = prod;
    
	return res;
}

int main () {
    vector<int> arr = {10, 3, 5, 6, 2};
    
    vector<int> res = productExceptSelf (arr);
    
    for (int x : res) {
        cout << x << " ";
    }
        

    return 0;
}

/*

One zero makes the total product 0
Only if one zero:
	All indices have product 0, except itself

If two or more zero:
	All indices have product 0		(which is already set 0 in result: res (n, 0))

*/