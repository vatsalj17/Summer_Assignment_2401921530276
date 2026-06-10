#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++) {
        if (s[j] == '\0') return true;
        if (s[j] == t[i]) j++;
    }
    if (s[j] == '\0') return true;
    return false;
}
