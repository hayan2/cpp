#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;
const int MAX_N = 10001;
const int MAX_T = 1001;

int root[MAX_T][MAX_N];
int N, T, M, S, E, u, v, w;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T >> M >> S >> E;
	for (int i = 0; i < N; i++) root[0][i] = INF;
	root[0][S] = 0;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < N; j++) root[i + 1][j] = root[i][j];
		for (int j = 0; j < M; j++) {
			cin >> u >> v >> w;
			root[i + 1][v] = min(root[i + 1][v], root[i][u] + w);
			root[i + 1][u] = min(root[i + 1][u], root[i][v] + w);
		}
	}

	(root[T][E] >= INF) ? cout << "-1" : cout << root[T][E];

	return 0;
}