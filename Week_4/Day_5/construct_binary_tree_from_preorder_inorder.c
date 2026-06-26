#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAX 3000

static inline struct TreeNode *tree_node_init(int val) {
	struct TreeNode *new = malloc(sizeof(struct TreeNode));
	new->val = val;
	new->left = new->right = NULL;
	return new;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
	if (!preorderSize || !inorderSize) return NULL;
	struct TreeNode *root = tree_node_init(preorder[0]);
	struct TreeNode *stack[MAX];
	int sp = -1;
	stack[++sp] = root;

	int inidx = 0;
	for (int i = 1; i < preorderSize; i++) {
		struct TreeNode *curr = stack[sp];
		struct TreeNode *newnode = tree_node_init(preorder[i]);

		if (curr->val == inorder[inidx]) {
			while (sp != -1 && stack[sp]->val == inorder[inidx]) {
				curr = stack[sp--];
				inidx++;
			}
			curr->right = newnode;
		} else {
			curr->left = newnode;
		}
		stack[++sp] = newnode;
	}

	return root;
}
