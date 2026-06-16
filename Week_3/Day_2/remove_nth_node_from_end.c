struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *removeNthFromEnd_cleaner(struct ListNode *head, int n) {
	struct ListNode dummy = {0, head};
	struct ListNode *temp = &dummy;
	struct ListNode *to_delete = &dummy;
	for (int i = 0; i <= n; i++)
		temp = temp->next;

	while (temp) {
		temp = temp->next;
		to_delete = to_delete->next;
	}

	to_delete->next = to_delete->next->next;
	return dummy.next;
}
