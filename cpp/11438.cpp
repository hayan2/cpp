#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_LEN 100001
#define MAX_LOG 18
#define ROOT 1

using namespace std;

vector<int> tree[MAX_LEN];
int cache[MAX_LEN][MAX_LOG] = { 0, };
int depth[MAX_LEN] = { 0, };
int N, M, u, v;

void getDepth(int cur, int curDepth, int parent) {
	depth[cur] = curDepth;

	for (auto nxt : tree[cur]) {
		if (nxt != parent) {
			cache[nxt][0] = cur;
			getDepth(nxt, curDepth + 1, cur);
		}
	}
}

void getParent() {	
	for (int i = 1; i < MAX_LOG; i++) {
		for (int j = 1; j <= N; j++) {
			cache[j][i] = cache[cache[j][i - 1]][i - 1];
		}
	}
}

int solved(int a, int b) {
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	for (int i = MAX_LOG - 1; i > -1; i--) {
		if (depth[a] - depth[b] >= (1 << i)) {
			a = cache[a][i];
		}
	}

	if (a == b) return a;

	for (int i = MAX_LOG - 1; i > -1; i--) {
		if (cache[a][i] != cache[b][i]) {
			a = cache[a][i];
			b = cache[b][i];
		}
	}

	return cache[a][0];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	getDepth(ROOT, 1, 0);
	getParent();

	cin >> M;
	
	while (M--) {
		int a, b;

		cin >> a >> b;

		cout << solved(a, b) << "\n";
	}
	
	return 0;
}