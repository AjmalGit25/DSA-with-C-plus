#include <iostream>
#include <vector>
using namespace std;

void moveZeroes (vector<int>& nums) {
    int j = 0;

    // Pass 1: Move nonzero elements forward
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) 
            nums[j++] = nums[i];
    }

    // Pass 2: Fill remaining positions with zeros
    while (j < nums.size()) 
        nums[j++] = 0;
}

int main () {
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	
	moveZeroes (arr);
    
    for (int x : arr) cout << x << " ";
    
    return 0;
}

/*

283. Moves Zero 


- Moves all zeroes to the end
- Maintain element relative order
- Do this in-place (without extra array)

*/