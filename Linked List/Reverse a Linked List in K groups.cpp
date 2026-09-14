
// For leetcode
ListNode* reverseKGroup (ListNode* head, int k) {
	if (!head || k == 1)
		return head;

	// Dummy node to handle edge cases easily
	ListNode* dummy = new ListNode(0);
	dummy->next = head;

	ListNode* groupPrev = dummy;

	while (true) {
		// Check if there are at least k nodes remaining
		ListNode* kth = groupPrev;
		
		for (int i = 0; i < k && kth != nullptr; ++i) 
			kth = kth->next;
		
		if (kth == nullptr)
			break;      // Less than k nodes remaining

		ListNode* groupNext = kth->next;

		// Reverse k nodes
		ListNode* prev = groupNext;
		ListNode* curr = groupPrev->next;

		for (int i = 0; i < k; ++i) {
			ListNode* temp = curr->next;
			curr->next = prev;
			
			prev = curr;
			curr = temp;
		}

		// Connect previous part with reversed group
		ListNode* temp = groupPrev->next;
		groupPrev->next = kth;
		groupPrev = temp;
	}

	return dummy->next;
}

/*

Example: 

Input:
3 ? 5 ? 4 ? 7 ? 7 ? 9 ? 8 ? 3 ? 1 ? 8 ? 6
k = 3

Output:
4 ? 5 ? 3 ? 9 ? 7 ? 7 ? 1 ? 3 ? 8 ? 8 ? 6


*/


// For GFG
Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1)
        return head;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* groupPrev = dummy;

    while (groupPrev->next != nullptr) {

        Node* curr = groupPrev->next;
        Node* prev = nullptr;

        int count = 0;

        // Reverse up to k nodes
        while (curr != nullptr && count < k) {
            Node* temp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = temp;

            count++;
        }

        // Connect previous group to reversed group
        Node* groupStart = groupPrev->next;

        groupPrev->next = prev;

        // groupStart is now the last node of this reversed group
        groupPrev = groupStart;
    }

    return dummy->next;
}

/*

Example: 

Input:
3 ? 5 ? 4 ? 7 ? 7 ? 9 ? 8 ? 3 ? 1 ? 8 ? 6
k = 3

Output:
4 ? 5 ? 3 ? 9 ? 7 ? 7 ? 1 ? 3 ? 8 ? 6 ? 8


*/