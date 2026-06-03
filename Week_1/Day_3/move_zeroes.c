void moveZeroes(int* nums, int numsSize) {
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[idx++] = nums[i];
        }
    }
    while (idx < numsSize) nums[idx++] = 0;
}
