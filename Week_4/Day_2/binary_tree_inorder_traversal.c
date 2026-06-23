#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void inorder(struct TreeNode *root, int *in, int *i) {
	if (root == NULL) {
		return;
	}
	inorder(root->left, in, i);
	in[(*i)++] = root->val;
	inorder(root->right, in, i);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
	int *result = malloc(101 * sizeof(int));
	int i = 0;
	inorder(root, result, &i);
	*returnSize = i;
	return result;
}
