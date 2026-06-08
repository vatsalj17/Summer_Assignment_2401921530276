int firstUniqChar(char* s) {
    int occ[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        occ[s[i] - 'a']++;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (occ[s[i] - 'a'] == 1) return i;
    }
    return -1;
}
