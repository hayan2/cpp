#define MAX_LEN 501
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> tree[MAX_LEN];
int V, E;
int visited[MAX_LEN];
bool ok = 1;

void solved(int cur, int cnt) {
	visited[cur] = cnt;

	for (auto nxt : tree[cur]) {
		if (!visited[nxt]) solved(nxt, cnt + 1);
		else if (visited[cur] - visited[nxt] > 1) ok = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 1;

	while (1) {
		cin >> V >> E;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i <= V; i++) tree[i].clear();
		if (!V) break;

		while (E--) {
			int u, v;
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		int res = 0;
		for (int i = 1; i <= V; i++) {
			if (!visited[i]) {
				ok = 1;
				solved(i, 0);
				res += ok;
			}
		}

		cout << "Case " << cnt++ << ": ";
		if (res == 0) cout << "No trees.";
		else if (res == 1) cout << "There is one tree.";
		else cout << "A forest of " << res << " trees.";
		cout << "\n";
	}

	return 0;
}