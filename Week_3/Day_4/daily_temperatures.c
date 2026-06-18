#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *ans = calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    int stack[temperaturesSize];
    int sp = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (sp != -1 && temperatures[stack[sp]] < temperatures[i]) {
            int idx = stack[sp--];
            ans[idx] = i - idx;
        }
        stack[++sp] = i;
    }

    return ans;
}
