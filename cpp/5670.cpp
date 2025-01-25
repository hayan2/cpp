#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define MAX_LEN 26

using namespace std;

int res, N;

typedef struct Trie {
	Trie* cache[MAX_LEN];
	bool finish;
	int cnt;

	Trie() {
		for (int i = 0; i < MAX_LEN; i++) cache[i] = NULL;
		finish = false;
		cnt = 0;
	}

	~Trie() {
		for (int i = 0; i < MAX_LEN; i++) if (cache[i]) delete cache[i];
	}

	void insert(const char* s) {
		if (!*s) {
			finish = true;
			return;
		}

		int cur = *s - 'a';
		if (!cache[cur]) {
			cache[cur] = new Trie;
			cnt++;
		}
		cache[cur]->insert(s + 1);
	}
	
	void find(const char* s, int k, bool root) {
		if (!*s) {
			res += k;
			return;
		}
		int cur = *s - 'a';
		if (root) cache[cur]->find(s + 1, k, false);
		else {
			if (cnt == 1 && !finish) cache[cur]->find(s + 1, k, false);
			else cache[cur]->find(s + 1, k + 1, false);
		}
	}

}Trie;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	while (cin >> N) {
		Trie* root = new Trie;
		res = 0;
		vector<string> key;
		for (int i = 1; i <= N; i++) {
			string str;
			cin >> str;

			key.push_back(str);
			root->insert(str.c_str());
		}

		for (string x : key) {
			root->find(x.c_str(), 1, true);
		}
		cout << fixed;
		cout.precision(2);
		cout << (double)res / (int)key.size() << "\n";
		delete root;
	}

	return 0;
}