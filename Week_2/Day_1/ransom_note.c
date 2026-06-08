#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int occ[26] = {0};
    for (int i = 0; magazine[i] != '\0'; i++) {
        occ[magazine[i] - 'a']++;
    }
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        occ[ransomNote[i] - 'a']--;
        if (occ[ransomNote[i] - 'a'] < 0) return false;
    }
    return true;
}
