
int sumOfNodes (Node* root) {
	if (!root) return 0;
    
    int sum = 0;
    
    sum += root->data;
    
	int leftSum = sumOfNodes (root->left);
	int rightSum = sumOfNodes (root->right);
	
	return leftSum + rightSum + sum;
}

/*


Time Complexity: O(N) 

*/