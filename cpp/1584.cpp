#include <iostream>
#include <algorithm>
#include <deque>
#include <string.h>

using namespace std;
using pii = pair<int, int>;

const int MAX_SIZE = 501;
const int DEST = 500;
const int INF = 1e9;

deque<pii> dq;
int grid[MAX_SIZE][MAX_SIZE] = { 0, };
int dist[MAX_SIZE][MAX_SIZE];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int solve() {
	int N, M, x1, y1, x2, y2;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		int r1 = min(x1, x2);
		int r2 = max(x1, x2);
		int c1 = min(y1, y2);
		int c2 = max(y1, y2);

		for (int r = r1; r <= r2; r++) {
			for (int c = c1; c <= c2; c++) {
				grid[r][c] = 1;
			}
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		int r1 = min(x1, x2);
		int r2 = max(x1, x2);
		int c1 = min(y1, y2);
		int c2 = max(y1, y2);

		for (int r = r1; r <= r2; r++) {
			for (int c = c1; c <= c2; c++) {
				grid[r][c] = 2;
			}
		}
	}

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			dist[i][j] = INF;
		}
	}

	dist[0][0] = 0;
	dq.push_front({ 0, 0 });

	while (!dq.empty()) {
		pii cur = dq.front();
		dq.pop_front();

		int r = cur.first;
		int c = cur.second;

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr < 0 || nr > 500 || nc < 0 || nc > 500) continue;
			if (grid[nr][nc] == 2) continue;

			int cost = grid[nr][nc];
			int nxtCost = dist[r][c] + cost;

			if (dist[nr][nc] > nxtCost) {
				dist[nr][nc] = nxtCost;
				if (!grid[nr][nc]) dq.push_front({ nr, nc });
				else dq.push_back({ nr, nc });
			}
		}
	}
	//
	return ((dist[DEST][DEST] == INF) ? -1 : dist[DEST][DEST]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cout << solve();

	return 0;
}