struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int height(struct TreeNode *root, int level) {
	if (!root) return level;
	int left = height(root->left, level + 1);
	int right = height(root->right, level + 1);
	return (left > right) ? left : right;
}

int maxDepth(struct TreeNode *root) {
	return height(root, 0);
}
