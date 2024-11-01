#define MAX_M 100001
#define MAX_N 101
#define INF 1e9
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int res[MAX_N][MAX_N];
int n, m;

void sol() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	fill_n(res[0], MAX_N * MAX_N, INF);
	for (int i = 1; i < MAX_N; i++) {
		res[i][i] = 0;
	}

	int u, v, w;	

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;

		res[u][v] = min(res[u][v], w);
	}

	sol();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (res[i][j] >= INF) {
				cout << "0";
			}
			else {
				cout << res[i][j];
			}
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}