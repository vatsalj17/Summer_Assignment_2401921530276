#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool repeatedSubstringPattern(char *s) {
	int n = strlen(s);
	int *kmp = calloc(n, sizeof(int));
	int match = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[match]) {
			kmp[i] = ++match;
		} else {
			if (match != 0) {
				match = kmp[match - 1];
				i--;
			}
		}
	}

	int final = kmp[n - 1];
    free(kmp);
	int diff = n - final;
	if (final && n % diff == 0) return true;
	return false;
}
