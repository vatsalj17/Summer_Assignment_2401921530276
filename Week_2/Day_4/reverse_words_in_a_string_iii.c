void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *reverseWords(char *s) {
    int count = 0;
	for (int i = 0;; i++) {
        if (s[i] == '\0' || s[i] == ' ') {
            int first = i - count;
            int iterator = 0;
            for (int j = first; j < first + (count / 2); j++) {
                swap(&s[j], &s[i - (iterator++) - 1]);
            }
            count = 0;
            if (s[i] == '\0') break;
        } else {
            count++;
        }
	}
	return s;
}
