#include <stdlib.h>
#include <string.h>

void helper(int open_brackets, int closed_brackets, char **ans, int *index, char *string, int i, int n) {
    if (open_brackets > n || closed_brackets > n) return;
    if (closed_brackets > open_brackets) return;
    if (i == n * 2) {
        ans[(*index)++] = strdup(string);
        return;
    }
    string[i] = '(';
    helper(open_brackets + 1, closed_brackets, ans, index, string, i + 1, n);
    string[i] = ')';
    helper(open_brackets, closed_brackets + 1, ans, index, string, i + 1, n);
}

char **generateParenthesis(int n, int *returnSize) {
	if (n == 0) return 0;
	int size = 1 << (n * 2);
	char **ans = malloc(size * sizeof(char *));
	int index = 0;
    char *string = calloc((2 * n) + 1, sizeof(char));
    helper(0, 0, ans, &index, string, 0, n);
    free(string);
	*returnSize = index;
	return ans;
}
