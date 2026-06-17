#include <stdlib.h>
#include <string.h>

int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
	int *ans = malloc(nums1Size * sizeof(int));
	*returnSize = nums1Size;
	int hash[10001] = {0};
	memset(hash, -1, sizeof(hash));
	int stack[nums2Size];
	int sp = -1;

	for (int i = 0; i < nums2Size; i++) {
		while (sp != -1 && stack[sp] < nums2[i]) {
			int element = stack[sp--];
			hash[element] = nums2[i];
		}
		stack[++sp] = nums2[i];
	}
	for (int i = 0; i < nums1Size; i++) {
		ans[i] = hash[nums1[i]];
	}

	return ans;
}
