#include <iostream>
#include <vector>
#include <climits>
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

Node* buildTree() {
    int val;
    cout << "Enter root values (-1 for null): ";
    cin >> val;
    
    if (val == -1) return nullptr;
    
    Node* newNode = new Node(val);
    
    Node* root = newNode;
    
    root->left = buildTree();
    root->right = buildTree();
    
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int sumOfNodes(Node* root) {
    if (!root) return 0;
    
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    
    return root->data + leftSum + rightSum;
}

int maxNodeVal(Node* root) {
    if (!root) return INT_MIN;
    
    int curr = root->data;
    
    int leftVal = maxNodeVal(root->left);
    int rightVal = maxNodeVal(root->right);
    
    return max (max(leftVal, rightVal), curr);
}

int height(Node* root) {
    if (!root) return 0;
    
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    
    return max(leftHt, rightHt) + 1;
}

void kthLevelNode(Node* root, int k) {
	if (!root || k <= 0) return;

	if (k == 1) {
		cout << root->data << " ";
		return;
	}

	kthLevelNode(root->left, k - 1);
	kthLevelNode(root->right, k - 1);
}

string level(int k) {
    if (k == 1) return "1st";
    if (k == 2) return "2nd";
    if (k == 3) return "3rd";
    
    return to_string(k) + "th";
}


int main() {
	Node* root = buildTree();
	
	cout << "Preorder traversal: ";
	preorder(root);
	
	cout << "\nSum of nodes: ";
	cout << sumOfNodes(root) << endl;
	
	cout << "Height of the tree: ";
	cout << height(root) << endl;
	
	cout << "Maximum node value: ";
	cout << maxNodeVal(root) << endl;
	
	cout << "\nNodes at " << level(k) << " level: ";
	kthLevelNode (root, k);

	return 0;
}

/*

static int idx = -1;

Node* buildTree(vector<int>& tree) {
    ++idx;
    
	if (tree[idx] == -1 || idx >= tree.size()) return nullptr;

	Node* root = new Node(tree[idx]);

	root->left = buildTree(tree);
	root->right = buildTree(tree);

	return root;
}

vector<int> tree = {4, 3, -1, -1, 6, 5, 2, -1, -1, 9, -1, -1, 7, -1, 8, -1, -1};
Node* root = buildTree(tree);

*/