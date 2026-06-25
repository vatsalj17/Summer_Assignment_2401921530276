#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool helper(struct TreeNode *root, int sum, int target) {
	if (!root) return false;
	int newsum = root->val + sum;
	if (newsum == target && !root->left && !root->right) return true;
	return helper(root->left, newsum, target) || helper(root->right, newsum, target);
}

bool hasPathSum(struct TreeNode *root, int targetSum) {
	return helper(root, 0, targetSum);
}
