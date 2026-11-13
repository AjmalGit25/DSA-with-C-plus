
// ============ Time: O(n^2) ====================

int height(TreeNode* root) {
    if (!root) return 0;
    
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    
    return max(leftHt, rightHt) + 1;
}

int diameterOfBinaryTree (TreeNode* root) {
    if (root == nullptr) 
        return 0;
    
    int leftDiam = diameterOfBinaryTree(root->left);
    int rightDiam = diameterOfBinaryTree(root->right);
    
    int currDiam = height(root-left) + height(root->right);
    
    return max (currDiam, max(leftDiam, rightDiam));
}



// ============ Node-based diameter: Time: O(n) ====================

int diam = 0;

int height(TreeNode* root) {
	if (!root) return 0;

	int leftHt = height(root->left);
	int rightHt = height(root->right);
	
	diam = max(diam, leftHt + rightHt);
	return max(leftHt, rightHt) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
	height(root);

	return diam;
}


// ============ Edge-based diameter: Time: O(n) =================

int height(Node* root) {
    if (!root) return -1;
    
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    
    diam = max (diam, leftHt + rightHt + 2);
    return max (leftHt, rightHt) + 1;
}


// ========================= Height & Diameter (Simple) =================================
int height(Node* &root) {
    if (!root) return 0;
    
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    
    return max(leftHt, rightHt) + 1;
}

int diameter(Node* &root) {
    if (!root) return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    
    return leftHt + rightHt;
}


/*

Diameter = Number of edges in the longest path between any two nodes.

Important: The path does NOT necessarily have to pass through the root.


Longest path = Diameter = leftHeight + rightHeight



*/

