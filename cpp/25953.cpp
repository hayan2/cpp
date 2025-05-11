#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;
const int MAX_N = 10001;
const int MAX_T = 1001;

int cache[MAX_T][MAX_N];
int N, T, M, S, E, u, v, w;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T >> M >> S >> E;
	for (int i = 0; i < N; i++) cache[0][i] = INF;
	cache[0][S] = 0;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < N; j++) cache[i + 1][j] = cache[i][j];
		for (int j = 0; j < M; j++) {
			cin >> u >> v >> w;
			cache[i + 1][v] = min(cache[i + 1][v], cache[i][u] + w);
			cache[i + 1][u] = min(cache[i + 1][u], cache[i][v] + w);
		}
	}

	(cache[T][E] >= INF) ? cout << "-1" : cout << cache[T][E];

	return 0;
}