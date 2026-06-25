struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int diameter(struct TreeNode *root, int *max) {
	if (!root) return 0;
	int left = diameter(root->left, max);
	int right = diameter(root->right, max);
	int sum = left + right;
	if (sum >= *max) *max = sum;
	return 1 + ((left > right) ? left : right);
}

int diameterOfBinaryTree(struct TreeNode *root) {
	int d = 0;
	diameter(root, &d);
	return d;
}
