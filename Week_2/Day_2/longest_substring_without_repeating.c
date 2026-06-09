int lengthOfLongestSubstring(char *s) {
	if (s[0] == '\0') return 0;
	int max = 1;
	int occ[128] = {0};
	int fptr = 0, lptr = 1;
	occ[s[0]]++;

	while (s[lptr] != '\0') {
		occ[s[lptr]]++;
		if (occ[s[lptr]] > 1) {
			while (s[fptr] != s[lptr]) {
				occ[s[fptr]]--;
				fptr++;
			}
			if (fptr < lptr) {
				occ[s[fptr]]--;
				fptr++;
			}
		}
		lptr++;
		int new = lptr - fptr;
		if (new > max) max = new;
	}

	return max;
}
