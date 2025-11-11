#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using state = pair<int, pii>;

const int INF = 1e9 + 7;
const int MAX_N = 126;

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

int rupee[MAX_N][MAX_N];

int solve(int N) {
	priority_queue<state, vector<state>, greater<state>> pq;
	vector<vector<int>> dist(N, vector<int>(N, INF));

	pq.push({ rupee[0][0], { 0, 0 } });
	dist[0][0] = rupee[0][0];

	while (!pq.empty()) {
		state cur = pq.top();
		pq.pop();

		int cost = cur.first;
		int r = cur.second.first;
		int c = cur.second.second;

		if (cost > dist[r][c]) continue;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			int newCost = cost + rupee[nr][nc];
			if (dist[nr][nc] <= newCost) continue;

			dist[nr][nc] = newCost;
			pq.push({ newCost, { nr, nc } });
		}
	}

	return dist[N - 1][N - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, idx = 1;
		
	while (cin >> N, N != 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> rupee[i][j];				
			}
		}
		
		cout << "Problem " << idx++ << ": " << solve(N) << "\n";
 	}

	return 0;
}