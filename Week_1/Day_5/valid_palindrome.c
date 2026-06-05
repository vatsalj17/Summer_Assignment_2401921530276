#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    char ans[strlen(s) + 1];
    int index = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i]))
            ans[index++] = s[i];
        else if (isalpha(s[i]))
            ans[index++] = tolower(s[i]);
    }
    ans[index] = '\0';
    int beg = 0, end = strlen(ans) - 1;
    while (end > beg) {
        if (ans[beg++] != ans[end--])
            return false;
    }
    return true;
}
