#include <iostream>
#include <algorithm>

#define MAX_LEN 10001
#define VISITED true

using namespace std;

int cache[MAX_LEN];
bool visited[MAX_LEN] = { 0, };
int T, N, A, B, u, v, res = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cache[i] = i;
			visited[i] = !VISITED;
		}

		for (int i = 1; i < N; i++) {
			cin >> A >> B;

			cache[B] = A;
		}

		cin >> u >> v;
		visited[u] = VISITED;

		while (u != cache[u]) {
			u = cache[u];
			visited[u] = VISITED;			
		}

		while (1) {
			if (visited[v]) {
				cout << v << "\n";
				break;
			}
			v = cache[v];
		}
	}

	return 0;
}