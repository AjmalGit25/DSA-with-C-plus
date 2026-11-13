
int count (Node* root) {
	if (!root) return 0;
    
	int leftCount = count (root->left);
	int rightCount = count (root->right);
	
	return leftCount + rightCount + 1;
}



/*


Time Complexity: O(N) 

*/