#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool compare(struct TreeNode *left_side, struct TreeNode *right_side) {
	if (!left_side || !right_side) return left_side == right_side;
	if (left_side->val != right_side->val) return false;
	return compare(left_side->right, right_side->left) &&
	       compare(left_side->left, right_side->right);
}

bool isSymmetric(struct TreeNode *root) {
	return !root || compare(root->left, root->right);
}
