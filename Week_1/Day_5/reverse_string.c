void reverseString(char* s, int sSize) {
    int mid = sSize / 2;
    for (int i = 0; i <= mid; i++) {
        char temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
}
