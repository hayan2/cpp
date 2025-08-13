#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	vector<vector<int>> dist(N, vector<int>(N, INF));

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;

		for (int j = 0; j < N; j++) {
			if (!(i ^ j)) dist[i][j] = 0;
			else if (row[j] == 'Y') dist[i][j] = 1;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		int cur = 0;
		for (int j = 0; j < N; j++) {
			if (i ^ j && dist[i][j] <= 2) cur++;
		}
		res = max(res, cur);
	}

	cout << res;

	return 0;
}