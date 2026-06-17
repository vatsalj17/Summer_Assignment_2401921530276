#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
	int n = strlen(s);
	char stack[n];
	int sp = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			stack[++sp] = s[i];
		} else {
			if (sp == -1) return false;
			char top = stack[sp];
			if ((top == '(' && s[i] == ')') || (top == '{' && s[i] == '}') ||
			    (top == '[' && s[i] == ']'))
				sp--;
			else
				return false;
		}
	}
	if (sp < 0) return false;
	return true;
}
