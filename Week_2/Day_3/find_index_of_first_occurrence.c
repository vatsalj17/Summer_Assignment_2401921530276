#include <stdlib.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
	int hn = strlen(haystack);
	int nn = strlen(needle);

	int *kmp = calloc(nn, sizeof(int));
	int match = 0;
	for (int i = 1; i < nn; i++) {
		if (needle[i] == needle[match]) {
			kmp[i] = ++match;
		} else {
			if (match != 0) {
				match = kmp[match - 1];
				i--;
			} else {
                kmp[i] = 0;
            }
		}
	}

	int j = 0;
	for (int i = 0; i < hn; i++) {
		if (j == nn) return i - j;
		if (haystack[i] == needle[j]) {
			j++;
		} else {
			if (j == 0) continue;
			j = kmp[j - 1];
			i--;
		}
	}
    free(kmp);
	if (j == nn) {
		return hn - nn;
	}

	return -1;
}
