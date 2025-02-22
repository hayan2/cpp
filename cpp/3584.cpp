#include <iostream>
#include <algorithm>

#define MAX_LEN 10001
#define VISITED true

using namespace std;

int sccidx[MAX_LEN];
bool visited[MAX_LEN] = { 0, };
int T, V, A, B, u, v, res = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> V;

		for (int i = 1; i <= V; i++) {
			sccidx[i] = i;
			visited[i] = !VISITED;
		}

		for (int i = 1; i < V; i++) {
			cin >> A >> B;

			sccidx[B] = A;
		}

		cin >> u >> v;
		visited[u] = VISITED;

		while (u != sccidx[u]) {
			u = sccidx[u];
			visited[u] = VISITED;			
		}

		while (1) {
			if (visited[v]) {
				cout << v << "\n";
				break;
			}
			v = sccidx[v];
		}
	}

	return 0;
}