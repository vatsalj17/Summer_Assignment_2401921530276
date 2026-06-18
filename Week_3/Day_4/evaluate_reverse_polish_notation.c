#include <ctype.h>
#include <stdlib.h>

_Bool isinteger(char *s) {
	if (isdigit(s[0]))
		return 1;
	else if (s[0] == '-' && isdigit(s[1]))
		return 1;
	return 0;
}

int evalRPN(char **tokens, int tokensSize) {
	int stack[tokensSize];
	int sp = -1;

	for (int i = 0; i < tokensSize; i++) {
		if (isinteger(tokens[i])) {
			int n = atoi(tokens[i]);
			stack[++sp] = n;
		} else {
			char op = tokens[i][0];
			int a = stack[sp--];
			int b = stack[sp--];
			int result = 0;
			switch (op) {
			case '+':
				result = b + a;
				break;
			case '-':
				result = b - a;
				break;
			case '*':
				result = b * a;
				break;
			case '/':
				result = b / a;
				break;
			}
			stack[++sp] = result;
		}
	}

	return stack[0];
}
