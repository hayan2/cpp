#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;
const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, -1, 1 };

struct State {
	int t, r, c;
	bool operator > (const State& o) const { return t > o.t; }
};

struct TrafficLight {
	char state;
	int ew, ns;
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;

	while ((cin >> m >> n) && (m != 0 || n != 0)) {
		vector<string> cache(m);
		vector<TrafficLight> lights;

		int sr = 0, sc = 0, er = 0, ec = 0;
		int maxTrafficLight = -1;

		for (int i = 0; i < m; i++) {
			cin >> cache[i];

			for (int j = 0; j < n; j++) {
				if (cache[i][j] == 'A') sr = i, sc = j;
				else if (cache[i][j] == 'B') er = i, ec = j;
				else if (isdigit(cache[i][j])) maxTrafficLight = max(maxTrafficLight, cache[i][j] - '0');
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

			for (int i = 0; i < 4; i++) {				
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nr >= m || nc < 0 || nc >= m || cache[nr][nc] == '.') continue;

			}
		}
	}

	return 0;
}