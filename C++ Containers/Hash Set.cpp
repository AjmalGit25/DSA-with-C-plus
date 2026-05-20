#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10

vector<vector<string>> hash_set (SIZE);          // Chaining

// Hash function
int hash_function(string value) {
    int sum = 0;
    for (char c : value)
        sum += int (c);

    return sum % SIZE;							// hash code
}

// Add
void add (string value) {
    int idx = hash_function (value);
    for (string s : hash_set[idx]) {    
        if (s == value) return;                 // Duplicates NOT allowed
    }
    // Insert if not found
    hash_set[idx].push_back (value);            // no overwrite, 
}

// Delete
void removeValue (string value) {
    int idx = hash_function (value);
    
    for (auto it = hash_set[idx].begin(); it != hash_set[idx].end(); it++) {
        if (*it == value) {
            hash_set[idx].erase (it);
            return; 
        }
    }
    
    cout << "No value found!\n";
}

// Search
int search (string value) {
    int idx = hash_function (value);
    
    for (string str : hash_set[idx])
        if (str == value) return idx;

    return -1;
}

// Show
void show () {
    cout << "\nElements in Hash Set: \n";
    
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        for (string str : hash_set[i]) {
            cout << str << " ";
        }
        cout << "\n";
    }
}

int main () {
    add ("abc");
    add ("xyz");
    add ("xww");
    add ("abc"); 		// duplicate not allowed
    add ("maz");
    add ("gasoline");
    add ("rat");
    add ("mango");
    add ("rat");		// duplicate not allowed
    add ("mango");		// duplicate not allowed
    add ("rat");		// duplicate not allowed
    add ("abc");		// duplicate not allowed
    
    show ();
    
    string s;
    cout << "Search string: ";
    cin >> s;
    
    cout << "Search result: " << search (s) << endl;
    
    removeValue (s);
    show ();

	return 0;
}

/*
Hash Set structure:

	Index:        0        1        2        3        4
	Hash Set:
	           [ mango   ] [ xyz ] [ abc ] [ gas ] [ xww ]
	           [ pop     ]         [     ] [ maz ]
	           [ fox     ]


Properties:
    1. NO duplicates, Stores only keys (unique elements).
    2. NO associated value.
    3. Hash Set is called "unordered_set". "unordered_set" = Hash Set
    4. Hash Set is manually defined to know about the internal working of "unordered_set".
    5. Hash Set ? DS built on hash table (stores unique keys).
    6. Hash Set almost looks like Hash Table, only difference is uniqueness. Stores only UNIQUE keys or UNIQUE values.

-------------------------------------------------------

unordered_set == Hash Set

-------------------------------------------------------

"unordered" = not sorted
"set" = sorted
unordered_set = Data is not sorted


-------------------------------------------------------------------------------------
All four (set, map, unordered_set, unordered_map) are provided by the C++ Standard Template Library (STL).
-------------------------------------------------------------------------------------

They fall into two categories:

1. Ordered Containers (Tree-based):
	i) Set
	ii) Map
	
	-> Internally use a balanced tree (Red-Black Tree)
	-> Elements are always sorted

2. Unordered Containers (Hash-based):
	i) unordered_set
	ii) unordered_map
	
	-> Internally use a hash table
	-> No sorting, but faster access on average

*/	