#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> hashmap;
vector<int> sccidx, fnum;

int find(int x) {
	if (sccidx[x] == x) return x;
	else return sccidx[x] = find(sccidx[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) {
		sccidx[b] = a;
		fnum[a] += fnum[b];
	}
	else if (a > b) {
		sccidx[a] = b;
		fnum[b] += fnum[a];
	}
}

void initVector(int n) {
	sccidx.assign(n * 2 + 1, 0);
	fnum.assign(n * 2 + 1, 1);
	for (int i = 1; i <= n * 2; i++) sccidx[i] = i;	
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