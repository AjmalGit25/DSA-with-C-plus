#include <iostream>
using namespace std;

void printHollowDiamond (int n) {
    int i, j;

    // Upper part of diamond
    for (i = 1; i <= n; ++i) {
        
        // space
        for (j = 1; j <= n - i; ++j)
            cout << " ";
            
        // star
        for (j = 1; j <= 2 * i - 1; ++j) {
            
            if (j == 1 || j == 2 * i - 1)
            
                cout << "*";
            else
                cout << " ";
        }
        
        cout << endl;
    }

    // Lower part of diamond
    for (i = n - 1; i >= 1; --i) {
        
        // space
        for (j = 1; j <= n - i; ++j)
            cout << " ";
        
        // star
        for (j = 1; j <= 2 * i - 1; ++j) {
            
            if (j == 1 || j == 2 * i - 1)
            
                cout << "*";
            else
                cout << " ";
        }
        
        cout << endl;
    }
}

int main () {
    int n;
    cout << "Enter the number of rows for the upper half of the diamond: ";
    cin >> n;
    
    printHollowDiamond (n);
    
    return 0;
}