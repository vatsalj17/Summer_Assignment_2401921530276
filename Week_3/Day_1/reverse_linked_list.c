struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
	if (head == (struct ListNode *)0 || head->next == (struct ListNode *)0) return head;
	struct ListNode *new;
	struct ListNode *prev = head;
	struct ListNode *curr = prev->next;
	struct ListNode *temp = curr->next;
	prev->next = (struct ListNode *)0;
	while (curr != (struct ListNode *)0) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	new = prev;
	return new;
}
