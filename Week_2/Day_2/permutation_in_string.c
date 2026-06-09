#include <stdbool.h>
#include <string.h>

bool equals(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
	int s2n = strlen(s2);
	int s1n = strlen(s1);
    if (s1n > s2n) return false;
	int occ[26] = {0};
    int occ2[26] = {0};

	for (int i = 0; i < s1n; i++) {
		occ[s1[i] - 'a']++;
        occ2[s2[i] - 'a']++;
	}
    if (equals(occ, occ2)) 
        return true;

	for (int i = s1n; i < s2n; i++) {
        occ2[s2[i - s1n] - 'a']--;
        occ2[s2[i] - 'a']++;
        if (equals(occ, occ2)) 
            return true;
	}

	return false;
}
