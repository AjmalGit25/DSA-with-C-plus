#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// [Naive Approach] By exploring all possible pairs - O(n^2) Time and O(1) Space
int maxProfit (vector<int>& prices) {
    int n = prices.size();
    
    int profit = 0;
    
    // Explore all possible ways to buy and sell stock
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            profit = max (profit, prices[j] - prices[i]);
        }
    }
    
    return profit;
}


// [Expected Approach] One Traversal Solution - O(n) Time and O(1) Space
int maxProfit (vector<int>& prices) {
    int n = prices.size();
    
    int minSoFar = prices[0];
    int profit = 0;
    
    for (int i = 1; i < n; i++) {
        
        // Update the minimum value seen so far
        minSoFar = min (minSoFar, prices[i]);
        
        // Update result if we get more profit
        profit = max (profit, prices[i] - minSoFar);
    }
    
    return profit;
}

int main () {
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    
    int result = maxProfit (prices);
    
    cout << "maxProfit: " << result << endl;
    
    return 0;
}

/*

A man looking at past data and saying “Kaash maine is din buy kiya hota… aur is din sell kiya hota…”
We don’t calculate profit on the same day.

What we do on the next day?
    If price goes higher than the buying price, we calculate maxProfit.
    If price goes down than the buying price, we update the minPrice.


If price > minPrice -> calculate maxProfit
If price < minPrice -> update minPrice

*/