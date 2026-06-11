#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

typedef struct String_Stack {
	char **strs;
	ssize_t sp;
	size_t capacity;
} sstack_t;

sstack_t *sstack_init() {
	sstack_t *stack = malloc(sizeof(sstack_t));
	if (!stack) abort();
	stack->sp = -1;
	stack->capacity = 10;
	stack->strs = malloc(stack->capacity * sizeof(char *));
	if (!stack->strs) abort();
	return stack;
}

sstack_t *sstack_init_with_capicity(size_t capacity) {
	sstack_t *stack = malloc(sizeof(sstack_t));
	if (!stack) abort();
	stack->sp = -1;
	stack->capacity = capacity;
	stack->strs = malloc(stack->capacity * sizeof(char *));
	if (!stack->strs) abort();
	return stack;
}

static void sstack_realloc(sstack_t *stack) {
	if (!stack) return;
	size_t new_size = 2 * stack->capacity;
	char **new_stack = realloc(stack->strs, new_size * sizeof(char *));
	if (!new_stack) abort();
	stack->capacity = new_size;
	stack->strs = new_stack;
}

static bool is_empty(sstack_t *stack) {
	return stack->sp < 0;
}

static bool is_full(sstack_t *stack) {
	return stack->sp >= (ssize_t)stack->capacity - 1;
}

size_t sstack_size(sstack_t *stack) {
	if (!stack) return 0;
	return stack->sp + 1;
}

void push_string(sstack_t *stack, const char *string) {
	if (!stack) return;
	if (is_full(stack)) sstack_realloc(stack);
	stack->strs[++stack->sp] = strdup(string);
}

char *pop_string(sstack_t *stack) {
	if (!stack || is_empty(stack)) return NULL;
	return stack->strs[stack->sp--];
}

char *peek_string(sstack_t *stack) {
	if (!stack || is_empty(stack)) return NULL;
	return stack->strs[stack->sp];
}

void destroy_sstack(sstack_t *stack) {
	if (!stack) return;
	for (ssize_t i = 0; i <= stack->sp; i++)
		free(stack->strs[i]);
	free(stack->strs);
	free(stack);
}

#define STACK_EMPTY INT_MIN

typedef struct Stack {
	int *values;
	int top;
	size_t capacity;
} istack_t;

istack_t *stack_init(size_t capacity) {
	istack_t *stack = malloc(sizeof(istack_t));
	if (stack == NULL) {
		return NULL;
	}
	stack->capacity = capacity;
	stack->top = -1;
	stack->values = malloc(capacity * sizeof(int));
	if (stack->values == NULL) {
		free(stack);
		return NULL;
	}
	return stack;
}

bool stack_full(istack_t *stack) {
	return (size_t)stack->top >= stack->capacity - 1;
}

bool stack_empty(istack_t *stack) {
	return stack->top == -1;
}

void stack_push(istack_t *stack, int value) {
	if (stack == NULL) return;
	if (stack_full(stack)) {
		size_t new_capacity = stack->capacity * 2;
		int *temp = realloc(stack->values, new_capacity * sizeof(int));
		if (temp == NULL) abort();
		stack->capacity = new_capacity;
		stack->values = temp;
	}
	stack->top++;
	stack->values[stack->top] = value;
}

int stack_pop(istack_t *stack) {
	if (stack == NULL || stack_empty(stack)) return STACK_EMPTY;
	return stack->values[stack->top--];
}

int stack_top(istack_t *stack) {
	if (stack_empty(stack)) return STACK_EMPTY;
	return stack->values[stack->top];
}

void stack_destroy(istack_t *stack) {
	if (stack == NULL) return;
	free(stack->values);
	free(stack);
}

char *decodeString(char *s) {
	sstack_t *strings = sstack_init();
	istack_t *counts = stack_init(10);
	int cap = 100001;
	char *curr = malloc(cap);
	int icurr = 0;
	int times = 0;
	curr[0] = '\0';
	char *temp = malloc(cap);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isalpha((unsigned char)s[i])) {
			curr[icurr++] = s[i];
		} else if (isdigit((unsigned char)s[i])) {
			times = 0;
			while (isdigit((unsigned char)s[i]))
				times = times * 10 + (s[i++] - '0');
			i--;
		} else if (s[i] == '[') {
			curr[icurr] = '\0';
			push_string(strings, curr);
			stack_push(counts, times);
			icurr = 0;
			times = 0;
		} else {
			int count = stack_pop(counts);
			char *prefix = pop_string(strings);
			int plen = (int)strlen(prefix);
			int len = icurr;
			memcpy(temp, curr, len);
			memcpy(curr, prefix, plen);
			free(prefix);
			icurr = plen;
			for (int j = 0; j < count; j++, icurr += len)
				memcpy(curr + icurr, temp, len);
			curr[icurr] = '\0';
		}
	}

	curr[icurr] = '\0';
	free(temp);
	stack_destroy(counts);
	destroy_sstack(strings);
	return curr;
}
