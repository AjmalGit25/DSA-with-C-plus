#include <iostream>
#include <vector>
using namespace std;

void generatePermutations (string s, vector<bool>& used, string& curr, vector<string>& result) {
    if (curr.size() == s.size()) {
        result.push_back(curr);
        return;
    }
    
    for (int i = 0; i < s.size(); i++) {
        if (used[i])
            continue;
        
        curr += s[i];
        used[i] = true;
        
        generatePermutations (s, used, curr, result);
        
        used[i] = false;
        curr.pop_back();
    }
}

vector<string> permute (string s) {
    vector<string> result;
    string curr;
    
    vector<bool> used(s.size(), false);
    
    generatePermutations (s, used, curr, result);
    
    return result;
}

int main() {
    string s = "XYZ";
    
    vector<string> result = permute (s);
    
    for (const auto& rows : result) {
        for (const auto& x : rows) {
            cout << x;
        }
        cout << " ";
    }

    return 0;
}

/*

TC: O(n * n!)
SC: O(n + n!) = O(n!)

*/