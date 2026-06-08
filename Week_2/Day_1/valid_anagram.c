#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int occ[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        occ[s[i] - 'a']++;
    }
    for (int i = 0; t[i] != '\0'; i++) {
        if ((--occ[t[i] - 'a']) < 0) return false;
    }
    for (int i = 0; i < 26; i++) {
        if (occ[i] != 0) return false;
    }
    return true;
}
