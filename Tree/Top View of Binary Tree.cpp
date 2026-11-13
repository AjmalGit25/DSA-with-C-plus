void topView (Node* root) {
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    
    map<int, int> mp;
    
    while (!q.empty()) {							// O(n)
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();
        
        if (mp.find(hd) == mp.end())				// O(log n)
            mp[hd] = curr->data;
        
        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }
    
    for (auto it : mp) {
        cout << it.second();
    }
}


/*

Time Complexity: O(n log n)

*/