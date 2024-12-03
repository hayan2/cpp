#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> hashmap;
vector<int> cache, fnum;

int find(int x) {
	if (cache[x] == x) return x;
	else return cache[x] = find(cache[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) {
		cache[b] = a;
		fnum[a] += fnum[b];
	}
	else if (a > b) {
		cache[a] = b;
		fnum[b] += fnum[a];
	}
}

void initVector(int n) {
	cache.assign(n * 2 + 1, 0);
	fnum.assign(n * 2 + 1, 1);
	for (int i = 1; i <= n * 2; i++) cache[i] = i;	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		hashmap.clear();
		int idx = 0, f = 0;

		cin >> f;
		initVector(f);

		int n1, n2;

		for (int i = 0; i < f; i++) {
			string name1, name2;
			cin >> name1 >> name2;

			if (!hashmap.count(name1)) {
				hashmap[name1] = ++idx;
				n1 = idx;
			}
			else {
				n1 = hashmap[name1];
			}

			if (!hashmap.count(name2)) {
				hashmap[name2] = ++idx;
				n2 = idx;
			}
			else {
				n2 = hashmap[name2];
			}

			unionSet(n1, n2);
			cout << fnum[find(n1)] << "\n";
		}
	}

	return 0;
}