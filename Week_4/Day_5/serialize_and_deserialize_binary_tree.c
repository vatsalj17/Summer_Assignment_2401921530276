#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


// Approach 1 (BFS)

static inline struct TreeNode *tree_node_init(int val) {
	struct TreeNode *new = malloc(sizeof(struct TreeNode));
	new->val = val;
	new->left = new->right = NULL;
	return new;
}

#define MAX 10000

static inline void myitoa(int val, char *ser, size_t *iser) {
	if (val == 0) {
		ser[(*iser)++] = '0';
		ser[(*iser)++] = ',';
		return;
	}
	unsigned int uval;
	if (val < 0) {
		ser[(*iser)++] = '-';
		uval = -val;
	} else {
		uval = val;
	}
	char temp[10] = {0};
	int i = 9;
	while (uval) {
		temp[i--] = (uval % 10) + '0';
		uval /= 10;
	}
	while (i < 9) {
		ser[(*iser)++] = temp[++i];
	}
	ser[(*iser)++] = ',';
}

char *serialize(struct TreeNode *root) {
	if (!root) return NULL;
	size_t cap = MAX;
	char *ser = malloc(cap * sizeof(char));
	size_t iser = 0;
	struct TreeNode *q[MAX];
	int front = 0, rear = 0;
	q[rear++] = root;
	myitoa(root->val, ser, &iser);
	while (front < rear) {
		if (iser + 20 > cap) {
			cap *= 2;
			char *new = realloc(ser, cap * sizeof(char));
			if (!new) abort();
			ser = new;
		}
		struct TreeNode *top = q[front++];
		if (!top->left) {
			ser[iser++] = 'n';
			ser[iser++] = ',';
		} else {
			myitoa(top->left->val, ser, &iser);
			q[rear++] = top->left;
		}
		if (!top->right) {
			ser[iser++] = 'n';
			ser[iser++] = ',';
		} else {
			myitoa(top->right->val, ser, &iser);
			q[rear++] = top->right;
		}
	}
	ser[iser] = '\0';
	return ser;
}

static inline int myatoi(char **data) {
	int sign = 1;
	if (**data == '-') {
		sign = -1;
		(*data)++;
	}
	int val = 0;
	while (**data != ',') {
		val = (val * 10) + (**data - '0');
		(*data)++;
	}
	return val * sign;
}

struct TreeNode *deserialize(char *data) {
	if (!data) return NULL;
	struct TreeNode *root = tree_node_init(myatoi(&data));
	struct TreeNode *q[MAX];
	int front = 0, rear = 0;
	q[rear++] = root;
	while (*data != '\0') {
		if (*data == ',') {
			data++;
			continue;
		} else {
			if (front >= rear) break;
			struct TreeNode *top = q[front++];
			if (!top) continue;
			struct TreeNode *left;
			if (*data == 'n') {
				left = NULL;
				data++;
			} else {
				left = tree_node_init(myatoi(&data));
			}
			if (*data != ',') {
				fprintf(stderr, "not parsed correctly, %c\n", *data);
				abort();
			} else
				data++;
			if (*data == '\0') {
				fprintf(stderr, "can't read right, string ended\n");
				abort();
			}
			struct TreeNode *right;
			if (*data == 'n') {
				right = NULL;
				data++;
			} else {
				right = tree_node_init(myatoi(&data));
			}
			top->left = left;
			top->right = right;
			if (left) q[rear++] = top->left;
			if (right) q[rear++] = top->right;
		}
	}
	return root;
}

// ----------------------------------------------------------------


// Approach 2 (DFS)

#define INTNULL INT_MIN
#define MAX 10000

static void encode(struct TreeNode *node, int *buf, int *i) {
	if (!node) {
		buf[(*i)++] = INTNULL;
		return;
	}
	buf[(*i)++] = node->val;
	encode(node->left, buf, i);
	encode(node->right, buf, i);
}

char *serialize2(struct TreeNode *root) {
	int *buf = malloc((2 * MAX + 1) * sizeof(int));
	int i = 0;
	encode(root, buf, &i);
	return (char *)buf;
}

static struct TreeNode *decode(int **buf) {
	int val = *(*buf)++;
	if (val == INTNULL) return NULL;
	struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = val;
	node->left = decode(buf);
	node->right = decode(buf);
	return node;
}

struct TreeNode *deserialize2(char *data) {
	int *buf = (int *)data;
	return decode(&buf);
}
