#include<iostream>
#include<vector>
using namespace std;

int merge (vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    int count = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp.push_back (arr[i++]);
        }
        else {
            temp.push_back (arr[j++]);
            count += mid - i + 1;
        }
    }
    
    while (i <= mid) 
        temp.push_back (arr[i++]);
    
    while (j <= right) 
        temp.push_back (arr[j++]);
    
    for (int idx = 0; idx < temp.size(); idx++)
        arr[idx + left] = temp[idx];
    
    return count;
}

int mergeSort (vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        int leftCount = mergeSort (arr, left, mid);			// left half
        int rightCount = mergeSort (arr, mid + 1, right);	// right half

        int count = merge (arr, left, mid, right);
        
        return count + leftCount + rightCount;
    }
    
    return 0;
}

int main () {
    vector<int> nums = {6, 3, 5, 2, 7};
    
    cout << mergeSort(nums, 0, nums.size() - 1);
}