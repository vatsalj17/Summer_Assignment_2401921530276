int largestRectangleArea(int *heights, int heightsSize) {
	if (heightsSize == 1) return *heights;
	int area = 0;

	int stack[heightsSize];
	int sp = -1;
	for (int i = 0; i <= heightsSize; i++) {
		int ele = (i == heightsSize) ? -1 : heights[i];
		while (sp != -1 && heights[stack[sp]] > ele) {
			int curr = stack[sp--];
			int nse = i;
			int pse = (sp != -1) ? stack[sp] : -1;

			int nextelements = nse - i;
			int prevelements = i - pse;
			int base = nextelements + prevelements - 1;
			int newarea = heights[curr] * base;
			if (newarea > area) area = newarea;
		}
		stack[++sp] = i;
	}

	return area;
}
