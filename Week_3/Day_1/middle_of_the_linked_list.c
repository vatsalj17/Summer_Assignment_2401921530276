struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head) {
	struct ListNode *temp = head;
	struct ListNode *mid = head;
	int count = 0;
	while (temp != (struct ListNode *)0) {
		temp = temp->next;
		if (count & 1) mid = mid->next;
		count++;
	}
	return mid;
}
