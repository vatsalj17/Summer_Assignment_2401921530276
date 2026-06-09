#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool equals(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int *findAnagrams(char *s, char *p, int *returnSize) {
	int sn = strlen(s);
	int pn = strlen(p);
	int *indices = malloc(sn * sizeof(int));
	if (pn > sn) {
		*returnSize = 0;
		return indices;
	}
	int idx = 0;
	int occ[26] = {0};
    int occ2[26] = {0};
	for (int i = 0; i < pn; i++) {
		occ[p[i] - 'a']++;
        occ2[s[i] - 'a']++;
	}
    if (equals(occ, occ2)) 
        indices[idx++] = 0;

	for (int i = pn; i < sn; i++) {
        occ2[s[i - pn] - 'a']--;
        occ2[s[i] - 'a']++;
        if (equals(occ, occ2)) 
            indices[idx++] = i - pn + 1;
	}

	*returnSize = idx;
	return indices;
}
