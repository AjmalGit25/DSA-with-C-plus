void nextPermutation (vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    
    // Step 1: find pivot
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;
    
    if (i >= 0) {
    	
        int j = n - 1;
        
        // Step 2: find next greater
        while (nums[j] <= nums[i])
            j--;
            
        // Step 3: swap
        swap (nums[i], nums[j]);
    }
    
    // Step 4: reverse right part
    reverse (nums.begin() + i + 1, nums.end());
}

/*

Next Permutation: (Standard Algorithm)

	Step 1: Find the first decreasing point from right (n - 1)
			Find index i such that: arr[i] < arr[i+1]
			This is called the pivot
	
	Step 2: Find just greater element from right (n - 1)
			From the right side, find element just greater than arr[i]
	
	Step 3: Swap them
	
	Step 4: Reverse the right part from pivot (from i+1 to end)
	
	
	Simple way:
		i.	Find decreasing point (pivot) i from right (n - 1)
		ii.	Find just greater element than pivot (arr[i]) from right (n - 1)
		iii. Swap them
		iv.	Reverse right part from pivot arr[i]
	
	
	Examples:
		i) 1 2 3 -> pivot = 2, 1 3 2 (swap) -> 1 2 3 (no reverse, right part already sorted) -> Final = 1 2 3 
		
		ii) 2 3 1 -> pivot = 2, 3 2 1 (swap) -> 3 1 2 (reverse right part) -> Final = 3 1 2
		
		iii) 3 2 1 -> no pivot, (means it's the last permutation) -> 1 2 3 (reverse entire array) -> Final = 1 2 3
		
		iv) 4 3 5 2 1 -> pivot = 3 (index = 1), (swap 3 5) -> 4 5 3 2 1 | (reverse right part) -> 4 5 1 2 3 ->  Final = 4 5 1 2 3

*/