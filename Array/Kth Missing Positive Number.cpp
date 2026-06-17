#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findKthPositive (vector<int>& arr, int k) {
    int curr = 1;
    int i = 0;

    while (k > 0) {

        if (i < arr.size() && arr[i] == curr) {
            i++;
        }
        else {
            k--;

            if (k == 0)
                return curr;
        }

        curr++;
    }

    return curr;
}

int main () {    
    vector <int> arr = {2,3,4,7,11};
    
    int k = 5;
    
    int res = findKthPositive (arr, k);
    
    return 0;
}


/*

Sort the array if not sorted!

Time: O(n + k)

*/