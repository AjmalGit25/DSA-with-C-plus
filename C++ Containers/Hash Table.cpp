#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10

vector<vector<string>> hash_table (SIZE);        // Chaining

// Hash function
int hash_function (string value) {
    int sum = 0;
    for (char c : value)
        sum += int (c);

    return sum % SIZE;							// hash code
}

// Add
void add (string value) {
    int idx = hash_function (value);
    hash_table[idx].push_back (value);          // no overwrite, Duplicates allowed
}

// Delete
void removeValue (string value) {
    int idx = hash_function (value);
    
    for (auto it = hash_table[idx].begin(); it != hash_table[idx].end(); it++) {
        if (*it == value) {
            hash_table[idx].erase (it);
            return; 
        }
    }
    
    cout << "No value found!\n";
}

// Search
int search (string value) {
    int idx = hash_function (value);
    
    for (string str : hash_table[idx])
        if (str == value) return idx;

    return -1;
}

// Show
void show () {
    cout << "\nElements in Hash Table: \n";
    
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        for (string str : hash_table[i]) {
            cout << str << " ";
        }
        cout << "\n";
    }
}

int main () {
    add ("abc");
    add ("xyz");
    add ("xww");
    add ("abc"); // duplicate allowed
    add ("maz");
    add ("gasoline");
    add ("rat");
    add ("mango");
    
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

Bucket: Each element in a hash table is called a bucket (list), that stores many elements.

Chaining: Each index stores multiple values instead of one.

Collision: If two strings get the same index (same hash), the previous value gets overwritten. This is called a collision.

How to Handle Collisions?
    1. Chaining     (current code)
    2. Open Addressing (Advanced)


Hash Table is implemented using both: 
	1. Array + Linked List (Chaining) 
		vector<vector<string>> hash_table (SIZE); 
	
	2. Array + Struct (for key-value) 			// current implementation
		
		struct Node {
		    string key;
		    int value;
		};
		
		vector<vector<Node>> hash_table;


Hash Table structure:

	Index:        0        1        2        3        4
	Hash Table:
	           [ mango   ] [ xyz ] [ abc ] [ gas ] [ xww ]
	           [ pop     ]         [ abc ] [ maz ]
	           [ fox     ]				   [ gas ]

vector<vector<string>> hash_table;

hash_table[0] = ["mango", "pop", "fox"]
hash_table[1] = ["xyz"]
hash_table[2] = ["abc", "abc"]
hash_table[3] = ["gas", "maz", "gas"]
hash_table[4] = ["xww"]												// This is called: Chaining (Separate Chaining)

Properties:
    1. It is the base data structure (DS) for Hash Set and Hash Map.
    2. Allows duplicate elements.
    3. It can store:
		Only values
		Only keys
		Key–value pairs
	4. unordered_map (Hash Map), unordered_set (Hash Set) are implemented using Hash Table internally.

STL containers "unordered_set" and "unordered_map" are enough for "Hash Set" and "Hash Map". Manual implementation is mainly for:
	i. Learning (like you’re doing now)
	ii. Internal working
	iii. Interviews (to show understanding)


Final Mental Model:
	Hash Table → can store anything
	Hash Set   → stores UNIQUE keys only
	Hash Map   → stores key → value
	
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