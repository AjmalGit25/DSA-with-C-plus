#include <iostream>
#include <vector>
using namespace std;

int longestWPI (vector<int>& hours) {
    int n = hours.size();
    int length = 0;

    for (int i = 0; i < n; i++) {

        int score = 0;

        for (int j = i; j < n; j++) {

            if (hours[j] > 8)   // (strictly) greater than 8
                score++;
            else
                score--;

            if (score > 0)
                length = max (length, j - i + 1);
        }
    }

    return length;
}

int main () {
    vector<int> hours = {9,9,6,89,9,0,6,6,9,1,8,1,1,8,5,8};
	int result = longestWPI (hours);
	
	cout << "Longest Interval = " << result;

	return 0;
}