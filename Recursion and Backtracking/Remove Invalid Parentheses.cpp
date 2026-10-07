#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void helper(string& s,
            int index,
            int removeOpen,
            int removeClose,
            int balance,
            string& curr,
            unordered_set<string>& result) {

    // End of string
    if (index == s.size()) {

        if (removeOpen == 0 && removeClose == 0 && balance == 0) 

            result.insert (curr);

        return;
    }

    char ch = s[index];

    // -------------------------
    // OPTION 1: REMOVE
    // -------------------------

    if (ch == '(' && removeOpen > 0) 
    
        helper (s, index + 1, removeOpen - 1, removeClose, balance, curr, result);

    if (ch == ')' && removeClose > 0)

        helper (s, index + 1, removeOpen, removeClose - 1, balance, curr, result);


    // -------------------------
    // OPTION 2: KEEP
    // -------------------------

    curr.push_back(ch);

    if (ch == '(')

        helper (s, index + 1, removeOpen, removeClose, balance + 1, curr, result);

    else if (ch == ')') {

        // Can't have more ')' than '('
        if (balance > 0) 

            helper (s, index + 1, removeOpen, removeClose, balance - 1, curr, result);
    }
    else {

        // Normal character
        helper (s, index + 1, removeOpen, removeClose, balance, curr, result);
    }

    // BACKTRACK
    curr.pop_back();
}

vector<string> removeInvalidParentheses (string s) {

    int removeOpen = 0;
    int removeClose = 0;

    int balance = 0;

    // Find minimum number of removals needed
    for (char ch : s) {

        if (ch == '(') 
            balance++;

        else if (ch == ')') {

            if (balance > 0)
                balance--;
            else
                removeClose++;
        }
    }

    removeOpen = balance;

    unordered_set<string> result;
    string curr;

    helper (s, 0, removeOpen, removeClose, 0, curr, result);

    return vector<string> (result.begin(), result.end());
}

int main() {
    string s = "()())()";
    
    vector<string> result = removeInvalidParentheses(s);
    
    for (const auto& x : result) cout << x << " ";
}

/*

Leetcode 301: Remove Invalid Parentheses

----------------------------------------------------------------

We need to satisfy three requirements simultaneously:

	1. Remove parentheses.
	2. Result must be valid.
	3. Remove the minimum possible number of parentheses.
	4. No duplicate answers.


*/