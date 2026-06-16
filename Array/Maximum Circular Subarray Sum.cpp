#include <iostream>
#include <vector>
using namespace std;

int maxSubarrayCircularSum (vector<int>& nums) {
    int n = nums.size();
    
    int toalSum = 0;
    
    int currMaxSum = 0;
    int currMinSum = 0;
    
    int maxSum = nums[0];               
    int minSum = nums[0];
    
    for (int i = 0; i < n; i++) {
        
        // Kadane's to find maximum subarray sum
        currMaxSum = max (nums[i], nums[i] + currMaxSum);
        maxSum = max (maxSum, currMaxSum);
        
        // Kadane's to find minimum subarray sum
        currMinSum = min (nums[i], nums[i] + currMinSum);
        minSum = min (minSum, currMinSum);
        
        // Sum of all the elements
        toalSum += nums[i];
    }
    
    int normalSum = maxSum;
    int circularSum = toalSum - minSum;
    
    if (minSum == toalSum)
        return normalSum;
    else
        return max (normalSum, circularSum);
}


int main () {

	vector<int> nums = {8, -8, 9, -9, 10, -11, 12};

	int res = maxSubarrayCircularSum (nums);

	cout << res;

	return 0;
}

/*

Maximum Circular Subarray Sum = Total Sum - Minimum Subarray Sum.		(Standard formula)

*/