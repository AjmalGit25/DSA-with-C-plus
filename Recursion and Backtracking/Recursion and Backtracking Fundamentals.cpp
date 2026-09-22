

/*

1. What is Recursion?

	-> Recursion is when a function calls itself.

	-> A recursive function has two important parts:

	Base case 		= when to stop
	Recursive case  = the function calls itself with a smaller/simpler input

	-> The function keeps going deeper until it reaches the base case, then comes back.


2. What is Backtracking?

	-> Backtracking is a problem-solving technique that uses Recursion to explore different possibilities.

-----------------------------------------------------------------------------------------------------
do something
recursiveCall()
undo something

*/

// ======================== Recusrion ==========================
int fact (int n) {
    if (n == 0)
        return 1;
    
    return n * fact(n - 1);
}


// -------------- Classic Backtracking Template -----------------------

void backtrack(...) {

    if (base_case) {
        // save answer
        return;
    }

    for (each choice) {

        // choose
        ...

        // explore
        backtrack(...);

        // undo
        ...
    }
}

// ================ Recusrion + Backtracking ===================

void generateAllSubsets (vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& ans) {

    if (index == nums.size()) {
        ans.push_back(path);
        return;
    }

    // Choose 1: include nums[index]
    path.push_back (nums[index]);

    generateAllSubsets (nums, index + 1, path, ans);

    // Undo
    path.pop_back();

    // Choose 2: don't include nums[index]
    generateAllSubsets (nums, index + 1, path, ans);
}
