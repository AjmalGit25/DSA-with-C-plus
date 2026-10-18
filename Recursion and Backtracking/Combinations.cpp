#include <iostream>
#include <vector>
using namespace std;

void backtrack (int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i <= n; i++) {

        current.push_back (i); 
        
        backtrack (n, k, i + 1, current, result);
        
        current.pop_back(); 
    }
}

vector<vector<int>> combination (int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    
    backtrack (n, k, 1, current, result);
    
    return result;
}

int main() {
    int n = 4;
    int k = 2;
    
    vector<vector<int>> result = combination (n, k);
    
    for (const auto& rows : result) {
        for (const auto& x : rows) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*

Examples:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

Input: n = 1, k = 1
Output: [[1]]

*/