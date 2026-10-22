void merge (vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) 
            temp.push_back (arr[i++]);
        else 
            temp.push_back (arr[j++]);
    }
    
    while (i <= mid) 
        temp.push_back (arr[i++]);
    
    while (j <= right) 
        temp.push_back (arr[j++]);
    
    for (int idx = 0; idx < temp.size(); idx++)
        arr[idx + left] = temp[idx];
}

void mergeSort (vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort (arr, left, mid);			// left half
        mergeSort (arr, mid + 1, right);	// right half

        merge (arr, left, mid, right);		// merge left and right sorted halves
    }
}

/*

Merge Sort is a Divide and Conquer algorithm

Working Principle:

	1. Divide → Split the array into two halves
	2. Conquer → Recursively sort both halves
	3. Merge → Merge the two sorted halves into one sorted array

---------------------------------------------------------------------

Time Complexity: 
	Best/Average/Worst case	:	O(n log n)

Space Complexity			: 	O(n)   (Uses extra arrays during merging)

*/