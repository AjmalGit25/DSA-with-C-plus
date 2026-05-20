#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10

vector<vector<pair<string, int>>> hash_map (SIZE);          // Chaining

// Hash function
int hash_function (string value) {
    int sum = 0;
    for (char c : value)
        sum += int (c);

    return sum % SIZE;							// hash code
}

// Add
void add (string key, int value) {
    int idx = hash_function (key);
    
    // Check if key already exists
    for (auto k : hash_map[idx]) {    
        if (k.first == key) return;                 // Duplicates key NOT allowed
    }
    // Insert if not found
    hash_map[idx].push_back ({key, value});
}

// Delete
void removeValue (string key) {
    int idx = hash_function (key);
    
    for (auto it = hash_map[idx].begin(); it != hash_map[idx].end(); it++) {
        if (it->first == key) {
            hash_map[idx].erase (it);
            cout << "Deleted successfully\n";
            return; 
        }
    }
    
    cout << "VALUE not found!\n";
}

// Search
int search (string key) {
    int idx = hash_function (key);
    
    for (auto k : hash_map[idx])
        if (k.first == key) return k.second;   // return VALUE

    return -1;      // not found
}

// Show
void show () {
    cout << "\nElements in Hash Map: \n";
    
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        for (auto k : hash_map[i]) 
            cout << k.first << " : " << k.second << ", ";
            
        cout << "\n";
    }
}

int main () {
    add ("alis", 123);
    add ("sam", 786);
    add ("bob", 415);
    add ("jon", 239);
    add ("ram", 675);
    add ("ram", 225);           // duplicates NOT allowed
    
    show ();
    
    string key;
    cout << "Search using key: ";
    cin >> key;
    
    cout << "Search result: " << search (key) << endl;
    
    removeValue (key);
    show ();

	return 0;
}

/*
Hash Map structure:

	Index:				  0				1				2				3				4
	key - value:
		           [ alis : 123 ]  [ sam : 786 ]   [ bob : 415 ]   [ jon : 239 ]   [ ram : 675 ]
		           [ johny : 123 ] [ mac : 900 ]      			   [ don : 139 ]
																   [ xavier : 939 ]

Key Value rules:
	1. Order: key:value
	
	2. Always: 
		Key comes first					(first will be assumed as "key")
		Value comes second				(second will be assumed as "value")

	3. Always search using the key, not the value.
		Key = identifier (used for searching)
		Value = data associated with key

	4. Key can be any types: int, char, string, ...
	5. Hash code is computed for the KEY.
	6. Key ? must be UNIQUE, Value ? can be DUPLICATE.

Pair:
	pair<string, int> p;
	
		p.first   ? key (string)
		p.second  ? value (int)

-----------------------------------------------------------

unordered_map == Hash Map

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