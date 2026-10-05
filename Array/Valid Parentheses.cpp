#include <iostream>
#include <stack>
using namespace std;

bool checkValidString(string s) {
    stack<int> open;
    stack<int> star;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(') 
            open.push(i);
        
        else if (s[i] == '*') 
            star.push(i);
        
        else { // ')'

            // First, use an actual '('
            if (!open.empty()) 
                open.pop();
            
            // Otherwise, use '*' as '('
            else if (!star.empty()) 
                star.pop();
            
            // Nothing can match ')'
            else 
                return false;
        }
    }

    // Match remaining '(' with '*' AFTER them
    while (!open.empty() && !star.empty()) {

        if (open.top() > star.top()) 
            // '*' occurs before '(' ? cannot act as ')'
            return false;

        open.pop();
        star.pop();
    }

    return open.empty();
}

int main() {
    string s = "((*))";
    
	cout << checkValidString(s);

	return 0;
}