#include <stdlib.h>

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize) {
	*returnSize = numsSize - k + 1;
	int *ans = malloc((*returnSize) * sizeof(int));
	int idx = 0;
	int dequeue[k];
	int front = 0, rear = 0;

	for (int i = 0; i < numsSize; i++) {
		if (front < rear && dequeue[front % k] <= i - k) {
			front++;
		}
		while (front < rear && nums[dequeue[(rear - 1) % k]] <= nums[i]) {
			rear--;
		}
		dequeue[(rear++) % k] = i;
		if (i >= k - 1) {
			ans[idx++] = nums[dequeue[front % k]];
		}
	}
	return ans;
}
