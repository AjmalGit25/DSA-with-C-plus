#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

public:
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int idx = -1;

Node* buildTree(vector<int>& arr) {
    idx++;
    
    if (idx == arr.size() || arr[idx] == -1) return nullptr;
    
    Node* root = new Node(arr[idx]);
    
    root->left = buildTree(arr);
    root->right = buildTree(arr);
    
    return root;
}

void levelOrder(Node* root) {
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        cout << curr->data << " ";
        
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

// ------------------- Sum Tree ---------------------
int sumTree(Node* &root) {
    if (!root) return 0;
    
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    
    return root->data = leftSum + rightSum + root->data;
}

// --------------- Standard Sum Tree ----------------
int sumTree(Node* root) {
    if (!root) return 0;

    int oldValue = root->data;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data = leftSum + rightSum;		// 0 + 0 = 0

    return oldValue + leftSum + rightSum;
}

int main () {
	vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
	
	Node* root = buildTree(arr);
	
	cout << "\nLevel Order Traversal (Before): ";
	levelOrder (root);
	
	cout << "\nThe root value: " << sumTree(root);
	
	cout << "\nLevel Order Traversal (After): ";
	levelOrder (root);

	return 0;
}