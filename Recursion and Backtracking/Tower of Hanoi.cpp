#include <iostream>
#include <stack>
using namespace std;

stack<int> S, A, T;   // Source, Auxiliary, Target

// Move function (with validation)
void moveDisk(stack<int>& from, stack<int>& to, char f, char t) {
	if (!from.empty() && (to.empty() || from.top() < to.top())) {
	    to.push(from.top());
	    from.pop();
	    cout << "Move disk from " << f << " to " << t << endl;
	}
}


void towerOfHanoi(int n,
                  stack<int>& source, stack<int>& auxiliary, stack<int>& target,
                  char s, char a, char t) {

	if (n == 0) return;
	
	towerOfHanoi(n - 1, source, target, auxiliary, s, t, a);
	
	moveDisk(source, target, s, t);
	
	towerOfHanoi(n - 1, auxiliary, source, target, a, s, t);
} 

int main () {
	
	int n = 3;

    // push disks into Source (largest at bottom)
    for (int i = n; i >= 1; i--) {
        S.push(i);
    } 
	
    towerOfHanoi(n, S, A, T, 'S', 'A', 'T');
	
	return 0;
}