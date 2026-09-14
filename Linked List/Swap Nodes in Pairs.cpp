

ListNode* swapPairs (ListNode* head) {
	if (!head || head->next == nullptr)
		return head;

	ListNode* newHead = head->next;

	ListNode* first = head;
	ListNode* second = head->next;
	ListNode* third = second->next;
	ListNode* prev = nullptr;

	while (first != nullptr && second != nullptr) {
		// Swap current pair
		second->next = first;
		first->next = third;

		// Connect previous pair to current pair
		if (prev != nullptr)
			prev->next = second;

		// Move forward
		prev = first;
		first = third;

		(third) ? second = third->next : second = nullptr;
		prev->next = first;
		(second) ? third = second->next : second = nullptr;
	}

	return newHead;
}