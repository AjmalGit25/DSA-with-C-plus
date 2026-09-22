
void selectionSort (vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min = i;
        
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[min] > arr[j])
                min = j;
        }
        
        swap (arr[i], arr[min]);
    }
}

/*

Selection Sort is a straightforward comparison-based sorting algorithm.

Working Principle:
	1. Start with the entire list	:	Consider the first element as the minimum (or maximum)
	2. Find the minimum element		: 	Traverse the unsorted part of the list to find the smallest element
	3. Swap							: 	Swap this smallest element with the first element of the unsorted part
	4. Move to the next position	:	Now, consider the next position as part of the sorted section
	5. Repeat						: 	Continue this process for each position in the list until the entire list is sorted

Time Complexity:
	Worst					: 	O(n²)
	Average					: 	O(n²)
	Best (already sorted)	: 	O(n²)

Selection Sort: Best = Average = Worst = O(n²)

It performs well for small datasets.

*/