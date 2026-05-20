#include <iostream>
#include <map>
using namespace std;


int main () {
	/* Syntax: map<key, value> mapName; ----- */

	// Create a map strings as keys and integers as values (only declaration)
	map<string, int> person;

	// Create a map with values (initialization)
	map<string, int> people = { {"John", 32}, {"Alis", 45}, {"Bo", 29} };

    
	/* Access a Map : Only accessible by keys in [] or .at() function ----- */

	// Get the value associated with the key "John"
	cout << "John is: " << people["John"] << "\n";

    // Get the value associated with the key "Adele"
	cout << "Alis is: " << people["Alis"] << "\n";
	
    cout << "Alis is: " << people.at ("Alis") << "\n";
    
    cout << "Bo is: " << people.at ("Bo") << "\n";
    
    
    /* Size of a Map : .size() function ----- */
    
    cout << "Size of people: " << people.size() << endl;  // Outputs 3
    
    
	/* Change Values : keys in [] or .at() function ----- */
	
	// Change John's value to 50 instead of 32
    people["John"] = 50;
    
    people.at("John") = 75;

    cout << "John is: " << people.at("John");  // Now outputs John is: 75
    
    
    /* Add Elements : keys in [] or .insert() function ----- */
    
    // Add new elements : keys in []
    people["Gabriel"] = 22;
    people["Liam"] = 24;
    people["Kasper"] = 20;
    
    // Add new elements : .insert()
    people.insert( {"Xavier", 22} );
    people.insert( {"Dalius", 24} );
    people.insert( {"Moores", 30} );
    
    
    /* Check if a Map is Empty : .empty() function ----- */
    
    cout << endl << person.empty();     // Outputs 1 (The map is empty)
    cout << endl << people.empty();     // Outputs 0 (not empty)
    
    
    /* Loop Through a Map : 'auto' for auto-determine data type */
    
    for (auto person : people) {
      cout << person.first << " is: " << person.second << "\n";
    }
    
    
    /* Remove Elements : .erase() function ----- */
    
    // Remove an element by key
    people.erase("John");
    
    
    /* Remove All Elements : .clear() function ----- */
    
    // Remove all elements
    people.clear();
    
    
    /* Create a Map in Descending order : 'greater<type>' functor */
    
    map<string, int, greater<string>> team = { {"John", 32}, {"Adele", 45}, {"Bo", 29} };

    for (auto member : team) {
      cout << "Member '" << member.first << "' is: " << member.second << "\n";
    }
    
    
	return 0;
}

/*

Elements in a map are:
	-> Accessible by keys (not index), and each key is unique.
	-> Automatically sorted in ascending order by their keys.


'map' in C++ is an ordered map.		Used for sorted, ordered maps.
'unordered_map' in C++ is a hash map (or hashmap). Used for faster, hash-based maps.

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