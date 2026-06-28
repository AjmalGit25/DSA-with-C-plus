#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// [Naive Approach - 1] Using a temporary array - O(n) Time,  O(n) Space
vector<int> reverseArray  { 
    int n = arr.size();
    
    vector<int> result(n);
    
    for (int i = n - 1; i >= 0; i--) {
        result[n - i - 1] = arr[i];
    }
    
    return result;
}

// [Expected Approach - 2] Using Single Pointer - O(n) Time,  O(1) Space  | (Swap)
void reverseArray (vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n / 2; i++) 
        swap (arr[i], arr[n - i - 1]);
}


// [Expected Approach - 3] Using Two Pointers - O(n) Time,  O(1) Space  | (Swap)
void reverseArray (vector<int> &arr) {
    int n = arr.size();
    
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        swap (arr[left++], arr[right--]);
    }
}

// Using Inbuilt Methods - O(n) Time
void reverseArray (vector<int> &arr) {
    reverse (arr.begin(), arr.end());
}

// Using Stack - - O(n) Time,  O(n) Space
void reverseArray (vector<int> &arr) {
    int n = arr.size();
    
    stack<int> s;                   // stack
    
    // Copy arr elements to stack (from start)
    for (int i = 0; i < n; i++)
        s.push(arr[i]);
    
    // Copy stack elements back to arr (from top)
    for (int i = 0; i < n; i++) {
        arr[i] = s.top();
        s.pop();
    }
}



int main () {
    vector<int> arr = {1, 4, 3, 2, 6, 5};
    
    reverseArray (arr);
    
    for (int val : arr) {
        cout << val << " ";
    }

    return 0;
}