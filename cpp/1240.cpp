#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

const int MAX_N = 1001;

int N, M, u, v, w;
vector<pii> cache[MAX_N];

int solve(int s, int e) {
	queue<pii> q;
	vector<bool> visited(N + 1, false);

	q.push({ s, 0 });
	visited[s] = true;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		int v = cur.first;
		int w = cur.second;

		if (v == e) return w;

		for (pii nxt : cache[v]) {
			if (!visited[nxt.first]) {
				visited[nxt.first] = true;
				q.push({ nxt.first, nxt.second + w });
			}			
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> N >> M;
	

	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;

		cache[u].push_back({ v, w });
		cache[v].push_back({ u, w });
	}

	int s, e;
	while (M--) {
		cin >> s >> e;

		cout << solve(s, e) << "\n";
	}

	return 0;
}