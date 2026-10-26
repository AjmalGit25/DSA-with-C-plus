#include <iostream>
#include <queue>
using namespace std;

// --- Level Order Traversal (also known as BFS (Breadth-First Search) traversal) ---

void levelOrder (Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push (root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push (curr->left);
        if (curr->right) q.push (curr->right);
    }
}


// --- Level Order Traversal with NULL push ---
void levelOrder (Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push (root);
    q.push (NULL);
    

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if (curr == NULL) {
            if (!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
                break;
        }

        cout << curr->data << " ";

        if (curr->left) q.push (curr->left);
        if (curr->right) q.push (curr->right);
    }
}


int main () {
    
    
    return 0;
}

/*

Binary Tree:

        10
       /  \
      20   30
     /  \
    40  50

Queue ensures level-by-level construction

Level Order Traversal: 10, 20, 30, 40, 50

*/