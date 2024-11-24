#define MAX_LEN 101
#define INF 1e9
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int graph[MAX_LEN][MAX_LEN];
int prevPath[MAX_LEN][MAX_LEN];
int N, M;

void solved() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
					prevPath[i][j] = k;
				}
			}
		}
	}
}

vector<int> getPath(int u, int v) {
	if (!prevPath[u][v]) return { u, v };

	vector<int> path;
	auto l = getPath(u, prevPath[u][v]);
	auto r = getPath(prevPath[u][v], v);

	for (auto x : l) path.push_back(x);
	path.pop_back();
	for (auto x : r) path.push_back(x);

	return path;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int u, v, w;

	// initialize
	fill_n(graph[0], MAX_LEN * MAX_LEN, INF);
	for (int i = 1; i < MAX_LEN; i++) graph[i][i] = 0;

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;

		graph[u][v] = graph[u][v] > w ? w : graph[u][v];
	}

	solved();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] >= INF) {
				cout << "0";
			}
			else {
				cout << graph[i][j];
			}
			cout << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == INF || i == j) {
				cout << "0";
			}
			else {
				auto ret = getPath(i, j);
				cout << ret.size() << " ";
				for (auto x : ret) cout << x << " ";
			}
			cout << endl;
		}		
	}

	return 0;
}