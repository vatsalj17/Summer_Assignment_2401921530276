#include <string.h>

char* longestPalindrome(char* s) {
    char *ans = NULL;
    int len = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > len) {
                len = r - l + 1;
                ans = s + l;
            }
            l--;
            r++;
        }

        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > len) {
                len = r - l + 1;
                ans = s + l;
            }
            l--;
            r++;
        }
    }
    ans[len] = '\0';
    return ans;
}
