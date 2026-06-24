#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool check_order(struct TreeNode *root, struct TreeNode **prev) {
	if (!root) return true;
	if (!check_order(root->left, prev)) return false;
	if (*prev && (*prev)->val >= root->val) return false;
	*prev = root;
	return check_order(root->right, prev);
}

bool isValidBST(struct TreeNode *root) {
	struct TreeNode *prev = 0;
	return check_order(root, &prev);
}
