#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

/* Mean -- Median -- Mode */

// Mean
double mean (vector<int> val) {
    double ans = 0;
    for (int i : val) {
        ans += i;
    }
    
    return ans / val.size();
}

// Median
double median (vector<int> val) {
    int n = val.size();
    sort (val.begin(), val.end());
    
    if (n % 2 == 0)
        return double(val[n/2] + val[n/2 - 1]) / 2.0;
    
    return val[n/2];
}

// Mode (only one mode)
double mode(vector<int> val) {
    unordered_map<int, int> freq;

    for (int x : val) {
        freq[x]++;
    }

    int maxFreq = 0;
    int modeValue = val[0];

    for (auto &p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            modeValue = p.first;
        }
    }

    return modeValue;
}

// Mode (all modes)
vector<int> mode(vector<int> val) {
    unordered_map<int,int> freq;

    for (int x : val) freq[x]++;

    int maxFreq = 0;
    for (auto &p : freq) {
        maxFreq = max(maxFreq, p.second);
    }

    vector<int> modes;
    for (auto &p : freq) {
        if (p.second == maxFreq) {
            modes.push_back(p.first);
        }
    }

    return modes;
}

int main () {
    vector<int> val = {4, 3, 5, 11, 2, 9};
    
    cout << "Mean (Average): " << mean (val) << endl;
    
    cout << "Median: " << median (val) << endl;
    
    cout << "Mode: " << mode (val) << endl;

    return 0;
}

/*

Mean (Average):
	The mean is what most people call the average.

Example:
	Numbers: 1, 2, 3, 4
	Mean = (1 + 2 + 3 + 4) / 4 = 2.5

------------------------------------
Median:
	The median is the middle number after sorting.

Example:
	Numbers: 1, 3, 5 ? Median = 3
	Numbers: 1, 2, 3, 4 ? Median = (2 + 3) / 2 = 2.5

------------------------------------
Mode:
	The mode is the value that appears most often.

Example:
	Numbers: 1, 2, 2, 3, 4
	Mode = 2
	
	{1,2,2,3,3} ? modes = 2 and 3		(Multiple modes possible)
	
	{1,2,3,4} ? no repetition 			(No mode case)


*/