TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    
    if (root->val == p->val || root->val == q->val) return root;
    
    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
    
    if (leftLCA && rightLCA) 
        return root;

    else if (!leftLCA) 
        return leftLCA;
        
    else
        return rightLCA;
}

/*

Lowest Common Ancestor (LCA) is the lowest (deepest) node in a tree that is an ancestor of two given nodes.

LCA exists in both Binary Trees and Binary Search Trees (BSTs).

Consider this tree:

          1
         / \
        2   3
       / \   \
      4   5   6
         / \
        7   8

Example 1: LCA(4, 5)
Answer: 2
Node 2 is an ancestor of both 4 and 5, and it's the lowest such node.

Example 2: LCA(4, 6)
Answer: 1
Node 1 is the first common ancestor of 4 and 6.

Example 3: LCA(7, 8)
Answer: 5
Both nodes are descendants of node 5.


*/