
// =========== Left Rotate : O(n) Time, O(1) Space =================
ListNode* rotateLeft (ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr)
        return head;

    // Find length and tail
    int n = 1;
    ListNode* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
        n++;
    }

    // Avoid unnecessary rotations
    k %= n;

    if (k == 0)
        return head;

    // Make circular
    tail->next = head;

    // Find new tail
    ListNode* newTail = head;

    for (int i = 1; i < k; i++) 
        newTail = newTail->next;

    // New head is after new tail
    ListNode* newHead = newTail->next;

    // Break circle
    newTail->next = nullptr;

    return newHead;
}

/*

Left Rotate


Right Rotate
	Only modify for loop: i < n - k

*/