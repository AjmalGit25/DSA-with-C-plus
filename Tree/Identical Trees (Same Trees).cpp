#include <iostream>
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
	// Case 1: Both NULL
	if (!p && !q)
		return true;

	// Case 2: One is NULL
	if (!p || !q)
		return false;

	// Case 3: Values different
	if (p->val != q->val)
		return false;

	// Case 4: Check left and right subtree
	return isSameTree(p->left, q->left) &&
	       isSameTree(p->right, q->right);
}

int main() {

	return 0;
}

/*

Identical Trees (Same Trees):

Two trees are identical if their:
    i) Node structure are same
    ii) Corresponding node values are same

*/