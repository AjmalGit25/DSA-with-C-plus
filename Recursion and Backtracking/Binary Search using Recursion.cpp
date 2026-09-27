#include <iostream>
#include <vector>
using namespace std;

int binarySearch (vector<int>& nums, int target, int start, int end) {
	
	if (start <= end) {
	    int mid = start + (end - start) / 2;
	    
	    if (nums[mid] == target)
	        return mid;
	    
	    if (nums[mid] < target) 
	        return binarySearch (nums, target, mid + 1, end);
	    else
	        return binarySearch (nums, target, start, mid - 1);
	}

	return -1;
}


int main () {
	vector<int> nums = {-1, 0, 3, 5, 9, 12};
	int target = 9;

	cout << binarySearch (nums, target, 0, nums.size() - 1);
	
	return 0;
}