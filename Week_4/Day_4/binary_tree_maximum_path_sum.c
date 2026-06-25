#include <limits.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAX(a, b) ((a > b) ? a : b)

int findpath(struct TreeNode *root, int *max) {
	if (!root) return 0;
	int left = findpath(root->left, max);
	int right = findpath(root->right, max);
	left = MAX(left, 0);
	right = MAX(right, 0);
	int sum = root->val + right + left;
	*max = MAX(*max, sum);
	return root->val + MAX(left, right);
}

int maxPathSum(struct TreeNode *root) {
	int max = INT_MIN;
	findpath(root, &max);
	return max;
}
