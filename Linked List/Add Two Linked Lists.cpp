
// ======== For small lists (int, long long) ================

Node* addTwoLists (Node* head1, Node* head2) {
	int n1 = 0, n2 = 0;
	Node* ptr = head1;
	while (ptr != nullptr) {
		n1 = n1 * 10 + ptr->data;
		ptr = ptr->next;
	}

	ptr = head2;
	while (ptr != nullptr) {
		n2 = n2 * 10 + ptr->data;
		ptr = ptr->next;
	}

	long long res = n1 + n2;
	string nums = to_string(res);

	Node* newHead = nullptr;
	Node* tail = nullptr;

	for (long long i = 0; i < nums.length(); i++) {
		Node* newNode = new Node(nums[i] - '0');

		if (newHead == nullptr) {
			newHead = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}


	return newHead;
}

/*

For large linked lists, the standard approach is digit-by-digit addition with carry. 
You never convert the entire list into an integer.

*/


// Add two Lists (Forward-order representation)
ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
	ListNode* dummy = new ListNode(0);
	ListNode* curr = dummy;

	int carry = 0;

	while (l1 != nullptr || l2 != nullptr || carry) {
		int sum = carry;

		if (l1 != nullptr) {
			sum += l1->val;
			l1 = l1->next;
		}

		if (l2 != nullptr) {
			sum += l2->val;
			l2 = l2->next;
		}

		carry = sum / 10;

		curr->next = new ListNode (sum % 10);
		curr = curr->next;
	}

	return dummy->next;
}

// Add two Lists (Reversed-order representation)
Node* reverseList (Node* head) {
	Node* prev = nullptr;
	Node* curr = head;
	Node* next = nullptr;

	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}

	return prev;
}

Node* addTwoLists (Node* head1, Node* head2) {
	Node* dummy = new Node (-1);
	Node* curr = dummy;

	head1 = reverseList (head1);
	head2 = reverseList (head2);

	int carry = 0;

	while (head1 != nullptr || head2 != nullptr || carry) {
		int sum = carry;

		if (head1 != nullptr) {
			sum += head1->data;
			head1 = head1->next;
		}

		if (head2 != nullptr) {
			sum += head2->data;
			head2 = head2->next;
		}

		carry = (sum / 10);

		curr->next = new Node(sum % 10);
		curr = curr->next;
	}

	// Reverse result
	Node* result = reverseList (dummy->next);

	// Remove leading zeros
	while (result != nullptr && result->data == 0 && result->next != nullptr) {
		Node* temp = result;
		result = result->next;
		delete temp;
	}

	return result;
}