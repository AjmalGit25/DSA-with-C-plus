#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void genPermutations (int n, string& curr, unordered_map<char, int>& mp, vector<string>& result) {
    if (curr.size() == n) {
        result.push_back (curr);
        return;
    }
    
    for (pair<char, int> it : mp) {
        char c = it.first;
        int count = it.second;
        
        if (count == 0) 
            continue;

        curr.push_back(c);

        mp[c]--;
        
        genPermutations (n, curr, mp , result);
        
        curr.pop_back();
        mp[c]++;
    }
}

vector<string> findPermutation (string s) {
    vector<string> result;
    
    unordered_map<char, int> mp;   

    for (char c : s) 
        mp[c]++;

    string curr = "";
    
    genPermutations (s.size(), curr, mp, result);
    
    return result;
}

int main() {
    string s = "ABC";
    vector<string> res = findPermutation(s);

    for (string perm: res)
        cout << perm << " ";

    return 0;
}

/*

Choose ? Explore ? Undo ? Try another choice

*/