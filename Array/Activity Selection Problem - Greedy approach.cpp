#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Each train = an activity with start and finish time
struct train {
  int start;
  int end;
};

int main () {
    train trains[] = { 
						{6, 11}, 
						{5, 7}, 
						{1, 4}, 
						{8, 12}, 
						{3, 6}, 
						{8, 9} 
					};
    
    int n = sizeof (trains) / sizeof (trains[0]);
    
    // 1. Sort trains based on the 'end' member
    sort (trains, trains + n, [](const train &a, const train &b) { 
        return a.end < b.end;
    });
    
    // 2. First activity (after sorting) is always selected
    cout << "Train 1: start = " << trains[0].start << ", end = " << trains[0].end << endl;
    
    int current = 0;
    
    for (int next = 1; next < n; next++) { 
    	
    	// 3. Select non-overlapping ones
        if (trains[current].end <= trains[next].start) { 
            current = next;
            
            cout << "Train " << next + 1 
                 << ": start = " << trains[next].start
                 << ", end = " << trains[next].end << endl;
        }
    }

	return 0;
}

/*

Activity Selection Problem using Greedy approach:
	1. Sort : Sort by END time
	2. Pick first activity
	3. Select non-overlapping ones


Time Complexity: O(n log n)
	Sorting → O(n log n)
	Loop → O(n)


Goal:
	-> Select maximum number of non-overlapping activities.		"Don’t overlap"
	-> We want the maximum number of activities.

Why sort by END time?
	-> Finish the current activity as early as possible so more activities can fit later
	-> So we choose the activity with the smallest ending time first.
	
Job Scheduling Problem's Goal:
	Maximize profit, not number of jobs.						"Fit jobs before deadlines to earn max profit"

------------------------------------------------

Need earliest finishing? → sort by END
Need overlap grouping? → sort by START

-------------------------------------------------
Overlap logic:

start1 <= end2
AND
start2 <= end1

*/