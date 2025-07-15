#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int INF = 1e9 + 7;

struct State {
	int t, r, c;
	bool operator > (const State& o) const { return t > o.t; }
};

struct TrafficLight {
	char state;
	int ew, ns;
};

const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, -1, 1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	while (cin >> m >> n && (m != 0 || n != 0)) {
		vector<string> grid(m);
		vector<TrafficLight> lights(10);
		int sr = 0, sc = 0, er = 0, ec = 0;
		int maxId = -1;

		for (int i = 0; i < m; i++) {
			cin >> grid[i];
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 'A') sr = i, sc = j;
				else if (grid[i][j] == 'B') er = i, ec = j;
				else if (isdigit(grid[i][j])) maxId = max(maxId, grid[i][j] - '0');
			}
		}

		if (maxId != -1) {
			for (int i = 0; i <= maxId; i++) {
				int id; char state; int a, b;
				cin >> id >> state >> a >> b;
				lights[id] = { state, a, b };
			}
		}

		vector<vector<int>> dist(m, vector<int>(n, INF));
		priority_queue<State, vector<State>, greater<State>> pq;

		dist[sr][sc] = 0;
		pq.push({ 0, sr, sc });

		while (!pq.empty()) {
			State cur = pq.top();
			pq.pop();

			int t = cur.t;
			int r = cur.r;
			int c = cur.c;

			if (t > dist[r][c]) continue;
			if (r == er && c == ec) break;

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];


				if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == '.') continue;

				int nt;

				if (isdigit(grid[nr][nc])) {
					int li = grid[nr][nc] - '0';
					TrafficLight l = lights[li];
					char dir = (i < 2) ? '|' : '-';

					int mov = t;

					while (true) {
						int cl = l.ew + l.ns;
						int tic = mov % cl;
						char gdir;

						if (l.state == '-') gdir = (tic < l.ew) ? '-' : '|';
						else gdir = (tic < l.ns) ? '|' : '-';

						if (gdir == dir) {
							break;
						}

						mov++;
					}
					nt = mov + 1;

					if (mov > t) nt++;
				}
				else { nt = t + 1; }


				if (nt < dist[nr][nc]) {
					dist[nr][nc] = nt;
					pq.push({ nt, nr, nc });
				}
			}
		}

		if (dist[er][ec] == INF) cout << "impossible" << "\n";
		else cout << dist[er][ec] << "\n";
	}

	return 0;
}