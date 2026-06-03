#include <stdlib.h>

int *sortedSquares(int *nums, int numsSize, int *returnSize) {
	*returnSize = numsSize;
	int *ans = malloc(numsSize * sizeof(int));
	int posptr = -1;
	int negptr = -1;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] >= 0) {
			posptr = i;
			negptr = i - 1;
			break;
		}
	}

	int idx = 0;
	if (posptr == -1) {
		for (int i = numsSize - 1; i >= 0; i--) {
			ans[idx++] = nums[i] * nums[i];
		}
	} else if (negptr == -1) {
		for (int i = 0; i < numsSize; i++) {
			ans[idx++] = nums[i] * nums[i];
		}
	} else {
		while (negptr >= 0 && posptr < numsSize) {
			if ((-nums[negptr]) > nums[posptr]) {
				ans[idx++] = nums[posptr] * nums[posptr];
				posptr++;
			} else {
				ans[idx++] = nums[negptr] * nums[negptr];
				negptr--;
			}
		}
		while (negptr >= 0) {
			ans[idx++] = nums[negptr] * nums[negptr];
			negptr--;
		}
		while (posptr < numsSize) {
			ans[idx++] = nums[posptr] * nums[posptr];
			posptr++;
		}
	}

	return ans;
}
