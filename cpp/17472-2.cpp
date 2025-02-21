#define MAX_LEN 11
#define MAX_ILND 51
#define DIR_LEN 4
#define VISITED 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <stdbool.h>

using namespace std;

typedef pair<int, pair<int, int>> Mst;

int map[MAX_LEN][MAX_LEN];
int root[MAX_ILND];
int visited[MAX_LEN][MAX_LEN];
int dist[MAX_ILND][MAX_ILND];
int dx[DIR_LEN] = { -1, 0, 1, 0 };
int dy[DIR_LEN] = { 0, -1, 0, 1 };
int V, E, islandNum = 0;

int find(int x) {
	if (root[x] == x) return root[x];
	else return root[x] = find(root[x]);
}

void unionSet(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) root[b] = a;
	else root[a] = b;
}

void putIslandNum(int x, int y) {
	queue<pair<int, int>> queue;
	queue.push({ x, y });

	map[x][y] += islandNum;
	visited[x][y] = VISITED;

	while (!queue.empty()) {
		int curX = queue.front().first;
		int curY = queue.front().second;
		queue.pop();

		for (int i = 0; i < DIR_LEN; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 1 || ny < 1 || nx > V || ny > E) continue;

			if (!visited[nx][ny] && map[nx][ny]) {
				map[nx][ny] += islandNum;
				visited[nx][ny] = VISITED;
				queue.push({ nx, ny });
			}
		}
	}

	islandNum++;
}

void downHeight(int x, int y) {
	int distance = 0, curNum = map[x][y];
	x++;

	while (!map[x][y]) {
		if (x < 1 || x > V) return;

		distance++;
		x++;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);

	if (cy <= islandNum && distance > 1 && (cx != cy) && x < MAX_LEN) {
		dist[cx][cy] = min(distance, dist[cx][cy]);
	}
}

void goWidth(int x, int y) {
	int distance = 0, curNum = map[x][y];
	y++;

	while (!map[x][y]) {
		if (y < 1 || y > E) return;

		distance++;
		y++;
	}

	int cx = min(curNum, map[x][y]);
	int cy = max(curNum, map[x][y]);
	if (cy <= islandNum && distance > 1 && (cx != cy) && y < MAX_LEN) {
		dist[cx][cy] = min(distance, dist[cx][cy]);
	}
}

int isConnected() {
	int tmp = find(root[1]);
	for (int i = 2; i <= islandNum; i++) {
		if (tmp != find(root[i])) return 0;
	}

	return 1;
}

int solved(vector<Mst> cache) {
	int ret = 0, cnt = 0;

	for (Mst cur : cache) {
		int u = cur.second.first;
		int v = cur.second.second;
		int w = cur.first;

		if (find(u) == find(v)) continue;
		if (cnt == islandNum - 1) break;

		cnt++;
		ret += w;
		unionSet(u, v);
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Mst> cache;

	for (int i = 1; i < MAX_ILND; i++) root[i] = i;
	cin >> V >> E;

	memset(visited, 0, sizeof(visited));
	memset(map, 0, sizeof(map));
	fill_n(&dist[0][0], MAX_ILND * MAX_ILND, MAX_LEN);

	for (int x = 1; x <= V; x++) {
		for (int y = 1; y <= E; y++) {
			cin >> map[x][y];
		}
	}

	for (int x = 1; x <= V; x++) {
		for (int y = 1; y <= E; y++) {
			if (!visited[x][y] && map[x][y]) {
				putIslandNum(x, y);
			}
		}
	}
	
	for (int x = 1; x <= V; x++) {
		for (int y = 1; y <= E; y++) {
			if (map[x][y]) {
				goWidth(x, y);
				downHeight(x, y);
			}
		}
	}
	
	int lim = (V > E) ? V : E;
	for (int x = 1; x <= lim; x++) {
		for (int y = 1; y <= lim; y++) {
			if (dist[x][y] > 1 && dist[x][y] < MAX_LEN) {
				cache.push_back({ dist[x][y], { x, y } });
			}
		}
	}

	sort(cache.begin(), cache.end());

	int res = solved(cache);
	if (isConnected()) {
		(res > 0) ? cout << res : cout << "-1";
	}
	else {
		cout << "-1";
	}

	return 0;
}