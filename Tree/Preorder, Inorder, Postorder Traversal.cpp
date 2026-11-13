#include <iostream>
using namespace std;

// Tree Node		(List representation)
struct Node {
    Node* left;
    int data;
    Node* right;
    
    // Constructor to initialize a node
    Node (int data) {
        left = nullptr;
        this->data = data;
        right = nullptr;
    }
};

// Preorder traversal
void preorder (Node* root) {
	if (root == nullptr) return;
	
	cout << root->data << " ";          // root
	preorder (root->left);              // left
	preorder (root->right);             // right
}

// Inorder traversal
void inorder (Node* root) {
	if (root == nullptr) return;
	
	inorder (root->left);               // left
	cout << root->data << " ";          // root
	inorder (root->right);              // right
}

// Postorder traversal
void postorder (Node* root) {
	if (root == nullptr) return;
	
	postorder (root->left);             // left
	postorder (root->right);            // right
	cout << root->data << " ";          // root
}

int main () {
    Node* root = nullptr;				// root
    
    // Creating Nodes
    root = new Node (10);
    root->left = new Node (20);
    root->right = new Node (30);
    root->left->left = new Node (40);
    root->left->right = new Node (50);
    
    // Simple traversal to print the tree
    cout << root->data << " ";
    cout << root->left->data << " ";
    cout << root->right->data << " ";
    cout << root->left->left->data << " ";
    cout << root->left->right->data << " ";
    
    // Preorder
    cout << "\nPreorder Traversal: ";
    preorder(root);
    
    // Inorder
    cout << "\nInorder Traversal: ";
    inorder (root);
    
    // Postorder
    cout << "\nPostorder Traversal: ";
    postorder(root);
    

    return 0;
}

/*

Binary Tree:

        10
       /  \
      20   30
     /  \
    40  50

Preorder Traversal: 10, 20, 40, 50, 30
Inorder Traversal: 40, 20, 50, 10, 30
Postorder Traversal: 40, 50, 20, 30, 10

------------------------------------------------
Large trees are created in 3 standard ways:
	1. Using Input + Recursion (Most common in DSA problems)
	2. Using Level Order + Queue (Most practical)
	3. Automatically via Rules (BST, Heap, Trie, etc.)

------------------------------------------------
Time Complexity: All four standard tree traversals take O(N) time.

*/