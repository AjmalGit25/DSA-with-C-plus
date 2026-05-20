#include <iostream>
#include <set>
using namespace std;

template <typename T>
void printSetElements (const set<T>& setName) {
    for (const T& val : setName) {
        cout << val << " ";
    }
    cout << endl;
}

int main () {
	set<int> numbers = {1, 7, 3, 2, 5, 9};

	// Print set elements
	printSetElements (numbers);
	

	/* Sort elements in a set in descending order ----- */
	set<int, greater<int>> nums = {1, 7, 3, 2, 5, 9};
	
	/* set is ascending by default using less<int> ----- */
    set<int, less<int>> nums2 = {1, 7, 3, 2, 5, 9};

	// Print the elements
	for (int num : nums2) {
		cout << num << "\n";
	}


	/* Unique Elements : cannot be duplicated or equal ----- */

	set<string> cars = {"Volvo", "BMW", "Ford", "BMW", "Mazda"};

	// Print set elements
	printSetElements (cars);


	/* Add Elements : .insert() function ----- */

	// Add new elements
	cars.insert ("Tesla");
	cars.insert ("Volvo");           // adding duplicate will be ignored
	cars.insert ("Toyota");
	cars.insert ("Audi");

	// Print set elements
	printSetElements (cars);


	/* Remove Elements : .erase() function ----- */

	// Remove elements
	cars.erase ("Volvo");
	cars.erase ("Mazda");
	
	// Print set elements
	printSetElements (cars);
    

	/* Remove All Elements : .clear() function ----- */

	// Remove all elements
	cars.clear ();
	
	if (cars.empty ()) cout << "Empty set\n"; else printSetElements (cars);


	return 0;
}

/*

Set:
	A set is a data structure or container provided by the C++ STL (Standard Template Library).
	It stores unique elements.
	Elements are sorted automatically in ascending order.
	Elements are unique, meaning equal or duplicate values are ignored.
	Elements can be added or removed, but the value of an existing element cannot be changed.
	Elements cannot be accessed by index numbers, because the order is based on sorting and not indexing.
	
	Set automatically keeps elements:
		-> Sorted	(ascending by default)
		-> Unique


Sorting of Set:
	Comparator decides order:
		i) less<int> ? ascending
		ii) greater<int> ? descending
	
	set<int> nums = {1, 7, 3, 2, 5, 9};						Output: 1 2 3 5 7 9
	set<int, less<int>> nums = {1, 7, 3, 2, 5, 9};			Output: same result as default
	
	set<int, greater<int>> nums = {1, 7, 3, 2, 5, 9};		Output: 9 7 5 3 2 1

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