// Prefix Sum ----------- Total sum from left
vector<int> prefixSum (vector<int>& nums) {
    int n = nums.size();
    
    vector<int> prefixSum(n);
    
    prefixSum[0] = nums[0];
    
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    return prefixSum;
}

// Suffix Sum ----------- Total sum from right
vector<int> suffixSum (vector<int>& nums) {
    int n = nums.size();
    
    vector<int> suffixSum(n);
    
    suffixSum[n-1] = nums[n-1];
    
    for (int i = n - 2; i >= 0; i--) {
        suffixSum[i] = nums[i] + suffixSum[i+1];
    }
    
    return suffixSum;
}

// Prefix Max ----------- maximum seen so far from left
vector<int> prefixMax (vector<int>& nums) {
    int n = nums.size();
    
    vector<int> prefixMax(n);
    
    prefixMax[0] = nums[0];
    
    for (int i = 1; i < n; i++) {
        prefixMax[i] = max (prefixMax[i-1], nums[i]);
    }
    
    return prefixMax;
}

// Prefix Min ----------- minimum seen so far from left
vector<int> prefixMin (vector<int>& nums) {
    int n = nums.size();
    
    vector<int> prefixMin(n);
    
    prefixMin[0] = nums[0];
    
    for (int i = 1; i < n; i++) {
        prefixMin[i] = min (prefixMin[i-1], nums[i]);
    }
    
    return prefixMin;
}

// Suffix Min ----------- minimum seen so far from right
vector<int> suffixMin (vector<int>& nums) {
    int n = nums.size();
    
    vector<int> suffixMin(n);
    
    suffixMin[n-1] = nums[n-1];
    
    for (int i = n - 2; i >= 0; i--) {
        suffixMin[i] = min (suffixMin[i+1], nums[i]);
    }
    
    return suffixMin;
}

// Suffix Max ----------- maximum seen so far from right
vector<int> suffixMax (vector<int>& nums) {
    int n = nums.size();
    
    vector<int> suffixMax(n);
    
    suffixMax[n-1] = nums[n-1];
    
    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max (suffixMax[i+1], nums[i]);			// only change | max <-> min
    }
    
    return suffixMax;
}

/*

Prefix Sum		Left -> Right		prefix[i] = prefix[i-1] + nums[i]
Suffix Sum		Right -> Left		suffix[i] = suffix[i+1] + nums[i]

Prefix Max		Left -> Right		prefix[i] = max(prefix[i-1], nums[i])
Prefix Min		Left -> Right		prefix[i] = min(prefix[i-1], nums[i])

Suffix Max		Right -> Left		suffix[i] = max(suffix[i+1], nums[i])
Suffix Min		Right -> Left		suffix[i] = min(suffix[i+1], nums[i])

*/