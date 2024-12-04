#define MAX_LEN 1001
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int visited[MAX_LEN] = { 0, };
int N, M, cnt = 0;

void solved(vector<int>* cache, int x) {
	visited[x] = VISITED;

	for (auto node : cache[x]) {
		if (!visited[node]) {
			visited[node] = VISITED;
			cnt++;
			solved(cache, node);			
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	while (T--) {
		cin >> N >> M;
		vector<int> cache[MAX_LEN];
		memset(visited, 0, sizeof(visited));

		while (M--) {
			int u, v;
			cin >> u >> v;
			cache[u].push_back(v);
			cache[v].push_back(u);
		}

		solved(cache, 1);
		cout << cnt << "\n";
		cnt = 0;
	}

	return 0;
}