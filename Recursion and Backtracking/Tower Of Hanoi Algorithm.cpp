#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    towerOfHanoi(n - 1, auxiliary, target, source);
}


int main () {
	char source = 'S', target = 'T', auxiliary = 'A';
	
	towerOfHanoi (3, source, target, auxiliary);
	
	return 0;
}

/*
It ONLY:

	-> Prints the correct move sequence

	-> Describes the algorithm

*/