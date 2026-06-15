#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (slow != (struct ListNode *)0 && fast != (struct ListNode *)0) {
		fast = fast->next;
		if (fast == (struct ListNode *)0) return false;
		fast = fast->next;
		slow = slow->next;
		if (fast == slow) return true;
	}
	return false;
}
