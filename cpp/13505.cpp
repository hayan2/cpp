#include <iostream>
#include <algorithm>

using namespace std;

const int DIGITS = 31;
const int MAX_SIZE = 100001;
const bool FINISHED = true;

int N, root[MAX_SIZE];

struct Trie {
	Trie* node[2];

	bool finished = !FINISHED;

	Trie() {
		for (int i = 0; i < 2; i++) node[i] = NULL;
		finished = false;
	}

	~Trie() {
		for (int i = 0; i < 2; i++) if (node[i]) delete node[i];
	}

	void add(int key, int digit) {
		if (digit < 0) {
			finished = FINISHED;
			return;
		}

		int nxt = key & (1 << digit);

		if (nxt) nxt = 1;
		if (node[nxt] == NULL) node[nxt] = new Trie;
				
		node[nxt]->add(key & ~(1 << digit), digit - 1);
	}

	int solved(int key, int digit) {
		if (digit < 0) return 0;

		int nxt = key & (1 << digit);

		if (nxt) nxt = 1;
		nxt = (nxt + 1) % 2;

		int ret = 0;

		if (node[nxt] == NULL) nxt = (nxt + 1) % 2;
		else ret = 1 << digit;

		return ret + node[nxt]->solved(key & ~(1 << digit), digit - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Trie* T = new Trie;

	for (int i = 0; i < N; i++) {
		cin >> root[i];
		T->add(root[i], DIGITS);
	}

	int ret = 0;
	for (int i = 0; i < N; i++) ret = max(ret, T->solved(root[i], DIGITS));

	cout << ret;

	return 0;
}