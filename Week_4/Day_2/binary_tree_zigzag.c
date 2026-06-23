#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAX 2000

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
	int **result = malloc(MAX * sizeof(int *));
	if (result == NULL) {
		return NULL;
	}
	*returnSize = 0;
	int *cols = calloc(MAX, sizeof(int));
	if (root == NULL) {
		*returnColumnSizes = cols;
		return result;
	}

	int lvl = 0;
	struct TreeNode **q = calloc(MAX, sizeof(struct TreeNode *));
	int head = 0, tail = 0;
	q[tail++] = root;
	while (head < tail) {
		int num = tail - head;
		result[lvl] = malloc(num * sizeof(int));
		cols[lvl] = num;
		for (int i = 0; i < num; i++) {
			struct TreeNode *current = q[head++];
			if (current->left != NULL) q[tail++] = current->left;
			if (current->right != NULL) q[tail++] = current->right;
			if (lvl & 1)
				result[lvl][num - i - 1] = current->val;
			else
				result[lvl][i] = current->val;
		}
		lvl++;
	}

	free(q);
	*returnSize = lvl;
	*returnColumnSizes = cols;
	return result;
}
