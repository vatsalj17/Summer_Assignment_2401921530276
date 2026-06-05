#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 1) return strs[0];

    char* ans = calloc(201, sizeof(char));
    strcpy(ans, strs[0]);

    int min = INT_MAX;
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (ans[j] != '\0' && ans[j] == strs[i][j]) {
            j++;
        }
        if (j < min) {
            min = j;
        }
    }
    assert(min != INT_MAX);

    ans[min] = '\0';
    return ans;
}
