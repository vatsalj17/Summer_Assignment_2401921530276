#include <stdlib.h>
#include <stdbool.h>

bool containsDuplicate(int *nums, int numsSize) {
	int min = nums[0];
	int max = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] < min) min = nums[i];
		if (nums[i] > max) max = nums[i];
	}
	int size = max - min + 1;

	bool *hash = calloc(size, sizeof(bool));

	for (int i = 0; i < numsSize; i++) {
		int idx = nums[i] - min;
		if (hash[idx] == true) {
			free(hash);
			return true;
		}
		hash[idx] = true;
	}

	free(hash);
	return false;
}
