#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define MAX_LEN 26

using namespace std;

typedef struct Trie {
	bool finish;
	Trie* cache[MAX_LEN];
	int cnt;

	Trie() {
		finish = false;
		for (int i = 0; i < MAX_LEN; i++) cache[i] = NULL;
		cnt = 0;
	}
}Trie;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	return 0;
}