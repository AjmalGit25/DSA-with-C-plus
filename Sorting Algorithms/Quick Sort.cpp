#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int partition (vector<int>& arr, int start, int end) {
    int idx = start - 1;
    int pivot = arr[end];
    
    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            swap (arr[j], arr[++idx]);
        }
    }
    
    swap (arr[end], arr[++idx]);
    
    return idx;
}

void quickSort (vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivIdx = partition (arr, start, end);

        quickSort (arr, start, pivIdx - 1);     // left half
        quickSort (arr, pivIdx + 1, end);       // right half
    }
}

int main () {
    vector<int> arr = {5, 9, 2, 7, 11};
    
    quickSort (arr, 0, arr.size() - 1);
    
    for (int x : arr) cout << x << " ";
    
    return 0;
}


/*

Quick Sort is a Divide and Conquer sorting algorithm.
It sorts in-place.


Time Complexity: 
	Best/Average case	:	O(n log n)
	Worst case			:	O(n²)
	
Space Complexity		: 	O(n)   (Uses extra arrays during merging)

*/