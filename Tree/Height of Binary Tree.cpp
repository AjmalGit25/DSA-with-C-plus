
//  ============= Edge-based height ====================

int height (Node* root) {
	if (!root) return -1;
    
	int leftHt = height (root->left);
	int rightHt = height (root->right);
	
	return max (leftHt, rightHt) + 1;
}


//  ============= Node-based height ====================

int height (Node* root) {
	if (!root) return 0;
    
	int leftHt = height (root->left);
	int rightHt = height (root->right);
	
	return max (leftHt, rightHt) + 1;
}

/*

The recursive formula is identical in both functions:	return max (leftHt, rightHt) + 1;

*/
