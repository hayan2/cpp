#define ll long long
#define INF 1e9
#define MAX_V 503
#define MAX_E 6003
#define START 1
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> edges;
ll res[MAX_V];
int V, E;

bool sol() {
	res[START] = 0;

	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < E; j++) {
			int origin = edges[j].first;
			int dest = edges[j].second.first;
			int weight = edges[j].second.second;

			if (res[origin] >= INF) {
				continue;
			}

			if (res[dest] > res[origin] + weight) {
				res[dest] = res[origin] + weight;

				if (i == V) {
					return false;
				}
			}
		}
	}

	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill_n(res, MAX_V, INF);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		edges.push_back({ u, {v, w} });
	}

	bool flag = sol();

	if (flag) {
		for (int i = 2; i <= V; i++) {
			if (res[i] >= INF) {
				cout << "-1" << endl;
			}
			else {
				cout << res[i] << endl;
			}
		}
	}
	else {
		cout << "-1";
	}

	return 0;
}