#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASHTABLE_SIZE 20011
#define BASE 101

typedef struct {
	char **bucket;
	uint8_t key[26];
	uint16_t valcount;
	bool used;
} ht_entry;

bool isequal(uint8_t a[26], uint8_t b[26]) {
	for (int i = 0; i < 26; i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

size_t hash(uint8_t key[26]) {
	size_t res = 0;
	for (int i = 0; i < 26; i++) {
		res = ((res * BASE) + key[i]) % HASHTABLE_SIZE;
	}
	return res;
}

void insert(uint8_t key[26], char *value, int max, ht_entry *hashtable) {
	size_t ind = hash(key);
	ht_entry *entry = &hashtable[ind];
	bool placed = false;
	while (entry->used) {
		if (isequal(key, entry->key)) {
			entry->bucket[entry->valcount++] = value;
			placed = true;
			break;
		}
		entry = &hashtable[(++ind) % HASHTABLE_SIZE];
	}
	if (!placed) {
		memcpy(entry->key, key, 26);
		entry->bucket = malloc(max * sizeof(char *));
		*entry->bucket = value;
		entry->valcount = 1;
		entry->used = true;
	}
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
	ht_entry hashtable[HASHTABLE_SIZE] = {0};

	char ***groups = malloc(strsSize * sizeof(char **));
	int *colssize = malloc(strsSize * sizeof(int));
	uint8_t occ[26] = {0};

	for (int i = 0; i < strsSize; i++) {
		char *s = strs[i];
		for (int j = 0; s[j] != '\0'; j++) {
			occ[s[j] - 'a']++;
		}
		insert(occ, s, strsSize, hashtable);
		memset(occ, 0, 26);
	}

    int count = 0;
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        if (hashtable[i].used) {
            colssize[count] = hashtable[i].valcount;
            groups[count] = hashtable[i].bucket;
            count++;
        }
    }
    *returnSize = count;
	*returnColumnSizes = colssize;

	return groups;
}
