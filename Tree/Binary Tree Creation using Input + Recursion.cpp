#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Binary Tree Creation using Input + Recursion

// Tree Node
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

// Recursive function to build tree
Node* buildTree () {
	int val;
	cin >> val;

	// Base case
	if (val == -1) return nullptr;

	// Create current node
	Node* root = new Node (val);

	// Build left subtree
	root->left = buildTree ();

	// Build right subtree
	root->right = buildTree ();

	return root;
}

// Preorder traversal (for verification)
void preorder (Node* root) {
	if (root == nullptr) return;

	cout << root->data << " ";
	preorder (root->left);
	preorder (root->right);
}

// Time Complexity: O(n log n)
void topView (Node* root) {
	queue<pair<Node*, int>> q;

	q.push({root, 0});

	map<int, int> mp;

	while (!q.empty()) {
		Node* curr = q.front().first;
		int hd = q.front().second;
		q.pop();

		if (mp.find(hd) == mp.end())
			mp[hd] = curr->data;

		if (curr->left) q.push({curr->left, hd - 1});
		if (curr->right) q.push({curr->right, hd + 1});
	}

	for (auto it : mp) {
		cout << it.second;
	}
}

void rightView (Node* root) {
	if (!root) return;

	queue<Node*> q;

	q.push(root);

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			Node* curr = q.front();
			q.pop();

			if (i == size - 1)
				cout << curr->data;

			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
		}
	}
}

int main () {
	cout << "Enter tree values (-1 for NULL): ";
	Node* root = buildTree ();

	cout << "\nPreorder Traversal: ";
	preorder (root);

	cout << "\nTop View: ";
	topView (root);
	
	cout << "\nRight View: ";
	rightView (root);

	return 0;
}


/*

Binary Tree:

        10
       /  \
      20   30
     /  \
    40  50

Example input:
10 20 40 -1 -1 50 -1 -1 30 -1 -1

Preorder Traversal: 10, 20, 40, 50, 30

*/