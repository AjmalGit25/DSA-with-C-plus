#include <iostream>
#include <vector>
using namespace std;

/* [Naive Approach] By Trying All Possibility - O(2^n) Time and O(n) Space */
// Recursive function to find max profit
int maxProfitRec (vector<int> &price, int start, int end) {
    int res = 0;

    // Try every possible pair of buy (i) and sell (j)
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            
            // Valid transaction if selling price > buying price
            if (price[j] > price[i]) {
               
                // Current profit + profit from left and right parts
                int curr = (price[j] - price[i]) +
                           maxProfitRec (price, start, i - 1) +
                           maxProfitRec (price, j + 1, end);
                res = max (res, curr);
            }
        }
    }
    return res;
}

int maxProfit (vector<int> &prices) {
    return maxProfitRec (prices, 0, prices.size() - 1);
}




int main () {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    
    cout << maxProfit (prices);
    
    return 0;
}