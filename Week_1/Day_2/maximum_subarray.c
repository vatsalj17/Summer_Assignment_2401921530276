#include <limits.h>

int maxSubArray(int *nums, int numsSize) {
	int sum = 0;
	int maxSum = INT_MIN;
	for (int i = 0; i < numsSize; i++) {
		sum += i;
		maxSum = (sum > maxSum) ? sum : maxSum;
		if (sum < 0) sum = 0;
	}
	return maxSum;
}
