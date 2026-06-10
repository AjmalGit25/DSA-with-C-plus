#include <iostream>
#include <climits>
using namespace std;

int maxProfit (vector<int>& prices) {
	int n = prices.size();
	int profit = 0;

	// Explore all possible ways to buy and sell stock
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			res = max (profit, prices[j] - prices[i]);
		}
	}
	
	return profit;
}

int main () {
    vector<int> prices = {7,1,5,3,6,4};
    
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