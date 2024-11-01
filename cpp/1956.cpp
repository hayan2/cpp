#define INF 1e9
#define MAX_V 401
#define MAX_E 159602
#include <iostream>
#include <algorithm>

using namespace std;

int cache[MAX_V][MAX_V];
int V, E;

void sol() {
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				cache[i][j] = min(cache[i][j], cache[i][k] + cache[k][j]);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v, w;
	fill_n(cache[0], MAX_V * MAX_V, INF);
	for (int i = 1; i <= V; i++) {
		cache[i][i] = 0;
	}

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		cache[u][v] = min(cache[u][v], w);
	}

	sol();

	int res = INF;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			res = min(res, cache[i][j] + cache[j][i]);
		}
	}

	if (res >= INF) {
		cout << "-1";
	}
	else {
		cout << res;
	}

	return 0;
}