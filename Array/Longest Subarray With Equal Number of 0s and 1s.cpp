#include <iostream>
#include <vector>
using namespace std;

// [Naive Approach] Using Nested Loop - O(n^2) Time and O(1) Space
int maxLen (vector<int>& arr) {
    int n = arr.size();
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        
        for (int j = i; j < n; j++) {
            sum += (arr[j] == 0) ? -1 : 1;
            
            if (sum == 0)
                count = max (count, j - i + 1);
        }
    }
    
    return count;
}

// [Expected Approach] Using Hash Map and Prefix Sum Technique - O(n) Time and O(n) Space
int maxLen (vector<int>& arr) {
    int n = arr.size();
    
    unordered_map<int, int> mp;
    
    int prefSum = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        prefSum += (arr[i] == 0) ? -1 : 1;
        
        if (prefSum == 0)
            count = max (count, i + 1);
        
        if (mp.find (mp[prefSum]) != mp.end()) 
            count = max (count, i - mp[prefSum]);
        else
            mp[prefSum] = i;
    }
    
    return count;
}

int main () {
    vector<int> arr = {1, 0, 1, 1, 1, 0, 0};

	cout << maxLen (arr);

	return 0;
}