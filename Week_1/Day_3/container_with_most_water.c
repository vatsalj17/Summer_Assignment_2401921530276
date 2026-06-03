int maxArea(int *height, int heightSize) {
	int left = 0, right = heightSize - 1;
	int max = 0;

	while (left < right) {
		int minheight = (height[left] < height[right]) ? height[left] : height[right];
		int base = right - left;
		int area = base * minheight;
		if (area > max) max = area;

        if (height[left] > height[right]) right--;
        else left++;
	}

	return max;
}
