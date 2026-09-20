Node* flatten (Node* head) {
	if (head == nullptr)
		return head;

	Node* curr = head;
	while (curr != nullptr) {
		if (curr->child != nullptr) {
			Node* next = curr->next;

			curr->next = flatten (curr->child);
			
			// Connect curr with next pointer
			curr->next->prev = curr;
			curr->child = nullptr;
		
			// find tail
			while (curr->next != nullptr) 
				curr = curr->next;

			// attach tail with next node
			if (next != nullptr) {
				curr->next = next;
				next->prev = curr;
			}
		}
		curr = curr->next;
	}
	return head;
}

// Recursive approach