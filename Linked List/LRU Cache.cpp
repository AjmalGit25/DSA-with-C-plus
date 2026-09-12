class LRUCache {
public:
	class Node {
	public:
		int key, val;
		Node* next;
		Node* prev;

		Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
	};


	Node* head = new Node(-1, -1);
	Node* tail = new Node(-1, -1);

	unordered_map<int, Node*> mp;

	void addNode(Node* newNode) {
		Node* oldNext = head->next;

		head->next = newNode;
		oldNext->prev = newNode;

		newNode->next = oldNext;
		newNode->prev = head;
	}

	void delNode (Node* oldNode) {
		Node* oldPrev = oldNode->prev;
		Node* oldNext = oldNode->next;

		oldPrev->next = oldNext;
		oldNext->prev = oldPrev;
	}

	int limit;
	LRUCache(int capacity) {
		limit = capacity;
		head->next = tail;
		tail->next = head;
	}

	int get(int key) {
		if (mp.find(key) == mp.end())
			return -1;

		Node* ansNode = mp[key];
		int ans = ansNode->val;

		mp.erase(key);
		delNode(ansNode);

		addNode(ansNode);
		mp[key] = ansNode;
		return ans;
	}

	void put(int key, int val) {
		if (mp.find(key) != mp.end()) {
			Node* oldNode = mp[key];
			delNode(oldNode);
			mp.erase(key);
		}

		if (mp.size() == limit) {
			mp.erase(tail->prev->key);
			delNode(tail->prev);
		}

		Node* newNode = new Node(key, val);
		addNode(newNode);
		mp[key] = newNode;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */